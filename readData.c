/*
    readData.c

    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

    By Marina W. & Vanessa M.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readData.h"
#include "linkedlist.h"
#include "set.h"

#define size 500

void cleanString(char * string) {

    //Make lowercase
    int i = 0;

    while(string[i] != '\0') {

        if(isalpha(string[i]) != 0) {
            string[i] = tolower(string[i]);
            i++;

        } else if(isdigit(string[i]) != 0) {
            i++;

        } else {

            int j = i;

            //Skip over punctuation
            while(string[j] != '\0') {
                string[j] = string[j+1];
                j++;
            }
        }
    }
    return;
}

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
    	// no duplicates to be added
    	if(!isElem(s, buffer)){
	    	enterQueue(q, buffer);
	    	insertInto(s, buffer);
    	}
    }
    disposeSet(s);
    fclose(fp);
}

void getGraph(Graph g, Queue q) {

	char * fileName;
	char buffer[size];
	//char temp[size];

	//While the queue is not empty - continue checking for links
	while(!emptyQueue(q)) {

		//Increment -> move to next file
		//leaveQueue -> returns string at the front of the queue
		fileName = leaveQueue(q);

		//Add the .txt suffix to the current file
		strcat(fileName, ".txt");

		FILE * fp;
		if((fp = fopen(fileName, "r")) == NULL)  return;

		//Look for "Section 1" and "end"
		//Not at the end of the file yet
		while((fscanf(fp, "%s", buffer) != EOF) && strcmp(buffer, "#end") != 0) {
			//Look for "start" and "section1"
			if((strcmp(buffer, "#start") != 0) && (strcmp(buffer, "Section-1") != 0)) {
				//add .txt to eliminate duplication
				strcat(buffer, ".txt");
				//Add to the graph
				addEdge(g, fileName, buffer);
			}
		}
		fclose(fp);
		free(fileName);
	}
}

BSTNode getTree(BSTNode treeNode, Queue q)
{
	char * curr;
	char buffer[size];
	char file[size];

	//Iterate through all the files
	while(!emptyQueue(q)) {

		//Move to the end of the queue
		curr = leaveQueue(q);

		sprintf(file, "%s.txt", curr);

		FILE * fp;
		fp = fopen(file, "r");

		//Not at the end of the file yet
		while(strcmp(buffer, "Section-2") != 0) {
			fscanf(fp, "%s", buffer);
		}

		int flag = 1;
		while((strcmp(buffer, "#end") != 0)) {

		    cleanString(buffer);
			//printf("buffer normalise %s\n", buffer);
			cleanString(curr);
			//printf("curr normalise %s\n", curr);

            //If empty tree
			if(flag == 1) {
				treeNode = insertBSTree(treeNode, buffer, curr);
			} else {
                //Add to tree
				insertBSTree(treeNode, buffer, curr);
				flag = 0;
			}

			fscanf(fp, "%s", buffer);
		}
		fclose(fp);
		free(curr);
	}
	return treeNode;
}
