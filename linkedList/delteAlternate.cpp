/* deletes alternate nodes of a list starting with head */
void deleteAlt(Node *head)
{
	if (head == NULL)
		return;

	Node *node = head->next;

	if (node == NULL)
		return;

	/* Change the next link of head */
	head->next = node->next;

	/* free memory allocated for node */
	free(node);

	/* Recursively call for the new next of head */
	deleteAlt(head->next);
}

// This code is contributed by rathbhupendra
