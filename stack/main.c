//********************************************************
//
// Stack
// File: main.c
//
// Copyright (C) <2021>  <Christopher Tall>
// Licensed under the GPLv3 <https://www.gnu.org/licenses/>.
//
//********************************************************

//********************************************************
// Includes
//********************************************************
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main()
{
	NODE* top = NULL;
	int i = 0;

	//
	//push nodes to stack
	//
	for (i = 1; i <= 50; i++)
	{
		Push(&top, i);
	}
	//print stack
	printf("*************************************\n");
	printf("Push To Stack\n");
	printf("*************************************\n");
	PrintStack(&top);
	printf("\n");

	//
	//pop all nodes from stack
	//
	printf("Pop all nodes from stack...\n\n");
	while (!IsEmpty(&top))
	{
		Pop(&top);
	}
	assert(top == NULL);

	//print stack
	printf("Print stack...\n");
	PrintStack(&top);
	printf("\n");

	//
	//Re-push nodes
	//
	for (i = 50; i >= 1; i--)
	{
		Push(&top, i);
	}

	//print stack
	printf("*************************************\n");
	printf("Push To Stack\n");
	printf("*************************************\n");
	PrintStack(&top);
	printf("\n");

	//print stack
	printf("*************************************\n");
	printf("Find Node\n");
	printf("*************************************\n");
	int data = -1;
	data = Find(&top, 14);
	if (data != -1)
	{
		printf("Node ID is: %d\n", data);
	}
	else
	{
		printf("Could not find node.\n");
	}
	printf("\n");

	//
	//erase stack
	//
	printf("Erase entire stack...\n\n");
	EraseStack(&top);
	assert(top == NULL);

	//print stack
	printf("Print stack...\n");
	PrintStack(&top);
	printf("\n");

	return 0;
}
