// BSTree.c ... implementation of binary search tree ADT

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "BSTree.h"
#include "queue.h"
#include "linkedlist.h"

// make a new node containing a value
BSTNode newBSTNode(char * word, char * urlName)
{
	BSTNode newNode = malloc(sizeof(BSTNode));

	newNode->word = strdup(urlName);
    newNode->node = NULL;
	newNode->left = NULL;
	newNode->right = NULL;

    return newNode;
}

//Print to file
void printListNode(Node node, FILE * output)
{
    if(node == NULL) return;

    printListNode(node->next, output);
    fprintf(output, "%s", node->name);
}

//Prints to file
void printTreeNode(BSTNode treeNode, FILE * output)
{
    if(treeNode == NULL) return;

    fprintf(output, "%s", treeNode->word);
    printListNode(treeNode->node, output);
    fprintf(output, "\n");
}

//Prints tree in infix order - modified to print to a file
void BSTreeInfixPrint(BSTNode treeNode, FILE * output)
{
    if(treeNode == NULL) return;

    BSTreeInfixPrint(treeNode->left, output);
    printTreeNode(treeNode, output);
    BSTreeInfixPrint(treeNode->right, output);
}

//Add node to the tree
BSTNode insertBSTree(BSTNode treeNode, char * word, Node nodeVal)
{

    if(treeNode == NULL) return newBSTNode(word, nodeVal->name);

    int cmp = strcmp(word, nodeVal->name);

    if(cmp < 0)
        insertBSTree(treeNode->left, word, nodeVal);
    else if(cmp > 0)
        insertBSTree(treeNode->right, word, nodeVal);
    else
        treeNode->node = nodeVal;

    return treeNode;
}

//Bye bye tree
void disposeTree(BSTNode treeNode)
{
    if(treeNode == NULL) return;

    disposeTree(treeNode->left);
    disposeTree(treeNode->right);

    disposeList(treeNode->node);
}
