#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int field;
	struct Node* next;
} Node_t;

typedef struct Queue
{
	struct Node* first, * last;
} queue_t;

typedef struct Edge
{
	int out;
	int in;
} edge_t;

typedef struct Graph
{
	int size;
	edge_t* edge;
} graph_t;



queue_t* QCreate(int value);
void QDestroy(queue_t* queue);
void AddInQ(queue_t* queue, int field);
void DeleteOutQ(queue_t* queue);
graph_t GCreate();
void G_BFS();
void StressTest();
int IsInQ(queue_t* queue, int value);
int IsInA(int* arr, int size, int value);