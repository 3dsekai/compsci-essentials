//********************************************************
//
// Singly Linked List
// File: singly_linked_list.c
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
#include "singly_linked_list.h"

//********************************************************
// Add node to the front of the linked list
//********************************************************
void PushNode(NODE** head, int data)
{
	NODE* newHead = (NODE*)malloc(sizeof(NODE));
	if (newHead != NULL)
	{
		newHead->data = data;

		if (*head == NULL)
		{
			newHead->next = NULL;
		}
		else
		{
			newHead->next = *head;
		}
		*head = newHead;
	}
}
//********************************************************
// Add node to the back of the linked list
//********************************************************
void AppendNode(NODE** head, int data)
{
	NODE* node = *head;

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;

		if (node == NULL)
		{
			*head = newNode;
			return;
		}
		while (node != NULL)
		{
			if (node->next == NULL)
			{
				node->next = newNode;
				break;
			}
			node = node->next;
		}
	}
}
//********************************************************
// Delete node from linked list
//********************************************************
void DeleteNode(NODE** head, int data)
{
	NODE* node = *head;
	NODE* prevNode = *head;

	if(*head != NULL && (*head)->data == data)
	{
		*head = (*head)->next;	
		free(node);
		return;
	}

	while(node != NULL)	
	{
		if(node->data == data)
		{
			prevNode->next = node->next;
			free(node);
			break;
		}
		prevNode = node;
		node = node->next;	
	}
}
//********************************************************
// Delete entire list
//********************************************************
void DeleteList(NODE** head)
{
	NODE* node = *head;
	while(node != NULL)
	{
		NODE* nextNode = node->next;
		free(node);
		node = nextNode;
	}
	*head = NULL;
}
//********************************************************
// Print entire list
//********************************************************
void PrintList(NODE** head)
{
	NODE* node = *head;
	while(node != NULL)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}
//********************************************************
// Reverse list
//********************************************************
void ReverseList(NODE** head)
{
	NODE* prevNode = NULL;
	NODE* currentNode = *head;
	NODE* nextNode = NULL;

	while(currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	//set head to the last node in the previously unreversed list
	*head = prevNode;
}
