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

char * normalise(char * badString)
{

	//If there is a trailing newLine -> replace it with null character for end of string
	//Check for extra full stops
	//Copy everything into the temporary string
	//Lowercase all the characters in the temporary string
	//return the nice new string

	//Convert everything into lowercase
	int i = 0;
	int len = strlen(badString);
	for(i = 0; i < len; i++) badString[i] = tolower(badString[i]);
	//Find the newline characters and spaces

	//Strchr - returns pointer to first occurence of char otherwise NULL
	char * tmp;
	tmp = strchr(badString, '\n');
	if(tmp != NULL) * tmp = '\0';

	//Make a temporary string to search for full stops
	char * tmp2 = malloc(sizeof(char) * strlen(badString));

	char * pointer = strchr(badString, '.');
	while(pointer != NULL) {
		strcpy(tmp2, pointer + 1);
		strcpy(pointer, tmp2);
	}
	free(tmp2);

	//badString is now 'normalised';
	return badString;
}


BSTNode getInvertedList(BSTNode treeNode, Queue q) {
	char * fileName;
	char buffer[size];
	char *temp[size];
	int i = 0;

	while(!emptyQueue(q)) {
		//Increment -> move to next file
		//leaveQueue -> returns string at the front of the queue
		fileName = leaveQueue(q);

		//Add the .txt suffix to the current file
		strcat(fileName, ".txt");

		FILE * fp;
		if((fp = fopen(fileName, "r")) == NULL)  return NULL; 

		printf("site 1: %s\n", fileName);
		//Look for "Section 1" and "end"
		//Not at the end of the file yet
		while((fscanf(fp, "%s", buffer) != EOF) && strcmp(buffer, "#end") != 0) {
			//Look for "start" and "section1"
			if((strcmp(buffer, "#start") != 0) && (strcmp(buffer, "Section-1") != 0)) {
				strcat(buffer, ".txt");
				temp[i] = buffer;
				printf("temp:%s\n", temp[i]);
				i++;
			}
		}

		int i=0;
		int j=0;
		int k=0;


		//Look for "Section 2" and "end"
		//Not at the end of the file yet
		while((fscanf(fp, "%s", buffer) != EOF) && strcmp(buffer, "#end") != 0) {

			//Look for "start" and "section2" and "section1" 
			if((strcmp(buffer, "#start") != 0) && (strcmp(buffer, "Section-2") != 0) && (strcmp(buffer, "Section-1"))) {
				// create node
				
		printf("%d site 2: %s\n", i++, buffer);
				Node new = newNode(fileName);
			printf("%d site 3: %s\n", j++, buffer);
				// normalise string and insert into tree. 
				insertBSTree(treeNode, normalise(buffer), new); // !!!!!!!!!!!!!!!!!!!
printf("%d site 4: %s\n", k++, buffer);
			}
		}
		fclose(fp);
		free(fileName);
	}
	return treeNode;
}




