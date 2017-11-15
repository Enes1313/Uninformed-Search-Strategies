/*
 * ucs.c
 *
 *  Created on: 14 Kas 2017
 *      Author: tayyizaman
 */

#include <stdio.h>
#include "USS.h"

int UCSforMT(MyTree my_tree, Data d)
{
	if(isEmptyMyTree(my_tree))
		return 0;

	printf("\nUCS: Araniyor.\n\nDugum : %8s, Data : %4d, Cost :    0\n", "Root", (int) my_tree->root->data);

	if (my_tree->root->data == d)
		return 1;

	LinkedList ll = createLinkedList();

	DONGU:

	for(int i = 0; i < MAX_NODES; i++)
	{
		if(my_tree->iter->subNodes[i] != NULL)
		{
			my_tree->iter->subNodes[i]->cost += my_tree->iter->cost;
			insert(ll, (Data) (my_tree->iter->subNodes[i]));
		}
	}

	if(get(ll, (pData) &(my_tree->iter)))
	{
		printf("Dugum : %8x, Data : %4d, Cost : %4d\n", *((unsigned int *)&(my_tree->iter)), my_tree->iter->data, my_tree->iter->cost);

		if (my_tree->iter->data == d)
		{
			my_tree->iter = my_tree->root;
			clearLinkedList(ll);
			return 1;
		}
		goto DONGU;
	}

	my_tree->iter = my_tree->root;
	clearLinkedList(ll);
	return 0;
}
