#pragma once
typedef struct BinNode {
	int data;
	struct BinNode* left;
	struct BinNode* right;
} BinNode;
#define LEFT 1
#define RIGHT 0
typedef BinNode* BinTree;
void InsertBin(BinTree* tree, int dt);
int SearchBIn(BinTree tree, int dt);
void RemoveSub(BinNode* node);
void RemoveFromKey(BinTree* tree, int dt);
void PrintBin(BinNode* node, int n);
