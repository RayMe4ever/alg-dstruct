#include<stdio.h>
#include<stdlib.h>

#include "QList.h"
#pragma warning (disable:6011)




void Init(Queue* Q) {

	Q->first = NULL;
	Q->last = Q->first;
}
int Full(Queue* Q) {
	if ((Q->first==NULL))
	{
		return 0;
	}
	else return 1;
}
void Add(Queue *Q,int value) {
	if (Q->first == NULL) 
	{
		Q->last = Q->first = malloc(sizeof(Node));
		Q->first->next = NULL;
	}
	else 
	{ 
		Q->last->next = malloc(sizeof(Node));
		Q->last = Q->last->next;
		Q->last->next = NULL;
	}

	Q->last->data = value;
}
int Pop(Queue *Q,int *div) {
	if (Q->first==NULL)
		return 0;
	Node* delnode = Q->first;
	*div= Q->first->data;
	Q->first = Q->first->next;
	free(delnode);
	return 1;
}