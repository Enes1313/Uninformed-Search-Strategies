/*
 * st_qu.h
 *
 *  Created on: 12 Kas 2017
 *      Author: tayyizaman
 */

#ifndef ST_QU_LL_H_
#define ST_QU_LL_H_

#include <stddef.h>

typedef size_t Data;
typedef size_t * pData;

/*
 * Node
 */

struct item{
	Data data;
	struct item * next;
};
typedef struct item * Item;

/*
 * Stack
 */

struct stack{
	Item top;
};
typedef struct stack * Stack;

Stack createStack();
void clearStack(Stack);

int isEmptyStack(Stack);
int pop(Stack, pData);
void push(Stack, Data);
int peekStack(Stack, pData);

/*
 * Queue
 */

struct queue{
	Item front;
	Item rear;
};
typedef struct queue * Queue;

Queue createQueue();
void clearQueue(Queue);

int isEmptyQueue(Queue);
int dequeue(Queue, pData);
void enqueue(Queue, Data);
int peekQueue(Queue, pData);

/*
 * LinkedList
 */

struct linked_list{
	Item head;
	//Item tail; güncelleme yapılabilir. Fonksiyonlarla birlikte
};
typedef struct linked_list * LinkedList;

LinkedList createLinkedList();
void clearLinkedList(LinkedList);

int isEmptyLinkedList(LinkedList);
int get(LinkedList, pData); // and delete
void insert(LinkedList, Data); //sorted
int peekLinkedList(LinkedList, pData);



#endif /* ST_QU_LL_H_ */
