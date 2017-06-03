// queue.h ... interface to simple Queue of Strings
// Written by John Shepherd, September 2015

#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

typedef struct QueueRep * Queue;

typedef struct QueueRep {
	Node  front;
	Node  back;
	int qSize;
} QueueRep;

// Function signatures

Queue newQueue();
void disposeQueue(Queue);
void enterQueue(Queue,char *);
char *leaveQueue(Queue);
int  emptyQueue(Queue);
void showQueue(Queue q);

#endif
