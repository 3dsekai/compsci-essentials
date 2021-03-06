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
	FALSE = 0,
	TRUE
} BOOL;

//********************************************************
// structs
//********************************************************
typedef struct Data
{
	char character;
	int id;
} DATA;

typedef struct Node
{
	DATA* data;
	struct Node* next;
} NODE;

//********************************************************
// method declarations
//********************************************************
void Push(NODE** top, DATA item);
DATA Pop(NODE** top);
DATA Peek(NODE** top);
DATA Find(NODE** top, int id);
BOOL IsEmpty(NODE** top);
void PrintStack(NODE** top);
void EraseStack(NODE** top);