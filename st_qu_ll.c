/*
 * st_qu.c
 *
 *  Created on: 12 Kas 2017
 *      Author: tayyizaman
 */

#include "st_qu_ll.h"

#include <stdio.h>
#include <stdlib.h>

// Stack

Stack createStack()
{
	Stack s = (Stack) calloc(1, sizeof(struct stack));

	if(s == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	return s;
}

void clearStack(Stack s)
{
	while(s->top != NULL)
	{
		Item tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}

	free(s);
}

int isEmptyStack(Stack s)
{
	if(s->top == NULL)
		return 1;
	return 0;
}

int pop(Stack s, pData pd)
{
	if(!isEmptyStack(s))
	{
		Item tmp = s->top;
		*pd = s->top->data;
		s->top = s->top->next;
		free(tmp);
		return 1;
	}
	return 0;
}

void push(Stack s, Data d)
{
	Item tmp = (Item) malloc(sizeof(struct item));

	if(tmp == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	tmp->data = d;

	if(isEmptyStack(s))
		tmp->next = NULL;
	else
		tmp->next = s->top;

	s->top = tmp;
}

int peekStack(Stack s, pData pd)
{
	if(!isEmptyStack(s))
	{
		*pd = s->top->data;
		return 1;
	}
	return 0;
}

//Queue

Queue createQueue()
{
	Queue q = (Queue) calloc(1, sizeof(struct queue));

	if(q == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	return q;
}

void clearQueue(Queue q)
{
	while(q->front != NULL)
	{
		Item tmp = q->front;
		q->front = q->front->next;
		free(tmp);
	}

	free(q);
}

int isEmptyQueue(Queue q)
{
	if(q->front == NULL)
		return 1;
	return 0;
}

int dequeue(Queue q, pData pd)
{
	if(!isEmptyQueue(q))
	{
		Item tmp = q->front;
		*pd = q->front->data;
		q->front = q->front->next;
		free(tmp);
		return 1;
	}
	return 0;
}

void enqueue(Queue q, Data d)
{
	Item tmp = (Item) malloc(sizeof(struct item));

	if(tmp == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	tmp->data = d;
	tmp->next = NULL;

	if(isEmptyQueue(q))
		q->front = tmp;
	else
		q->rear->next = tmp;

	q->rear = tmp;
}

int peekQueue(Queue q, pData pd)
{
	if(!isEmptyQueue(q))
	{
		*pd = q->front->data;
		return 1;
	}
	return 0;
}

// LinkedList

LinkedList createLinkedList()
{
	LinkedList ll = (LinkedList) calloc(1, sizeof(struct linked_list));

	if(ll == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	return ll;
}

void clearLinkedList(LinkedList ll)
{
	while(ll->head != NULL)
	{
		Item tmp = ll->head;
		ll->head = ll->head->next;
		free(tmp);
	}

	free(ll);
}

int isEmptyLinkedList(LinkedList ll)
{
	if(ll->head == NULL)
		return 1;
	return 0;
}

int get(LinkedList ll, pData pd)
{
	if(!isEmptyLinkedList(ll))
	{
		Item tmp = ll->head;
		*pd = ll->head->data;
		ll->head = ll->head->next;
		free(tmp);
		return 1;
	}
	return 0;
}

void insert(LinkedList ll, Data d)
{
	Item tmp = (Item) malloc(sizeof(struct item));

	if(tmp == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	tmp->data = d;

	if(isEmptyLinkedList(ll))
	{
		ll->head = tmp;
		tmp->next = NULL;
	}
	else
	{
		Item iter = ll->head;

		while(iter->next != NULL && iter->next->data < d)
			iter = iter->next;

		tmp->next = iter->next;
		iter->next = tmp;
	}
}

int peekLinkedList(LinkedList ll, pData pd)
{
	if(!isEmptyLinkedList(ll))
	{
		*pd = ll->head->data;
		return 1;
	}
	return 0;
}
