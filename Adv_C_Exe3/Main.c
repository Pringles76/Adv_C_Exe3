#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{

	// *************** Flip Between Hashes *************** //

	char sentence[] = "Remem# reb#thi#carp s#tice";
	printf("Flip Function\n");
	printf("Before: %s\n", sentence);
	printf("After:");
	flipBetweenHashes(sentence);
	puts("");

	// *************** Is Palindrom *************** //

	printf("Palindrome function\n");

	// Stack 2:
	// Definition
	Stack S2;
	initStack(&S2);
	push(&S2, 'M');
	push(&S2, 'A');
	push(&S2, 'D');
	push(&S2, 'A');
	push(&S2, 'M');

	// Palindrom checking
	int X2 = isPalindrome(&S2);
	switch (X2)
	{
	case -1: break;
	case 0: puts("S2 is not a palindrom."); break;
	case 1: puts("S2 is a palindrom."); break;
	default: puts("Error: Palindrom >> unknown behavior in switch X2"); break;
	}

	// Stack 3
	// Definition
	Stack S3;
	initStack(&S3);
	push(&S3, 'N');
	push(&S3, 'O');
	push(&S3, 'O');
	push(&S3, 'N');

	// Palindrom checking
	int X3 = isPalindrome(&S3);
	switch (X3)
	{
	case -1: break;
	case 0: puts("S3 is not a palindrom."); break;
	case 1: puts("S3 is a palindrom."); break;
	default: puts("Error: Palindrom >> unknown behavior in switch X3"); break;
	}

	// Stack 4
	// Definition
	Stack S4;
	initStack(&S4);
	push(&S4, 'W');
	push(&S4, 'H');
	push(&S4, 'A');
	push(&S4, 'T');

	// Palindrom checking
	int X4 = isPalindrome(&S4);
	switch (X4)
	{
	case -1: break;
	case 0: puts("S4 is not a palindrom."); break;
	case 1: puts("S4 is a palindrom."); break;
	default: puts("Error: Palindrom >> unknown behavior in switch X4"); break;
	}
	puts("");

	// *************** Rotate Stack *************** //

	printf("Rotation function\n");

	// Definition
	Stack S7;
	initStack(&S7);
	push(&S7, 'A');
	push(&S7, 'B');
	push(&S7, 'C');
	push(&S7, 'D');
	push(&S7, 'E');

	// Rotation
	rotateStack(&S7, 2);

	for (int i = 1; i <= 5; i++)
	{
		printf("%c", pop(&S7));
	}
	puts("\n");


	// *************** Rotate Queue *************** //

	printf("Rotation function\n");

	// Definition
	Queue Q2;
	initQueue(&Q2);
	enqueue(&Q2, 1);
	enqueue(&Q2, 2);
	enqueue(&Q2, 3);
	enqueue(&Q2, 4);

	// Rotation
	rotateQueue(&Q2);
	for (int i = 0; i < 4; i++)
	{
		printf("%d", dequeue(&Q2));
	}
	destroyQueue(&Q2);
	puts("\n");


	// **************** Cut and Replace *************** //




	// *************** Sort Kids First *************** //

	printf("Sort function\n");

	// Definition
	Queue Q3;
	initQueue(&Q3);
	enqueue(&Q3, 7);
	enqueue(&Q3, 5);
	enqueue(&Q3, 26);
	enqueue(&Q3, 18);

	// Sort
	sortKidsFirst(&Q3);
	for (int i = 0; i < 4; i++)
	{
		printf("%d\t", dequeue(&Q3));
	}
	destroyQueue(&Q3);
	puts("");
}