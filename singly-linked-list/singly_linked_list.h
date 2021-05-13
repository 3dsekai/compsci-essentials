//********************************************************
//
// Singly Linked List
// File: linked_list.h
//
// Copyright (C) <2021>  <Christopher Tall>
// Licensed under the GPLv3 <https://www.gnu.org/licenses/>.
//
//********************************************************

//********************************************************
// structs
//********************************************************
typedef struct Node
{
	struct Node* next;
	int data;
} NODE;

//********************************************************
// method declarations
//********************************************************
void PushNode(NODE** head, int data);
void AppendNode(NODE** head, int data);
void DeleteNode(NODE** head, int data);
void DeleteList(NODE** head);
void PrintList(NODE** head);
void ReverseList(NODE** head);
