#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	// function actions
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	// case [1/2]: empty queue
	if (isEmptyQueue(q) == 1)
	{
		return;
	}

	// case [2/2]: unempty queue
	intNode* curr = q->head;
	intNode* prev = NULL;

	// function actions
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	q->head = NULL;
	q->tail = NULL;
	return;
}

void enqueue(Queue* q, unsigned int data)
{
	// new node creation and allocation check
	intNode* newNode = (intNode*)malloc(sizeof(intNode));
	if (!newNode)
	{
		puts("Error: enqueue >> newNode allocation faliure.");
		return;
	}

	// function actions
	newNode->data = data;
	newNode->next = NULL;

	// case [1/2]: empty queue
	if (isEmptyQueue(q) == 1)
	{
		// function actions
		q->head = newNode;
		q->tail = newNode;
		return;
	}

	// case [2/2]: unempty queue
	// function actions
	q->tail->next = newNode;
	q->tail = newNode;
	return;
}

unsigned int dequeue(Queue* q)
{
	// case [1/3]: empty queue
	if (isEmptyQueue(q) == 1)
	{
		puts("Error: dequeue >> unable to dequeue because the queue is empty.");
		return 0;
	}

	// function actions
	unsigned int item;
	item = q->head->data;

	// case [2/3]: one item queue
	if (q->head == q->tail)
	{
		// function actions
		free(q->head);
		free(q->tail);
		q->head = NULL;
		q->tail = NULL;
		return item;
	}

	// case [3/3]: more than one item queue
	intNode* temp = q->head;
	q->head = q->head->next;
	free(temp);
	return item;
}

int isEmptyQueue(const Queue* q)
{
	// function actions
	if ((q->head == NULL) && (q->tail == NULL))
	{
		return 1;									// 1 represents an empty queue
	}
	else
	{
		return 0;									// 0 represents an unempty queue
	}
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}