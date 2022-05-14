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
		initQueue(q);
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
	// Case [1/4]: Unexisting queue
	if (q == NULL)
	{
		puts("Error: Rotate >> unable to rotate queue because the queue doesn't exist.");
		return;
	}

	// Case [2/4]: Empty queue
	if (isEmptyQueue(q) == 1)
	{
		puts("Error: Rotate >> unable to rotate queue because the queue is empty.");
		return;
	}

	// Case [3/4]: One item queue
	if (q->head->next == NULL)
	{
		return;			// no special actions requiered;
	}


	// Case [4/4]: General case
	intNode* temp = q->head;
	Queue Q1;
	initQueue(&Q1);
	int counter = 0;

	// Transfer from q to Q1
	while (1)
	{
		int num = dequeue(q);
		if (isEmptyQueue(q))
		{
			enqueue(q, num);
			break;
		}
		else
		{
			counter++;
			enqueue(&Q1, num);
		}
	}

	// Transfer from Q1 back to q
	for (int i = 1; i <= counter; i++)
	{
		int I = dequeue(&Q1);
		enqueue(q, I);
	}

	//// Case [4/4]: General case
	//intNode* prev = NULL;
	//intNode* curr = q->head;
	//intNode* next = q->head->next;
	//q->tail = q->head;

	//// Rotation
	//while (next != NULL)
	//{
	//	curr->next = prev;
	//	prev = curr;
	//	curr = next;
	//	next = next->next;
	//}

	//// Rotation finish
	//curr->next = prev;
	//q->head = curr;
	//return;
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	int numbers[50], length = 0;
	while (isEmptyQueue(q) != 1)
	{
		numbers[length] = dequeue(q);
		length++;
	}

	for (int i = 0; i < length * length; i++)
	{
		if (numbers[(i % length) + 1] > numbers[(i % length)])
		{
			int temp = numbers[(i % length) + 1];
			numbers[(i % length) + 1] = numbers[(i % length)];
			numbers[(i % length)] = temp;
		}
	}

	for (int i = 0; i < length; i++)
	{
		enqueue(q, numbers[length - i - 1]);
	}
}