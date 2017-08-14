#ifndef _MAIN_USS
#define _MAIN_USS

#define MAX_NODES 4

/**************A�a� yap�m�z**************/
struct pt{
	int data; /* Veri */
	int cost; /* Maliyet = Uniformed Cost Search algoritmas� buna bak�p ilerler. */
	struct pt * subNodes[MAX_NODES];
};
typedef struct pt SmTree;

SmTree * initSmTree(int);
void clearSmTree(SmTree *);
/****************************************/
struct ns{	/* BFS ve UCS i�in veri yap�s� gerekmektedir. */
	SmTree * nd;
	struct ns * next;
};
typedef struct ns Liste;

/* Breadth First Search algoritmas� i�in */

Liste * rootBFS = NULL;

SmTree * popForBFS();
void pushForBFS(SmTree *);
int BFSforST(SmTree *, int);

/* Uniformed Cost Search algoritmas� i�in */

Liste * rootUCS = NULL;

SmTree * popForUCS();
int UCSforST(SmTree *, int);
void pushForUCS(SmTree *smTree);

/* Depth First Search algoritmas� i�in */

SmTree *rootKontrolDFS;

int DFSforST(SmTree *, int);
int searchForDFS(SmTree *smTree, int);

/* Depth Limited Search algoritmas� i�in */

SmTree *rootKontrolDLS;

int DLSforST(SmTree *, int, int);
int searchForDLS(SmTree *, int, int);

#endif
