/*
    readData.c

    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

    By Marina W. & Vanessa M.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readData.h"
#include "set.h"

#define size 50 

void getCollection(Queue q) {
	char buffer[size];
	FILE *fp; 
	Set s = newSet();

	// if cannot find files 
	if((fp = fopen("collection.txt", "r")) == NULL){
    	return;
    }

    // whlie no error occurs while reading data 
    while(fscanf(fp, "%s", buffer) > 0) {
    	enterQueue(q, buffer);
    	insertInto(s, buffer);
    }
    disposeSet(s);
    fclose(fp);
}

void getGraph() {

}