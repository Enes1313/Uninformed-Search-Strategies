int BFSforST(SmTree *smTree, int x)
{
	int i;
	SmTree *buff = smTree;
	
	if(smTree == NULL)
	{
		puts("Agac bos!");
		return -1;
	}
	
	printf("\nBFS: Araniyor.\n\n");
	printf("Dugum : Root  , Data : %4d (root)\n", smTree->data);
	
	if (buff->data == x)
	{
		while(popForBFS() != NULL); /*Kötübir yöntem olmakla birlikte þuanlýk böyle hafiza temizleyelim.*/
		return 1;
	}
	
	while(buff != NULL)
	{
		for(i = 0; i < MAX_NODES; i++)
			if(buff->subNodes[i] != NULL)
			{
				/*BFS için alt düðümleri kuyruk yapýsýyla hafýzada tutmamýz gerekmektedir.*/
				pushForBFS(buff->subNodes[i]);
				printf("Dugum : %x, Data : %4d\n", *((unsigned int *)&buff->subNodes[i]), buff->subNodes[i]->data);
				
				if (buff->subNodes[i]->data == x)
				{
					while(popForBFS() != NULL);
					return 1;
				}
			}
		buff = popForBFS();
	}
	return -1;
}

void pushForBFS(SmTree *smTree)
{
	if(rootBFS == NULL)
	{
		rootBFS = (Liste *) malloc(sizeof(Liste));
		rootBFS->nd = smTree;
		rootBFS->next = NULL;
	}
	else
	{
		Liste *b = (Liste *) malloc(sizeof(Liste));
		b->nd = smTree;
		b->next = rootBFS;
		rootBFS = b;
	}
}

SmTree * popForBFS()
{
	SmTree * smTree;
	
	if(rootBFS == NULL)
		return NULL;
	
	if(rootBFS->next == NULL){
		smTree = rootBFS->nd;
		free(rootBFS);
		rootBFS = NULL;
		return smTree;
	}
	
	Liste * iter = rootBFS;
	while (iter->next->next != NULL)
		iter = iter->next;
	Liste * temp = iter->next;
	
	smTree = temp->nd;
	iter->next = NULL;
	free(temp);
	
	return smTree;
}
