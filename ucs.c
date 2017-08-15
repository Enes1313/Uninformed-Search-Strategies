int UCSforST(SmTree *smTree, int m)
{
	int i; 
	SmTree *buff = smTree;
	
	if(smTree == NULL)
	{
		puts("Agac bos!");
		return -1;
	}
	
	printf("\nUCS: Araniyor.\n\n");
	printf("Dugum : Root  , Data : %4d, Cost :    0 (root)\n", smTree->data);
	
	if (buff->data == m)
	{
		while(popForUCS() != NULL);
		return 1;
	}
	
	while(buff != NULL)
	{
		for(i = 0; i < MAX_NODES; i++)
			if(buff->subNodes[i] != NULL)
			{
				buff->subNodes[i]->cost += buff->cost;
				pushForUCS(buff->subNodes[i]);
			}
				
		buff = popForUCS();
		
		if(buff != NULL)
		{
			printf("Dugum : %x, Data : %4d, Cost : %4d\n", *((unsigned int *)&buff), buff->data, buff->cost);
			
			if (buff->data == m)
			{
				while(popForUCS() != NULL);
				return 1;
			}
		}
	}
	
	return -1;
}

void pushForUCS(SmTree *smTree)
{
	Liste * iter = rootUCS;
	Liste * temp = (Liste *) malloc(sizeof(Liste));
	
	if(rootUCS == NULL)
	{ 
		rootUCS = (Liste *) malloc(sizeof(Liste));
		rootUCS->nd = smTree;
		rootUCS->next = NULL;
	}
	else if(rootUCS->nd->cost > smTree->cost)
	{
		temp->next = rootUCS;
		rootUCS = temp;
		temp->nd = smTree;
	}
	else
	{
		while((iter->next != NULL) && (iter->next->nd->cost < smTree->cost))
			iter = iter->next;
			
		temp->next = iter->next;
		iter->next = temp;
		temp->nd = smTree;
	}
}

SmTree * popForUCS()
{
	SmTree * smTree = NULL;
	
	if(rootUCS != NULL)
	{
		Liste * temp = rootUCS->next;
		smTree = rootUCS->nd;
		free(rootUCS);
		rootUCS = temp;
	}
	
	return smTree;
}
