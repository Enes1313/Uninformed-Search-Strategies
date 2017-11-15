/*
 * USS.h
 *	Not: String bir değerden veya bir diziden ağaç yapımıza aktaran bir fonk. yazılabilir.
 *  Created on: 11 Kas 2017
 *      Author: tayyizaman
 */

#ifndef USS_H_
#define USS_H_

#include "st_qu_ll.h"

#define MAX_NODES 4

struct node{
	Data data;
	Data cost;
	struct node * subNodes[MAX_NODES];
};
typedef struct node * Node;

void clearNodes(Node);
void setNodes(Node, int, int);

struct my_tree{
	Node root;
	Node iter;
};
typedef struct my_tree * MyTree;

MyTree initMyTree(int);
void clearMyTree(MyTree);
int isEmptyMyTree(MyTree);

/* Breadth First Search */
int BFSforMT(MyTree, Data);

/* Uniformed Cost Search */
int UCSforMT(MyTree, Data);

/* Depth First Search */
int DFSforMT(MyTree, Data);
int searchForDFS(Node, Data);

/* Depth Limited Search */
int DLSforMT(MyTree, Data, int);
int searchForDLS(Node, Data, int);

#endif /* USS_H_ */
