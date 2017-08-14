int DLSforST(SmTree *smTree, int x, int l)
{
	rootKontrolDLS = smTree;
	
	if(smTree == NULL)
	{
		puts("Agac bos!");
		return -1;
	}
	
	printf("\nDLS: Araniyor.\n\n");
	
	if (searchForDLS(smTree, x, l) == 1)
		return 1;
	
	return -1;
}

int searchForDLS(SmTree *smTree, int x, int l)
{
	int i;
	
	if(l > 0)
	{
		if(smTree == NULL)
			return -1;
		
		for(i = 0; i < MAX_NODES; i++)
			if(searchForDLS(smTree->subNodes[i], x, l - 1) == 1)
				return 1;
		
		if(smTree != rootKontrolDLS)
			printf("Dugum : %x, Data : %4d\n", *((unsigned int *)&smTree), smTree->data);
		else
			printf("Dugum : Root  , Data : %4d (root)\n", smTree->data);
		
		if(smTree->data == x)
			return 1;
	}
	return -1;
}
