#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	// function actions
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	// case [1/2]: empty stack
	if (isEmptyStack(s) == 1)
	{
		return;
	}

	// case [2/2]: unempty stack
	charNode* curr = s->head;
	charNode* prev = NULL;

	// function actions
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	s->head = NULL;
	return;
}

void push(Stack* s, char data)
{
	// new node creation and allocation check
	charNode* newNode = (charNode*)malloc(sizeof(charNode));
	if (!newNode)
	{
		puts("Error: push >> newNode allocation faliure.");
		return;
	}

	// function actions
	newNode->data = data;
	newNode->next = NULL;

	// case [1/2]: empty stack
	if (isEmptyStack(s) == 1)
	{
		// function actions
		s->head = newNode;
		return;
	}

	// case [2/2]: unempty stack
	// function actions
	newNode->next = s->head;
	s->head = newNode;
	return;
}

char pop(Stack* s)
{
	// case [1/3]: empty stack
	if (isEmptyStack(s) == 1)
	{
		puts("Error: pop >> unable to pop because the stack is empty.");
		return NULL;
	}

	// function actions
	char item;
	item = s->head->data;

	// case [2/3]: one item stack
	if (s->head->next == NULL)
	{
		free(s->head);
		return item;
	}

	// case [3/3]: more than one item stack
	charNode* temp = s->head;
	s->head = s->head->next;
	free(temp);
	return item;
}


int isEmptyStack(const Stack* s)
{
	// function actions
	if (s->head == NULL)
	{
		return 1;					// 1 represents an empty stack
	}
	else
	{
		return 0;					// 0 represents an unempty stack
	}
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	// add your code here
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}