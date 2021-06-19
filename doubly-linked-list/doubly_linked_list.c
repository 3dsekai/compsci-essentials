//********************************************************
//
// Doubly Linked List
// File: doubly_linked_list.c
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
#include "doubly_linked_list.h"

//********************************************************
// Add node to the front of the linked list
//********************************************************
void PushNode(NODE** head, int data)
{
	NODE* newHead = (NODE*)malloc(sizeof(NODE));	
	newHead->data = data;
	newHead->prev = NULL;

	if(*head == NULL)
	{
		newHead->next = NULL;
	}
	else
	{
		newHead->next = *head;
		(*head)->prev = newHead;
	}
	*head = newHead;
}
//********************************************************
// Add node to the back of the linked list
//********************************************************
void AppendNode(NODE** head, int data)
{
	NODE* node = *head;

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;

	if(node == NULL)
	{
		*head = newNode;
		return;
	}
	while(node != NULL)
	{
		if(node->next == NULL)
		{
			node->next = newNode;
			newNode->prev = node;
			break;
		}
		node = node->next;	
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
		(*head)->prev = NULL;
		free(node);
		return;
	}

	while(node != NULL)	
	{
		if(node->data == data)
		{
			prevNode->next = node->next;
			node->next->prev = prevNode;
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
