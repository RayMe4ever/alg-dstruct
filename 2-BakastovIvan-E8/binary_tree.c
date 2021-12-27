#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"


void InsertBin(BinTree* tree, int dt) {

	BinNode* new_node = (BinNode*)malloc(sizeof(BinNode));
	if (new_node == NULL)
		return;

	new_node->data = dt;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*tree == NULL) {
		*tree = new_node;
		return;
	}

	BinNode* node = *tree;
		
	while (node != NULL) {
		if (new_node->data == node->data) {
			free(new_node);
			return;
		}
		else if (new_node->data < node->data) {
			if (node->left == NULL) {
				node->left = new_node;
				return;
			}
			else {
				node = node->left;
			}
		}
		else {
			if (node->right == NULL) {
				node->right = new_node;
				return;
			}
			else {
				node = node->right;
			}
		}
	}
}


int SearchBIn(BinTree tree, int dt) {
	BinNode* node = tree;

	while (node != NULL) {
		if (dt < node->data) {
			node = node->left;
		}
		else if (dt == node->data) {
			return 1;
		}
		else {
			node = node->right;
		}
	}
	return 0;
}

void RemoveSub(BinNode* node) {
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL) {
		free(node);
		return;
	}
	RemoveSub(node->left);
	RemoveSub(node->right);
}


void RemoveFromKey(BinTree* tree, int dt) {
	BinNode* node = *tree;
	BinNode* prev_node = node;
	int flajok = LEFT;

	while (node != NULL) {
		if (dt == node->data) {
			if (node == *tree) {
				RemoveSub(node);
				*tree = NULL;
				return;
			}

			if (flajok)
				prev_node->left = NULL;
			else
				prev_node->right = NULL;

			RemoveSub(node);
			return;
		}
		else if (dt < node->data) {
			prev_node = node;
			flajok = LEFT;
			node = node->left;
		}
		else {
			prev_node = node;
			flajok = RIGHT;
			node = node->right;
		}
	}
}

void PrintBin(BinNode* node, int n) {
	if (node != NULL) {
		PrintBin(node->right, n + 1);
		for (int i = 0; i < n; i++) {
			putchar('\t');
		}
		printf("{%d}", node->data);
		printf("\n");
		PrintBin(node->left, n + 1);
	}
}


