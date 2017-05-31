// BSTree.h ... interface to binary search tree ADT

#ifndef BSTREE_H
#define BSTREE_H

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

typedef struct BSTree * BSTNode;

struct BSTree
{
	char * word;
    Node node;
	BSTNode left;
    BSTNode right;
};

// make a new node containing a value
BSTNode newBSTNode(char *, char *);

void BSTreeInfix(BSTNode);

BSTNode insertBSTree(BSTNode, char *, Node);
void printListNode(Node node, FILE * output);
void printTreeNode(BSTNode treeNode, FILE * output);
void disposeTree(BSTNode);

#endif