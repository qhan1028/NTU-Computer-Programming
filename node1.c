#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *getNode (struct node *head, unsigned int i)
{
	struct node * temp;
	temp = head;
	int count = 0, j;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	if (i >= count) return (NULL);
	temp = head;
	for (j = 0 ; j < count-i-1 ; j++) {
		temp = temp -> next;
	}
	return (temp);
}