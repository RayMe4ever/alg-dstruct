#include "solve.h"

#include <gtest/gtest.h>

extern "C" {
#include <string.h>
}

#define TEST_CHECK_LINE 10

TEST(simple, example_test) {
	int v = 0, ** g = NULL, j = 0, *solvepath= NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "3\n"\
		"2 3\n"\
		"1 3\n"\
		"1 2\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g,&solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "1 2 3 ") == 0);
}

TEST(border, 0_vert_with_no_val) {
	int v = 0, ** g = NULL, j = 0, * solvepath = NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "0\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g, &solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "0") == 0);
}


TEST(usage, 1_vert_with_no_val) {
	int v = 0, ** g = NULL, j = 0, * solvepath = NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "1\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g, &solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "1 ") == 0);
}


TEST(usages, 2_vert_with_no_val) {
	int v = 0, ** g = NULL, j = 0, * solvepath = NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "2\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g, &solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "0") == 0);
}

TEST(usages, 2_vert_with_val) {
	int v = 0, ** g = NULL, j = 0, * solvepath = NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "2\n"
		"1 2\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g, &solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "1 2 ") == 0);
}



TEST(usages, 3_vert_with_no_val) {
	int v = 0, ** g = NULL, j = 0, * solvepath = NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "3\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g, &solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "0") == 0);
}

TEST(usages, 3_vert_with_1_val) {
	int v = 0, ** g = NULL, j = 0, * solvepath = NULL;
	char fajok = FALSE, checkbox_f = '2';
	FILE* filik = fopen("input.txt", "w");

	fprintf(filik, "3\n"
		"1 2\n");

	fclose(filik);
	filik = fopen("input.txt", "r");

	graph_from_file(filik, &v, &g);
	solve(v, g, &solvepath);

	fclose(filik);

	filik = fopen("output.txt", "w");
	print_ans(filik, v, solvepath);

	fclose(filik);

	filik = fopen("output.txt", "r");

	char line[TEST_CHECK_LINE] = { 0 };
	fgets(line, TEST_CHECK_LINE, filik);

	EXPECT_TRUE(strcmp(line, "0") == 0);
}

