/*
    inverted.c
    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES
    By Marina W. & Vanessa M.
    PART 1 B
    Reads data from a given collection of pages in collection.txt
    Generates an "inverted index" that provides a list (set) of urls for every word in a given colleciton of pages
    Need to "normalise" words by removing leading & trailing spaces
        and converting all characters to lowercase before inserting words into index
    In each list (set) duplicates are not allowed.
    List is ordered in asceding alphabetical order
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BSTree.h"
#include "graph.h"
#include "queue.h"
#include "readData.h"

void printInv(BSTNode treeNode);

int main(int argc, char * argv[])
{
    Queue q = newQueue();

    getCollection(q);
    printf("HELLO\n");

    //Start a new tree
    BSTNode tree = NULL;

    printf("ARE YOU HERE\n");
    tree = getTree(tree, q);

    printf("IS IT ME\n");

    printInv(tree);

    printf("OMG\n");

    disposeQueue(q);

    printf("IS IT HERE\n");

    disposeTree(tree);

    printf("FOR FUCKS SAKE\n");

    return EXIT_SUCCESS;
}

void printInv(BSTNode treeNode)
{
    //Print the tree to stdout

    FILE * fp;
    if((fp = fopen("invertedIndex.txt", "w")) != NULL) {
        BSTreeInfixPrint(treeNode, stdout);
        fclose(fp);
    }
}
