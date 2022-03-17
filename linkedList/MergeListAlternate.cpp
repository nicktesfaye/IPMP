#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<'\n';
}

void mergeList(struct Node **head1, struct Node **head2);

// Driver program to test above functions
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin>>n1;
        while(n1--){
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>n2;
        while(n2--){
            cin>>tmp;
            push(&b, tmp);
        }
        mergeList(&a, &b);
        printList(a);
        printList(b);
    }
	return 0;
}
// } Driver Code Ends


/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};
*/
// complete this function
void mergeList(struct Node **p, struct Node **q)
{   
    Node *first=*p;
    Node *second=*q;
    Node*temp1=first->next;
    Node*temp2=second->next;
    while(first && second){
        
        first->next=second;
        second->next=temp1;
        
        first=temp1;
        second=temp2;
        if(first) temp1=first->next;
        if(second)temp2=second->next;
    }
    *q=second;
}
