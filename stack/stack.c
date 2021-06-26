//********************************************************
//
// Stack
// File: stack.c
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

//********************************************************
// Push item to the stack
//********************************************************
void Push(NODE** top, DATA item)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	assert(node != NULL);

	DATA* newItem = (DATA*)malloc(sizeof(DATA));
	assert(newItem != NULL);

	newItem->character = item.character;
	newItem->id = item.id;

	if (node != NULL)
	{
		node->data = newItem;

		if ((*top) == NULL)
		{
			node->next = NULL;
		}
		else
		{
			node->next = (*top);
		}

		(*top) = node;
	}
}

//********************************************************
// Pop item from the stack
//********************************************************
DATA Pop(NODE** top)
{
	DATA r;
	{
		r.id = -1;
		r.character = '\0';
	}
	NODE* node = (*top);
	
	if ((*top) != NULL)
	{
		r = (*(*top)->data);
		(*top) = (*top)->next;
		
		free(node->data);
		node->data = NULL;
		free(node);
		node = NULL;
	}

	return r;
}

//********************************************************
// Peek at the item on top of the stack
//********************************************************
//int Peek();

//********************************************************
// Find an item in the stack
//********************************************************
DATA Find(NODE** top, int id)
{
	DATA r;
	{
		r.character = '\0';
		r.id = -1;
	}
	NODE* node = (*top);

	while (node != NULL)
	{
		if (node->data != NULL)
		{
			if (node->data->id == id)
			{
				r = *(node->data);
				break;
			}
		}
		node = node->next;
	}
	return r;
}

//********************************************************
// Determine if the stack is empty
//********************************************************
BOOL IsEmpty(NODE** top)
{
	return (*top) == NULL;
}

//********************************************************
// Print the entire stack
//********************************************************
void PrintStack(NODE** top)
{
	NODE* node = (*top);
	while (node != NULL)
	{
		if (node->data != NULL)
		{
			printf("{ID: %d, CHARACTER: %c}\n", node->data->id, node->data->character);
			node = node->next;
		}
	}
}

//********************************************************
// Erase the entire stack
//********************************************************
void EraseStack(NODE** top)
{
	NODE* node = (*top);
	while (node != NULL)
	{
		NODE* next = node->next;

		free(node->data);
		node->data = NULL;
		free(node);
		node = NULL;

		node = next;
	}
	(*top) = node;
}