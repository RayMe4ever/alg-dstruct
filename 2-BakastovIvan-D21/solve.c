
#include "solve.h"
#include <stdlib.h>


char __check(int ve, int* checkbox, int* solvepath, int j, int v_num, int** g, char checkbox_f) {
	checkbox[ve] = TRUE;
	solvepath[j] = ve;

	if (j + 1 == v_num)
		return TRUE;

	for (int i = 0; i < v_num; i++) {
		if (g[ve][i] && !checkbox[i]) {
			j++;
			checkbox_f = __check(i, checkbox, solvepath, j, v_num, g, checkbox_f);
		}

		if (checkbox_f == FALSE) {
			if (i == v_num - 1) {
				j--;
				checkbox[ve] = FALSE;
				return FALSE;
			}

		}
		else
			return TRUE;
	}

	return FALSE;
}

void solve(int v_num, int** g, int** solvepath) {
	char checkbox_f = FALSE;
	int j = 0;
	char f = FALSE;
	int vertex_count = 0;
	int* checkbox = (int*)calloc(v_num, sizeof(int));
	*solvepath = (int*)calloc(v_num, sizeof(int));
	while (vertex_count < v_num && f == FALSE) {
		if (__check(vertex_count, checkbox, *solvepath, j, v_num, g, checkbox_f)) {
			f = TRUE;
			break;
		}
		else
			for (int i = 0; i < v_num; i++)
				checkbox[i] = 0;

		j = 0;
		vertex_count++;
	}
	free(checkbox);
	if (!f)
	{
		free(*solvepath);
		*solvepath = NULL;
	}
}


void graph_from_file(FILE* filik, int* v_num, int*** g) {
	fscanf(filik, "%d", v_num);
	int u = 0, v = 0;

	*g = (int**)calloc(*v_num, sizeof(int*));


	for (int i = 0; i < *v_num; i++)
		(*g)[i] = (int*)calloc(*v_num, sizeof(int));

	while (fscanf(filik, "%d %d", &u, &v) == 2)
		if (filik == stdin && u == 0)
			break;
		else
			(*g)[u - 1][v - 1] = (*g)[v - 1][u - 1] = TRUE;
}

void stress_test(int* v_num, int*** g) {
	*v_num = TEST_VERTEX_NUMBER;

	*g = (int**)calloc(*v_num, sizeof(int*));

	for (int i = 0; i < *v_num; i++)
		(*g)[i] = (int*)calloc(*v_num, sizeof(int));

	for (int i = 0; i < TEST_VERTEX_NUMBER; i++)
		for (int j = i + 1; j < TEST_VERTEX_NUMBER; j++)
			if (rand() % 4 <= 3)
				(*g)[i][j] = (*g)[j][i] = 1;
}

void print_ans(FILE* filik, int v_num, int* solvepath) {
	if (solvepath != NULL && v_num != 0)
		for (int i = 0; i < v_num; i++)
			fprintf(filik, "%d ", solvepath[i] + 1);
	else
		fprintf(filik, "%d", 0);
}