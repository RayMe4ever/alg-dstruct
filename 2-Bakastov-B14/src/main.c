#pragma warning(disable : 4996)
#include "memallocator.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX_ALLOCATING_SIZE 10000
#define MAX_ITERATIONS 100
                                   
double mallocTest(int size) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double fTime;
    QueryPerformanceFrequency(&frequency);
        void* arr[MAX_ITERATIONS] = { NULL };
    int last_i = 0;
    QueryPerformanceCounter(&start);
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            if (rand() % 3 != 0) {
                arr[i] = malloc(size);
                last_i = i;
            }
            else if (arr[last_i] != NULL) {
                free(arr[last_i]);
                arr[last_i] = NULL;
            }
        }
        QueryPerformanceCounter(&end);
        fTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            free(arr[i]);
        }
    return fTime;

}

double memallocTest(int size) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double fTime;
    QueryPerformanceFrequency(&frequency);
        void* arr[MAX_ITERATIONS] = { NULL };
    int last_i = 0;
    QueryPerformanceCounter(&start);
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            if (rand() % 3 != 0) {
                arr[i] = memalloc(size);
                last_i = i;
            }
            else if (arr[last_i] != NULL) {
                memfree(arr[last_i]);
                arr[last_i] = NULL;
            }
        }
        QueryPerformanceCounter(&end);
        fTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            memfree(arr[i]);
        }
    return fTime;
}

int main(void) {
    double timemal;
    double timememal;
    FILE* filik;
    if ((filik = fopen("cmp.csv", "w")) == NULL)
        printf("The file 'cmp' was not opened\n");
    int memorySize = MAX_ITERATIONS * (MAX_ALLOCATING_SIZE + memgetblocksize());
    void* ptr = malloc(memorySize);
    if (ptr == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    int init = meminit(ptr, memorySize);
    if (init) {
        printf("Error initialize allocating system\n");
        return 1;
    }
    if (filik) {
        fprintf(filik, "malloc;memalloc\n");
        for (int i = 10; i < MAX_ALLOCATING_SIZE; i += 10) {
            timemal = mallocTest(i);
            timememal = memallocTest(i);
            fprintf(filik, "%lf;%lf\n", timemal, timememal);
        }
        fclose(filik);
    }
    memdone();
    free(ptr);
    return 0;
}