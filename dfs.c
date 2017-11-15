/*
 * dfs.c
 *
 *  Created on: 14 Kas 2017
 *      Author: tayyizaman
 */

#include <stdio.h>
#include "USS.h"

int DFSforMT(MyTree my_tree, Data d)
{
	if(isEmptyMyTree(my_tree))
		return 0;

	printf("\nDFS: Araniyor.\n\n");

	if (searchForDFS(my_tree->root, d))
		return 1;

	return 0;
}

int searchForDFS(Node node, Data d)
{
	if(node == NULL)
		return 0;

	for(int i = 0; i < MAX_NODES; i++)
		if(searchForDFS(node->subNodes[i], d))
			return 1;

	printf("Dugum : %8x, Data : %4d\n", *((unsigned int *)&node), (int) node->data);

	if(node->data == d)
		return 1;

	return 0;
}

