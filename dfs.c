int DFSforST(SmTree *smTree, int x)
{
	rootKontrolDFS = smTree;  	/* Normalde gereksiz, sadece ekrana root basabilmek için. */
	
	if(smTree == NULL)
	{
		puts("Agac bos!");
		return -1;
	}
	
	printf("\nDFS: Araniyor.\n\n");
	
	if (searchForDFS(smTree, x) == 1)
		return 1;
		
	return -1;
}

int searchForDFS(SmTree *smTree, int x)
{
	int i;
	if(smTree == NULL)
		return -1;
	
	for(i = 0; i < MAX_NODES; i++)
		if(searchForDFS(smTree->subNodes[i], x) == 1)
			return 1;
	
	if(smTree != rootKontrolDFS)
		printf("Dugum : %x, Data : %4d\n", *((unsigned int *)&smTree), smTree->data);
	else
		printf("Dugum : Root  , Data : %4d (root)\n", smTree->data);
		
	if(smTree->data == x)
		return 1;
		
	return -1;
}

