#pragma warning (disable:4996)
#pragma warning (disable:6031)


#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"


int main() {
	char input;
	int data;

	BinNode* tree = NULL;

	while (scanf("%c", &input) >= 1) {
		if (input != 'p' && input != 'q')
			scanf("%i", &data);
		switch (input) {
		case 'a':
			InsertBin(&tree, data);
			break;
		case 'r':
			RemoveFromKey(&tree, data);
			break;
		case 'f':
			if (SearchBIn(tree, data))
				puts("Look at this, this is leaf that you looking for");
			else
				puts("Oooh no, sadness, your leaf isn't exist");
			break;
		case 'p':
			PrintBin(tree,0);
			break;
		case 'q':
			return 0;
			break;
		}
	}

	return 0;
}
