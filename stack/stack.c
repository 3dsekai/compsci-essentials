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
#include "stack.h"

//********************************************************
// Push item to the stack
//********************************************************
void Push(NODE** top, int item)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	if (node != NULL)
	{
		node->data = item;

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
int Pop(NODE** top)
{
	int r = -1;
	NODE* node = (*top);
	
	if ((*top) != NULL)
	{
		r = (*top)->data;
		(*top) = (*top)->next;
		free(node);
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
int Find(NODE** top, int id)
{
	int r = -1;
	NODE* node = (*top);

	while (node != NULL)
	{
		if (node->data == id)
		{
			r = node->data;
			break;
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
		printf("%d\n", node->data);
		node = node->next;
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
		free(node);
		node = next;
	}
	(*top) = node;
}