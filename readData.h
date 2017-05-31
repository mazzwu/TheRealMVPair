#ifndef READDATA_H
#define READDATA_H

#include "graph.h"
#include "queue.h"
#include "BSTree.h"
#include "linkedlist.h"

void getCollection(Queue q);
void getGraph(Graph g, Queue q);
BSTNode getInvertedList(BSTNode treeNode, Queue q);

#endif