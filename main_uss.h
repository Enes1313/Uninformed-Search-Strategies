#ifndef _MAIN_USS
#define _MAIN_USS

#define MAX_NODES 4

/**************Aðaç yapýmýz**************/
struct pt{
	int data; /* Veri */
	int cost; /* Maliyet = Uniformed Cost Search algoritmasý buna bakýp ilerler. */
	struct pt * subNodes[MAX_NODES];
};
typedef struct pt SmTree;

SmTree * initSmTree(int);
void clearSmTree(SmTree *);
/****************************************/
struct ns{	/* BFS ve UCS için veri yapýsý gerekmektedir. */
	SmTree * nd;
	struct ns * next;
};
typedef struct ns Liste;

/* Breadth First Search algoritmasý için */

Liste * rootBFS = NULL;

SmTree * popForBFS();
void pushForBFS(SmTree *);
int BFSforST(SmTree *, int);

/* Uniformed Cost Search algoritmasý için */

Liste * rootUCS = NULL;

SmTree * popForUCS();
int UCSforST(SmTree *, int);
void pushForUCS(SmTree *smTree);

/* Depth First Search algoritmasý için */

SmTree *rootKontrolDFS;

int DFSforST(SmTree *, int);
int searchForDFS(SmTree *smTree, int);

/* Depth Limited Search algoritmasý için */

SmTree *rootKontrolDLS;

int DLSforST(SmTree *, int, int);
int searchForDLS(SmTree *, int, int);

#endif
