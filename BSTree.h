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

void BSTreeInfixPrint(BSTNode, FILE *);

BSTNode insertBSTree(BSTNode, char *, char *);
void printListNode(Node node, FILE * output);
void printTreeNode(BSTNode treeNode, FILE * output);
void disposeTree(BSTNode);

//void addList(BSTNode, Node, char *);

void addLinkToList(BSTNode t, Node node, char *p);

#endif
