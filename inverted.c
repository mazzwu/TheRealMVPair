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

int main(int argc, char * argv[])
{
    Queue q = newQueue();
    getCollection(q);

    BSTNode tree = NULL; 
    tree = getInvertedList(tree, q); 
    if(tree == NULL) {
       return EXIT_FAILURE; // LMAO FIX THIS MAYBE idk if this is how to do it or not 
    }

    disposeQueue(q);
    disposeTree(tree);

    return EXIT_SUCCESS;
}

void printInv(BSTNode treeNode) {

    FILE *fp;

    // checks if file is accessable 
    if((fp = fopen("invertedIndex.txt", "w")) != NULL) {
        // print to file
        BSTreeInfixPrint(treeNode, fp);
        // close file
        fclose(fp);
    }
    return;
}