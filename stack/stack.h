//********************************************************
//
// Stack
// File: stack.h
//
// Copyright (C) <2021>  <Christopher Tall>
// Licensed under the GPLv3 <https://www.gnu.org/licenses/>.
//
//********************************************************

//********************************************************
// Enumerations
//********************************************************
typedef enum
{
	TRUE,
	FALSE
} BOOL;

//********************************************************
// structs
//********************************************************
typedef struct Node
{
	int data;
	struct Node* next;
} NODE;

//********************************************************
// method declarations
//********************************************************
void Push(NODE** top, int id);
int Pop(NODE** top);
//int Peek();
int Find(NODE** top, int id);
BOOL IsEmpty(NODE** top);
void PrintStack(NODE** top);
void EraseStack(NODE** top);