//********************************************************
//
// Doubly Linked List
// File: doubly_linked_list_test.c
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

void DoublyLinkedListTest()
{
	NODE* head = NULL;
	int i = 0;

	//
	//push nodes to front of list
	//
	for(i = 1; i <= 50; i++)
	{
		PushNode(&head, i);
	}
	//print list
	printf("*************************************\n");
	printf("Push Nodes\n");
	printf("*************************************\n");
	PrintList(&head);
	printf("\n");

	//
	//delete list
	//
	DeleteList(&head);

	//print list
	printf("Print deleted nodes...\n");
	PrintList(&head);
	printf("\n");

	//
	//append nodes to front of list
	//
	for(i = 1; i <= 50; i++)
	{
		AppendNode(&head, i);
	}
	//print list
	printf("*************************************\n");
	printf("Append Nodes\n");
	printf("*************************************\n");
	PrintList(&head);
	printf("\n");

	//
	//delete list
	//
	for(i = 1; i <= 50; i++)
	{
		DeleteNode(&head, i);
	}
	//print list
	printf("Print deleted nodes...\n");
	PrintList(&head);
	printf("\n");
/*
	//
	// reverse list
	//
	printf("*************************************\n");
	printf("Reverse Nodes\n");
	printf("*************************************\n");
	
	//push new nodes
	for(i = 1; i <= 10; i++)
	{
		AppendNode(&head, i);
	}

	//print nodes
	printf("Forward List:\n");
	PrintList(&head);
	printf("\n");

	//reverse the nodes
	ReverseList(&head);

	//print nodes
	printf("Reversed List:\n");
	PrintList(&head);
	printf("\n");

	//re-reverse back to normal
	ReverseList(&head);
	printf("Re-reversed List:\n");
	PrintList(&head);
	printf("\n");
*/
}
