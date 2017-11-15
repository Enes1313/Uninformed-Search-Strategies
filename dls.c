/*
 * dls.c
 *
 *  Created on: 15 Kas 2017
 *      Author: tayyizaman
 */

#include <stdio.h>
#include "USS.h"

int DLSforMT(MyTree my_tree, Data d, int l)
{
	if(isEmptyMyTree(my_tree))
		return 0;

	printf("\nDLS: Araniyor.\n\n");

	if (searchForDLS(my_tree->root, d, l))
		return 1;

	return 0;
}

int searchForDLS(Node node, Data d, int l)
{
	if(l > 0)
	{
		if(node == NULL)
			return 0;

		for(int i = 0; i < MAX_NODES; i++)
			if(searchForDLS(node->subNodes[i], d, l - 1))
				return 1;

		printf("Dugum : %x, Data : %4d\n", *((unsigned int *)&node), (int) node->data);

		if(node->data == d)
			return 1;
	}

	return 0;
}
