//********************************************************
//
// Queue
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
#include "queue.h"

//********************************************************
// method declarations
//********************************************************
BOOL IsDataInvalid(DATA data);

//********************************************************
// Is this data invalid?
//********************************************************
BOOL IsDataInvalid(DATA data)
{
	if (data.id == -1)
	{
		return TRUE;
	}
	return FALSE;
}

int main()
{
	NODE* first = NULL;
	NODE* last = NULL;
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
		Add(&first, &last, item);
	}
	//print queue
	printf("*************************************\n");
	printf("Add To Queue\n");
	printf("*************************************\n");
	PrintQueue(&first);
	printf("\n");

	//
	//remove all nodes from queue
	//
	printf("Remove all nodes from queue...\n\n");
	while (!IsEmpty(&first, &last))
	{
		Remove(&first, &last);
	}
	assert(first == NULL && last == NULL);

	//print queue
	printf("Print queue...\n");
	PrintQueue(&first);
	printf("\n");

	//
	//Re-add nodes
	//
	for (i = 25; i >= 0; i--)
	{
		DATA item;
		{
			item.id = i;
			item.character = 'A' + i;
		}
		Add(&first, &last, item);
	}

	//print queue
	printf("*************************************\n");
	printf("Add To Queue\n");
	printf("*************************************\n");
	PrintQueue(&first);
	printf("\n");

	printf("Peek in Queue:\n");
	DATA peek = Peek(&first);
	if (!IsDataInvalid(peek))
	{
		printf("{ID: %d, CHARACTER: %c}\n\n", peek.id, peek.character);
	}
	else
	{
		printf("No data in queue to peek.\n\n");
	}
	//Find node in queue
	printf("*************************************\n");
	printf("Find Node\n");
	printf("*************************************\n");
	DATA item;
	{
		item.character = '\0';
		item.id = -1;
	}
	item = Find(&first, 13);
	if (item.id != -1)
	{
		printf("Data ID is: %d\nData Character is: %c\n", item.id, item.character);
	}
	else
	{
		printf("Could not find node.\n");
	}
	printf("\n");

	//
	//erase queue
	//
	printf("Erase entire queue...\n\n");
	EraseQueue(&first, &last);
	assert(first == NULL && last == NULL);

	//print queue
	printf("Print queue...\n");
	PrintQueue(&first);
	printf("\n");

	return 0;
}