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

void getGraph(Graph g, Queue q)
{
	char * fileName;
	char buffer[size];

	//While the queue is not empty - continue checking for links
	while(!emptyQueue(q)) {

		//Increment -> move to next file
		//leaveQueue -> returns string at the front of the queue
		fileName = leaveQueue(q);

		//Add the .txt suffix to the current file
		strcat(fileName, ".txt");

		printf("%s\n", fileName);

		FILE * fp;
		if((fp = fopen(fileName, "r")) == NULL)  return;

		//Look for "Section 1" and "end"
		//Not at the end of the file yet
		while((fscanf(fp, "%s", buffer) != EOF) && strcmp(buffer, "#end") != 0) {
			//Look for "start" and "section1"
			if((strcmp(buffer, "#start") != 0) && (strcmp(buffer, "Section-1") != 0)) {
				
				//printf("buffer: %s\n", buffer);
				//Add to the graph
				addEdge(g, fileName, buffer);
			}
		}
		fclose(fp);
		free(fileName);
	}
	//showGraph(g,1);
}