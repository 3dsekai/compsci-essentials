//********************************************************
//
// Queue
// File: queue.h
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
void Add(NODE** first, NODE** last, DATA item);
DATA Remove(NODE** first, NODE** last);
DATA Peek(NODE** first);
DATA Find(NODE** first, int id);
BOOL IsEmpty(NODE** first, NODE** last);
void PrintQueue(NODE** first);
void EraseQueue(NODE** first, NODE** last);