//********************************************************
//
// Queue
// File: queue.c
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
// Add item to the queue
//********************************************************
void Add(NODE** first, NODE** last, DATA item)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	assert(newNode != NULL);

	DATA* newItem = (DATA*)malloc(sizeof(DATA));
	assert(newItem != NULL);
	
	newItem->character = item.character;
	newItem->id = item.id;

	newNode->data = newItem;
	newNode->next = NULL;

	if ((*last) != NULL)
	{
		(*last)->next = newNode;
	}
	(*last) = newNode;

	if ((*first) == NULL)
	{
		(*first) = (*last);
	}
}

//********************************************************
// Remove item from the queue
//********************************************************
DATA Remove(NODE** first, NODE** last)
{
	DATA r;
	{
		r.character = '\0';
		r.id = -1;
	}

	NODE* node = (*first);
	if ((*first) != NULL)
	{
		r = (*(*first)->data);
		(*first) = (*first)->next;

		free(node->data);
		node->data = NULL;
		free(node);
		node = NULL;
	}

	if ((*first) == NULL)
	{
		(*last) = NULL;
	}
	return r;
}

//********************************************************
// Peek at the first item in the queue
//********************************************************
DATA Peek(NODE** first)
{
	DATA r;
	{
		r.character = '\0';
		r.id = -1;
	}
	if ((*first) != NULL)
	{
		if ((*first)->data != NULL)
		{
			r = (*(*first)->data);
		}
	}
	return r;
}

//********************************************************
// Find an item in the queue
//********************************************************
DATA Find(NODE** first, int id)
{
	DATA r;
	{
		r.character = '\0';
		r.id = -1;
	}
	NODE* node = (*first);

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
// Determine if the queue is empty
//********************************************************
BOOL IsEmpty(NODE** first, NODE** last)
{
	return ((*first) == NULL && (*last) == NULL);
}

//********************************************************
// Print the entire queue
//********************************************************
void PrintQueue(NODE** first)
{
	NODE* node = (*first);
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
// Erase the entire queue
//********************************************************
void EraseQueue(NODE** first, NODE** last)
{
	NODE* node = (*first);
	while (node != NULL)
	{
		NODE* next = node->next;

		free(node->data);
		node->data = NULL;
		free(node);
		node = NULL;

		node = next;
	}
	(*first) = NULL;
	(*last) = NULL;
}