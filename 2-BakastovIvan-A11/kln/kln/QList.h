#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#pragma warning (disable:6011)
#define MAX_ITERATIONS_AMOUNT 10000
#define CHANGE_ITERATION_STEP 100
#define COMPARING_FILE_NAME "Comparing.csv"



typedef struct Node {
	int data;
	struct Node* next;
} Node;
typedef struct {
	Node* first;
	Node* last;
}Queue;

void Init(Queue* Q);
int Full(Queue* Q);
void Add(Queue* Q, int value);
int Pop(Queue* Q, int* div);