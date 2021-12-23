#include "headerc.h"
#include <Windows.h>


#pragma warning (disable:4996)
#pragma warning (disable:6031)
#pragma warning (disable:26451)
#pragma warning (disable:6386)
#pragma warning (disable:4244)

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%i ", arr[i]);
	}
}

queue_t* QCreate(int value)
{
	queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
	if (!queue)
	{
		fprintf(stderr, "Memory error\n");
		return NULL;
	}
	queue->first = (Node_t*)malloc(sizeof(Node_t));
	if (!queue->first)
	{
		fprintf(stderr, "Memory error\n");
		return NULL;
	}
	queue->first->field = value;
	queue->first->next = NULL;
	queue->last = queue->first;
	return queue;
}

void AddInQ(queue_t* queue, int field)
{
	if (!queue->last)
	{
		QCreate(field);
		return;
	}
	queue->last->next = (Node_t*)malloc(sizeof(Node_t));
	if (!queue->last->next)
	{
		fprintf(stderr, "Memory error\n");
		return;
	}
	queue->last = queue->last->next;
	queue->last->field = field;
	queue->last->next = NULL;
}

void DeleteOutQ(queue_t* queue)
{
	if (queue)
	{
		Node_t* temp;
		temp = queue->first;
		queue->first = queue->first->next;
		free(temp);
	}
}

graph_t GCreate()
{
	FILE* file = fopen("test.txt", "r"); 
	//FILE* file = stdin; Для тестов из стдин
	graph_t graph;
	graph_t error = { 0,NULL };
	fscanf(file, "%i", &graph.size);
	int numEdge = 0.5 * graph.size * (graph.size - 1);
	graph.edge = malloc(numEdge * sizeof(edge_t));
	if (!graph.edge)
	{
		fprintf(stderr, "Memory error\n");
		return error;
	}
	int i = 0;
	while ((fscanf(file, "%i %i", &graph.edge[i].out, &graph.edge[i].in) != EOF) && (i != numEdge))
	{
		i++;
	}	
	graph.edge[i].out = 0;
	graph.edge[i].in = 0;
	fclose(file);
	return graph;
}

void ShirtArray(edge_t edge[], int number)
{
	int i = number;
	while ((edge[i].out != 0) || (edge[i].in != 0))
	{
		edge[i] = edge[i + 1];
		i++;
	}
}

int FoundNextVert(graph_t graph, int top)
{
	int i = 0;
	int nextVert = graph.size, count;
	while ((graph.edge[i].out != 0) || (graph.edge[i].in != 0))
	{
		if (graph.edge[i].out == top)
		{
			if (graph.edge[i].in < nextVert)
			{
				nextVert = graph.edge[i].in;
				count = i;
			}
		}
		if (graph.edge[i].in == top)
		{
			if (graph.edge[i].out < nextVert)
			{
				nextVert = graph.edge[i].out;
				count = i;
			}
		}
		i++;
	}
	if (nextVert != graph.size)
	{
		ShirtArray(graph.edge, count);
		return nextVert;
	}
	return 0;
}

int IsInQ(queue_t* queue, int value)
{
	Node_t* savemem = queue->first;
	while (savemem != NULL)
	{
		if (savemem->field == value)
		{
			return 1;
		}
		savemem = savemem->next;
	}
	return 0;
}

int IsInA(int* arr, int size, int value)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return 1;
		}
	}
	return 0;
}

void QDestroy(queue_t* queue)
{
	Node_t* delete = NULL;
	while (queue->first != NULL) {
		delete = queue->first;
		queue->first = queue->first->next;
		free(delete);
	}
}
void G_BFS()
{
	graph_t graph = GCreate();
	queue_t* queue = QCreate(0);
	if (!queue)
	{
		return;
	}
	int* BFS = (int*)malloc(graph.size * sizeof(int));
	if (!BFS)
	{
		fprintf(stderr, "Memory error\n");
		return;
	}
	int i = 0;
	int countBFS = 0;
	while (countBFS < graph.size)
	{
		if (queue->first == NULL)
			break;
		int savemem = queue->first->field;
		int vert = FoundNextVert(graph, savemem);
		while (vert != 0)
		{
			if ((IsInQ(queue, vert) == 0) && (IsInA(BFS, countBFS + 1, vert) == 0))
			{
				AddInQ(queue, vert);
			}
			vert = FoundNextVert(graph, savemem);
		}
		DeleteOutQ(queue);
		BFS[countBFS] = savemem;
		countBFS++;
	}
	QDestroy(queue);
	Print(BFS, countBFS);
	free(BFS);
	//free(graph.edge);
}

int Random(int left, int right)
{
	int k;
	double data;
	k = rand();
	data = ((double)k) / (RAND_MAX + 1);
	data = data * (right - left) + left;
	return (int)data;
}

void StressTest()
{

	LARGE_INTEGER tstart, tend, counter;
	double time_counter;

	int numVert = 550;

	int numEdge = numVert * (numVert)* 0.5;

	FILE* file = fopen("test.txt", "w");
	fprintf(file, "%i\n", numVert);

	for (int i = 0; i < numEdge; i++)
	{
		fprintf(file, "%i %i\n", Random(0, numVert), Random(0, numVert));
	}

	fclose(file);

	QueryPerformanceFrequency(&counter);
	QueryPerformanceCounter(&tstart);

	G_BFS();

	QueryPerformanceCounter(&tend);
	time_counter = (double)((double)(tend.QuadPart - tstart.QuadPart) / (double)counter.QuadPart);

	printf("%lf", time_counter);
}
