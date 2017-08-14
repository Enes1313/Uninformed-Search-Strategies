#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main_uss.h"

int main()
{
	int s = 10, l = 5;
	SmTree *smTree = initSmTree(4);
	/* A�ac�n sahip olabilece�i maksimum leveli paremetre olarak al�yor.  Rand ile kontrol oldu�u i�in 1-2-3 de olabilir*/
	
	if(BFSforST(smTree, s) == 1) /*A�a� i�inde bir kez buldumu ba�ar�l� olacakt�r. */
		printf("\n\nBFS: Aranan Deger (%d) Var!\n\n", s);
	else
		printf("\n\nBFS: Aranan Deger (%d) Yok!\n\n", s);
	
	if(UCSforST(smTree, s) == 1) /*A�a� i�inde bir kez buldumu ba�ar�l� olacakt�r. */
		printf("\n\nUCS: Aranan Deger (%d) Var!\n\n", s);
	else
		printf("\n\nUCS: Aranan Deger (%d) Yok!\n\n", s);
	
	if(DFSforST(smTree, s) == 1) /*A�a� i�inde bir kez buldumu ba�ar�l� olacakt�r. */
		printf("\n\nDFS: Aranan Deger (%d) Var!\n\n", s);
	else
		printf("\n\nDFS: Aranan Deger (%d) Yok!\n\n", s);
	
	if(DLSforST(smTree, s, l) == 1) /*A�a� i�inde bir kez buldumu ba�ar�l� olacakt�r. */
		printf("\n\nDLS: Aranan Deger (%d) Var!\n\n", s);
	else
		printf("\n\nDLS: Aranan Deger (%d) Yok!\n\n", s);
		
	clearSmTree(smTree);
	
	return 0;
}

void clearSmTree(SmTree *smTree) /*Sorunlu olabilir bakmak laz�m.*/
{
	if(smTree == NULL)
		return;
	clearSmTree(smTree->subNodes[0]);
	clearSmTree(smTree->subNodes[1]);
	clearSmTree(smTree->subNodes[2]);
	clearSmTree(smTree->subNodes[3]);
	
	free(smTree);
}

void doldur(SmTree * smTree, int level, int step)
{
	int i, j;
	
	if (level >= step)
	{
		for (i = 0; i < MAX_NODES; i++)
		{
			if (rand() % 2 == 0)
			{
				smTree->subNodes[i] = (SmTree *) malloc(sizeof(SmTree));
				smTree->subNodes[i]->data = rand() % 100;
				smTree->subNodes[i]->cost = (rand() % 21) * 10 + 100; /* 100 ile 300 aras�*/
				
				printf("* Level: %2d, UstDgm: %x, Dgm: %x, Data: %4d, Cost: %4d *\n", step, *((unsigned int *)&smTree), 
				*((unsigned int *)&smTree->subNodes[i]), smTree->subNodes[i]->data, smTree->subNodes[i]->cost);
				
				doldur(smTree->subNodes[i], level, step + 1);
			}
			else
				smTree->subNodes[i] = NULL;
		}
	}
	else
		for (j = 0; j < MAX_NODES; j++)
			smTree->subNodes[j] = NULL;
}

SmTree * initSmTree(int po)
{
	SmTree *smTree = (SmTree *) malloc(sizeof(SmTree)); /*root i�in yer tahsisi*/
	
	srand(time(NULL)); /* program her a��ld���nda farkl� de�erler �retmek i�in*/
	smTree->data = rand() % 100; /*Degistirilebilir.*/
	smTree->cost = 0;
	/*Rootun leveli 1 dir. 1 d���m olan yerdir. A�ac�m�z�n ba�lang�c�d�r. */
	printf("************************** Agac yapimiz **************************\n");
	printf("* Level:  1, Kendisi Root  , Dgm: %x, Data: %4d, Cost:    0 *\n", *((unsigned int *)&smTree), smTree->data);
	doldur(smTree, po, 2); /*A�ac� random doldurma. Doldurma �ekli sol a�a�lardan sa� a�a�lara do�rudur.*/
	printf("******************************************************************\n");
	return smTree;
}

#include "bfs.c"
#include "ucs.c"
#include "dfs.c"
#include "dls.c"
