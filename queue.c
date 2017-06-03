// queue.c ... simple Queue of Strings
// Written by John Shepherd, September 2015

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "queue.h"

// Function signatures

Queue newQueue();
void disposeQueue(Queue);
void enterQueue(Queue,char *);
char *leaveQueue(Queue);
int  emptyQueue(Queue);
void showQueue(Queue q);

Node newNode(char *);
static void disposeNode(Node);


// newQueue()
// - create an initially empty Queue
Queue newQueue()
{
	Queue new = malloc(sizeof(QueueRep));
	assert(new != NULL);
	new->front = NULL;
	new->back = NULL;
	new->qSize = 0;
	return new;
}

// disposeQueue(Queue)
// - clean up memory associated with Queue
void disposeQueue(Queue q)
{
	if (q == NULL) return;
	Node next, curr = q->front;
	while (curr != NULL) {
		next = curr->next;
		disposeNode(curr);
		curr = next;
	}
}

// enterQueue(Queue,Str)
// - add Str to back of Queue
void enterQueue(Queue q, char *str)
{
	Node new = newNode(str);
	if (q->front == NULL)
		q->front = q->back = new;
	else {
		// add into list of elems
		q->back->next = new;
		q->back = new;
	}
	q->qSize++;
}

// leaveQueue(Queue)
// - return string at front of Queue
char *leaveQueue(Queue q)
{
	assert (q->front != NULL);
    char *str = q->front->name;
	Node old = q->front;
	q->front = old->next;
	if (q->front == NULL)
		q->back = NULL;
	free(old);
	q->qSize--;
	return str;
}

// emptyQueue(Queue)
// - check whether Queue is empty
int emptyQueue(Queue q)
{
	return (q->front == NULL);
}

// showQueue(Queue)
// - display Queue (for debugging)
void showQueue(Queue q)
{
	Node curr;
	if (q->front == NULL)
		printf("Queue is empty\n");
	else {
		printf("Queue (front-to-back):\n");
		int id = 0;
		curr = q->front;
		while (curr != NULL) {
			printf("[%03d] %s\n", id, curr->name);
			id++;
			curr = curr->next;
		}
	}
}

// Helper functions

static void disposeNode(Node curr)
{
	assert(curr != NULL);
	free(curr->name);
	free(curr);
}
