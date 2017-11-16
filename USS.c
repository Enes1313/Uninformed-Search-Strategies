/*
 ============================================================================
 Name        : USS.c
 Author      : Enes AYDIN
 Version     :
 Copyright   : Copyright dediğin nedir ki gülüm?
 Description : Uninformed Search Strategies / C99
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "USS.h"

int main(void)
{
	Data d = 10;
	MyTree my_tree;

	setlocale(LC_ALL, "turkish");

	my_tree = initMyTree(4);

	if(BFSforMT(my_tree, d))
		printf("\n\nBFS: Aranan Deger (%d) Var!\n\n", (int) d);
	else
		printf("\n\nBFS: Aranan Deger (%d) Yok!\n\n", (int) d);

	if(UCSforMT(my_tree, d))
		printf("\n\nUCS: Aranan Deger (%d) Var!\n\n", (int) d);
	else
		printf("\n\nUCS: Aranan Deger (%d) Yok!\n\n", (int) d);

	if(DFSforMT(my_tree, d))
		printf("\n\nDFS: Aranan Deger (%d) Var!\n\n", (int) d);
	else
		printf("\n\nDFS: Aranan Deger (%d) Yok!\n\n", (int) d);

	if(DLSforMT(my_tree, d, 3))
		printf("\n\nDLS: Aranan Deger (%d) Var!\n\n", (int) d);
	else
		printf("\n\nDLS: Aranan Deger (%d) Yok!\n\n", (int) d);

	clearMyTree(my_tree);

	return EXIT_SUCCESS;
}

MyTree initMyTree(int max_level)
{
	MyTree my_tree = (MyTree) malloc(sizeof(struct my_tree));
	my_tree->root = (Node) malloc(sizeof(struct node));

	srand(time(NULL));

	my_tree->iter = my_tree->root;
	my_tree->root->cost = (Data) 0;
	my_tree->root->data = (Data) rand() % 100; // Degistirilebilir.

	// Rootun leveli 1 olarak ele alınmaktadır.
	printf("************************** Agaç yapımız **************************\n");
	printf("* Level:  1, Kendisi %8s, Dgm: %8x, Data: %4d, Cost:    0 *\n", "Root", *((unsigned int *)&(my_tree->root)), (int) my_tree->root->data);

	setNodes(my_tree->root, max_level, 2); // Doldurma işlemi soldan sağa doğrudur.

	printf("******************************************************************\n");

	return my_tree;
}

void clearMyTree(MyTree my_tree)
{
	if(my_tree == NULL)
		return;
	printf("************************* Agaç siliniyor *************************\n");
	clearNodes(my_tree->root);
	printf("******************************************************************\n");
	free(my_tree);
}

int isEmptyMyTree(MyTree my_tree)
{
	if(my_tree == NULL)
	{
		puts("Agaç yok!");
		return 1;
	}

	if(my_tree->root == NULL)
	{
		puts("Agaç boş!");
		return 1;
	}
	return 0;
}

void clearNodes(Node node)
{
	if(node == NULL)
		return;

	printf("* Dgm: %8x, Data: %4d, Cost: %4d *\n", *((unsigned int *)&node), (int) node->data, (int) node->cost);

	clearNodes(node->subNodes[0]);
	clearNodes(node->subNodes[1]);
	clearNodes(node->subNodes[2]);
	clearNodes(node->subNodes[3]);

	free(node);
}

void setNodes(Node node, int level, int step)
{
	if (level >= step)
	{
		for (int i = 0; i < MAX_NODES; i++)
		{
			if (rand() % 2 == 0)
			{
				node->subNodes[i] = (Node) malloc(sizeof(struct node));
				node->subNodes[i]->data = (Data) rand() % 100;
				node->subNodes[i]->cost = (Data) (rand() % 21) * 10 + 100; // 100 ile 300 arası

				printf("* Level: %2d, UstDgm: %8x, Dgm: %8x, Data: %4d, Cost: %4d *\n", step, *((unsigned int *)&node),
				*((unsigned int *)&node->subNodes[i]), (int) node->subNodes[i]->data, (int) node->subNodes[i]->cost);

				setNodes(node->subNodes[i], level, step + 1);
			}
			else
				node->subNodes[i] = NULL;
		}
	}
	else
		for (int j = 0; j < MAX_NODES; j++)
			node->subNodes[j] = NULL;
}
