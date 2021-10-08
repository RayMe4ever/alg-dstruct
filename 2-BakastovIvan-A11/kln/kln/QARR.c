#include <stdio.h>
#include "QARR.h"
#pragma warning (disable:6031)
#pragma warning (disable:4996)


void CreateARR(QueueARR* Q) {
	Q->last = 0;
}

int AddARR(QueueARR* Q,int k) 
{
	if (Q->last == N)
	{
		return 0;
	}
	Q->data[Q->last++] = k;
	return 1;
}

int DeleteARR(QueueARR* Q)
{
	if (Q->last==0)
	{
		return 0;
	}
	for (int i = 0; i < Q->last-1 && i < N-1; i++)
		Q->data[i] = Q->data[i + 1]; Q->last--;
	return 1;
}
int TopARR(QueueARR* Q)
{
	if (Q->last==0)
		return -1;
	else
		return Q->data[0];
}

int PopARR(QueueARR* Q) {
	int buf;
	buf = TopARR(Q);
	DeleteARR(Q);
	return buf;
}