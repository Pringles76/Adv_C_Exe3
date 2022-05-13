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
	printf("Flip Function: ");
	flipBetweenHashes(sentence);

	// *************** Is Palindrom *************** //

	// Stack 2:
	// Definition
	Stack S2;
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

	// *************** Rotate Stack *************** //

	// Definition
	Stack S7;
	push(&S7, 'A');
	push(&S7, 'B');
	push(&S7, 'C');
	push(&S7, 'D');
	push(&S7, 'E');

	// Rotation
	rotateStack(&S7, 2);
}