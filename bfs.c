/*
 * bfs.c
 *
 *  Created on: 13 Kas 2017
 *      Author: tayyizaman
 */

#include <stdio.h>
#include "USS.h"

int BFSforMT(MyTree my_tree, Data d)
{
	if(isEmptyMyTree(my_tree))
		return 0;

	printf("\nBFS: Aranıyor.\n\nDugum : %8s, Data : %4d\n", "Root", (int) my_tree->root->data);

	if (my_tree->root->data == d)
		return 1;

	Queue q = createQueue();

	do
	{
		for(int i = 0; i < MAX_NODES; i++)
		{
			if(my_tree->iter->subNodes[i] != NULL)
			{
				enqueue(q, (Data) (my_tree->iter->subNodes[i]));
				printf("Dugum : %8x, Data : %4d\n", *((unsigned int *)&(my_tree->iter->subNodes[i])), (int) my_tree->iter->subNodes[i]->data);

				if (my_tree->iter->subNodes[i]->data == d)
				{
					my_tree->iter = my_tree->root;
					clearQueue(q);
					return 1;
				}
			}
		}
	}while(dequeue(q, (pData) &(my_tree->iter)));

	my_tree->iter = my_tree->root;
	clearQueue(q);
	return 0;
}

