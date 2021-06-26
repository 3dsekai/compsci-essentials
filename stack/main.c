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
	for (i = 0; i < 26; i++)
	{
		DATA item;
		{
			item.id = i;
			item.character = 'A' + i;
		}
		Push(&top, item);
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
	for (i = 25; i >= 0; i--)
	{
		DATA item;
		{
			item.id = i;
			item.character = 'A' + i;
		}
		Push(&top, item);
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
	DATA item;
	{
		item.character = '\0';
		item.id = -1;
	}
	item = Find(&top, 13);
	if (item.id != -1)
	{
		printf("Data ID is: %d\nData Character is: %c", item.id, item.character);
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
