/* C program to arrange consonants and
vowels nodes in a linked list */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* A linked list node */
struct Node
{
	char data;
	struct Node *next;
};

/* Function to add new node to the List */
struct Node *newNode(char key)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// utility function to print linked list
void printlist(struct Node *head)
{
	if (! head)
	{
		printf("Empty list \n");
		return;
	}
	while (head != NULL)
	{
		printf("%c",head->data);
		if (head->next)
		printf("->");
		head = head->next;
	}
	printf("\n");
}

// utility function for checking vowel
bool isVowel(char x)
{
	return (x == 'a' || x == 'e' || x == 'i' ||
			x == 'o' || x == 'u');
}

/* function to arrange consonants and
vowels nodes */
struct Node *arrange(struct Node *head)
{
	struct Node *newHead = head;

	// for keep track of vowel
struct	 Node *latestVowel;

	struct Node *curr = head;

	// list is empty
	if (head == NULL)
		return NULL;

	// We need to discover the first vowel
	// in the list. It is going to be the
	// returned head, and also the initial
	// latestVowel.
	if (isVowel(head->data))

		// first element is a vowel. It will
		// also be the new head and the initial
		// latestVowel;
		latestVowel = head;

	else
	{

		// First element is not a vowel. Iterate
		// through the list until we find a vowel.
		// Note that curr points to the element
		// *before* the element with the vowel.
		while (curr->next != NULL &&
			!isVowel(curr->next->data))
			curr = curr->next;


		// This is an edge case where there are
		// only consonants in the list.
		if (curr->next == NULL)
			return head;

		// Set the initial latestVowel and the
		// new head to the vowel item that we found.
		// Relink the chain of consonants after
		// that vowel item:
		// old_head_consonant->consonant1->consonant2->
		// vowel->rest_of_list becomes
		// vowel->old_head_consonant->consonant1->
		// consonant2->rest_of_list
		latestVowel = newHead = curr->next;
		curr->next = curr->next->next;
		latestVowel->next = head;
	}

	// Now traverse the list. Curr is always the item
	// *before* the one we are checking, so that we
	// can use it to re-link.
	while (curr != NULL && curr->next != NULL)
	{
		if (isVowel(curr->next->data))
		{
			// The next discovered item is a vowel
			if (curr == latestVowel)
			{
				// If it comes directly after the
				// previous vowel, we don't need to
				// move items around, just mark the
				// new latestVowel and advance curr.
				latestVowel = curr = curr->next;
			}
			else
			{

				// But if it comes after an intervening
				// chain of consonants, we need to chain
				// the newly discovered vowel right after
				// the old vowel. Curr is not changed as
				// after the re-linking it will have a
				// new next, that has not been checked yet,
				// and we always keep curr at one before
				// the next to check.
				struct Node *temp = latestVowel->next;

				// Chain in new vowel
				latestVowel->next = curr->next;

				// Advance latestVowel
				latestVowel = latestVowel->next;

				// Remove found vowel from previous place
				curr->next = curr->next->next;

				// Re-link chain of consonants after latestVowel
				latestVowel->next = temp;
			}
		}
		else
		{

			// No vowel in the next element, advance curr.
			curr = curr->next;
		}
	}
	return newHead;
}

// Driver code
int main()
{
	struct Node *head = newNode('a');
	head->next = newNode('b');
	head->next->next = newNode('c');
	head->next->next->next = newNode('e');
	head->next->next->next->next = newNode('d');
	head->next->next->next->next->next = newNode('o');
	head->next->next->next->next->next->next = newNode('x');
	head->next->next->next->next->next->next->next = newNode('i');

	printf("Linked list before :\n");
	printlist(head);

	head = arrange(head);

	printf("Linked list after :\n");
	printlist(head);

	return 0;
}
