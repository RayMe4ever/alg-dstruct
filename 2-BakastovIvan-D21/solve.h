#pragma once
#pragma warning (disable:6011)
#pragma warning (disable:6031)
#pragma warning (disable:4996)

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TEST_VERTEX_NUMBER 3000

void graph_from_file(FILE* filik, int* v_num, int*** g);
char __check(int ve, int* checkbox, int* solvepath, int j, int v_num, int** g, char checkbox_f);
void solve(int v_num, int** g, int** solvepath);
void stress_test(int* v_num, int*** g);
void print_ans(FILE* filik, int v_num, int* solvepath);