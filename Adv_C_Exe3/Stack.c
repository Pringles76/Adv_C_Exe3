#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	// function actions
	if (s == NULL)
	{
		exit(1);
	}
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
	if (isEmptyStack(&s) == 1)
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
		initStack(&s);
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
	// Case [1/3]: Unexisting sentence
	if (sentence == NULL)
	{
		puts("Error: Flip >> unable to flip because the sentence does not exist.");
	}

	// Cases 2 and 3 >>
	char* Sptr = sentence;

	// Case[2/3]: Empty Sentence
	if (*Sptr == '\0')
	{
		puts("Error: Flip >> unable to flip because the sentence is empty.");
	}

	// Case [3/3]: Existing sentence
	while (*Sptr != '\0')
	{
		if (*Sptr == '#')
		{
			// Variables initialization
			Sptr++;
			Stack S1;
			initStack(&S1);

			// Flipping
			while (*Sptr != '#')
			{
				push(&S1, *Sptr);
				Sptr++;
			}
			Sptr++;

			// Printing the flipped format
			while (isEmptyStack(&S1) != 1)
			{
				printf("%c", pop(&S1));
			}
		}
		else
		{
			// Printing the sentence as is
			printf("%c", *Sptr);
			Sptr++;
		}
	}

	// Final Touch
	puts("");
	//destroyStack(&S1);		// is this because its outside the "while"?
}

int isPalindrome(Stack* s)
{
	// Case [1/3]: Uninitialized stack
	if (s == NULL)
	{
		puts("Error: Palindrom >> unable to check palindromation because the stack doesn't exist.");
		return -1;
	}

	// Case [2/3]: Empty Stack
	if (isEmptyStack(&s) == 1)
	{
		return 1;
	}

	// Case [3/3]: Unempty Stack
	char container[50];
	int counter = 0;

	// Poping into the container
	while (isEmptyStack(&s) != 1)
	{
		container[counter] = pop(&s);
		counter++;
	}

	// Palindrom checking
	for (int i = 0; i < counter / 2; i++)
	{
		if (container[i] == container[i - counter])
		{
			continue;
		}
		else
		{
			// Not a palindrome
			return 0;
		}
	}

	// Is a palindrome
	return 1;
}

void rotateStack(Stack* s, int n)
{
	// Case [1/7]: Uninitialized stack
	if (s == NULL)
	{
		puts("Error: Rotate >> unable to rotate stack because the stack doesn't exist.");
		return;
	}

	// case [2/7]: Empty stack
	if (isEmptyStack(&s) == 1)
	{
		puts("Error: Rotate >> unable to rotate stack because the stack is empty.");
		return;
	}

	// case [3/7]: Netagive n value
	if (n < 0)
	{
		puts("Be advised: the 'n' value was negative, resulting no function actions.");
		return;
	}

	// cases 4, 5, 6, 7 >> stack length checking
	charNode* Snode = s->head;
	int counter = 0;
	while (Snode != NULL)
	{
		Snode = Snode->next;
		counter++;
	}

	// case [4/7]: Oversized n value
	if (n > counter)
	{
		puts("Be advised: 'n' value was oversized, resulting no function actions.");
	}

	// case [5/7]: One item stack
	if (counter == 1)
	{
		return;		// no special actions requiered
	}

	// case [6/7]: Equality between n and counter
	if (n == counter)
	{
		return;		// no special actions requiered
	}

	// case [7/7]: No special problems
	Stack S5;
	Stack S6;
	char temp;

	// Top items transfer from s to S5
	for (int i = 1; i <= (counter - n); i++)
	{
		temp = pop(&s);
		push(&S5, temp);
	}

	// Bottom items transfer from s to S6
	for (int j = 1; j = n; j++)
	{
		temp = pop(&s);
		push(&S6, temp);
	}
	
	// Top items transfer from S5 to s
	for (int k = 1; k <= (counter - n); k++)
	{
		temp = pop(&S5);
		push(&s, temp);
	}

	// Bottom items transfer from S6 to s
	for (int l = 1; l = n; l++)
	{
		temp = pop(&S6);
		push(&s, temp);
	}
}