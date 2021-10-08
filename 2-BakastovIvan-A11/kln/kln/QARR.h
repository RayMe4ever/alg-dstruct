#pragma once

#define N  10

typedef struct {
	int data[N];
	int last;
}QueueARR;

void CreateARR(QueueARR* Q);

int AddARR(QueueARR* Q,int k);


int DeleteARR(QueueARR* Q);

int TopARR(QueueARR* Q);

int PopARR(QueueARR* Q);
