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


void showLinkNode(Node node, FILE * stream){
    if (node == NULL) return;
    //printf(" %s", l->pageName);
    showLinkNode(node->next, stream);
    fprintf(stream, " %s", node->name);
}

// display BSTree root node
void showBSTreeNode(BSTNode treeNode, FILE *stream)
{
    if (treeNode == NULL) return;
    fprintf(stream, "%s", treeNode->word);
    //printf("\n%s", t->word);
    showLinkNode(treeNode->node, stream);
    fprintf(stream, "\n");
}

// print values in infix order
void BSTreeInfixPrint(BSTNode treeNode, FILE *stream)
{
    if (treeNode == NULL) return;
    BSTreeInfixPrint(treeNode->left, stream);
    showBSTreeNode(treeNode, stream);
    BSTreeInfixPrint(treeNode->right, stream);
}


// insert a new value into a BSTree
BSTNode insertBSTree(BSTNode t, char *v, char *p)
{
    if (t == NULL)
	return newBSTNode(v, p);
    else if (strcmp(v, t->word) < 0)
	t->left = insertBSTree(t->left, v, p);
    else if (strcmp(v, t->word) > 0)
	t->right = insertBSTree(t->right, v, p);
    else // (v == t->value)
	addLinkToList(t, t->node, p);
    /* don't insert duplicates */;
    return t;
}

//adds item to the link list in the BST tree (per node)
//and ensure that it is sorted so that it prints
//nicely when ./inverted is run
void addLinkToList(BSTNode t, Node l, char *p){
    if (l == NULL)
	t->node = newNode(p);
    else{
	if (strcmp(l->name, p) == 0) return;
	if (strcmp(l->name, p) < 0){
	    Node nn = newNode(p);
	    nn->next = l;
	    t->node = nn;
	    return;
	}
	while (l->next!=NULL){
	    if (strcmp(l->next->name, p) == 0) return;

	    if ((strcmp(l->name, p) > 0) && (strcmp(l->next->name, p) < 0)){
		Node nn = newNode(p);
		nn->next = l->next;
		l->next = nn;
		return;
	    }
	    l = l->next;
	}
	Node nn = newNode(p);
	l->next = nn;
    }
}

/*
//Add node to the tree
BSTNode insertBSTree(BSTNode treeNode, char * word, char * page)
{
	if(treeNode == NULL) return newBSTNode(word, page);

	//int cmp = strcmp(word, treeNode->word);
	if(strcmp(word, treeNode->word) < 0) {
		treeNode->left = insertBSTree(treeNode->left, word, page);
	} else if (strcmp(word, treeNode->word) > 0) {
		treeNode->right = insertBSTree(treeNode->right, word, page);
	} else {
		addList(treeNode, treeNode->node, page);
	}

	printf("made it out of insertBSTree\n");

	return treeNode;
}

void addList(BSTNode treeNode, Node node, char * page)
{
	if (node == NULL)
	treeNode->node = newNode(page);
    else{
	if (strcmp(node->name, page) == 0) return;
	if (strcmp(node->name, page) < 0){
	    Node new = newNode(page);
	    new->next = node;
	    treeNode->node = new;
	    return;
	}
	while (node->next!=NULL){
	    if (strcmp(node->next->name, page) == 0) return;

	    if ((strcmp(node->name, page) > 0) && (strcmp(node->next->name, page) < 0)){
		Node new = newNode(page);
		new->next = node->next;
		node->next = new;
		return;
	    }
	    node = node->next;
	}
	Node new = newNode(page);
	node->next = new;
    }
}

//Prints tree in infix order - modified to print to a file
void BSTreeInfixPrint(BSTNode treeNode, FILE * output)
{
    if(treeNode == NULL) return;

    BSTreeInfixPrint(treeNode->left, output);
    printTreeNode(treeNode, output);
    BSTreeInfixPrint(treeNode->right, output);
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

*/

//Bye bye tree
void disposeTree(BSTNode treeNode)
{
    if(treeNode == NULL) return;

    disposeTree(treeNode->left);
    disposeTree(treeNode->right);

    disposeList(treeNode->node);
}
