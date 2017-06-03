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

		printf("q->Size is %d\n", q->qSize);
		//Add the .txt buffer
		//strcat(file, ".txt");
		sprintf(file, "%s.txt", curr);

		FILE * fp;
		fp = fopen(file, "r");

		//Not at the end of the file yet
		while(strcmp(buffer, "Section-2") != 0) {
			fscanf(fp, "%s", buffer);
		}

		int flag = 1;
		while((strcmp(buffer, "#end") != 0)) {

			normalise(buffer);
			printf("buffer normalise %s\n", buffer);
			normalise(curr);
			printf("curr normalise %s\n", curr);

			if(flag == 1) {
				treeNode = insertBSTree(treeNode, buffer, curr);
			} else {
				insertBSTree(treeNode, buffer, curr);
				flag = 0;
			}

			fscanf(fp, "%s", buffer);
		}
		fclose(fp);
		printf("ARE YOU DYING HERE\n");

		free(curr);
		printf("WHAT ABOUT HERE\n");
	}

	printf("MADE IT OUT OF getTree \n");
	return treeNode;
}

char * normalise (char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++)  //lowercase the string
	s[i] = tolower(s[i]);
    size_t sizes;
    char *end;

    sizes = strlen(s);  //grab info we need

    if (!size)
	return s;

    end = s + size - 1; //being to remove trailing and leading spaces
    while ((end >= s && isspace(*end))  || (end >= s && !isalnum(*end)))
	end--;
    *(end + 1) = '\0';
    //also remove trailing and leading punctuation
    while ((*s && isspace(*s)) || (*s && !isalnum(*s)))
	s++;

	return s;
}

/*

void normalise(char * string) {

    int i = 0;
	int j = 0;

    for (i = 0; string[i] != '\0'; i++) {

        if (!isalpha(string[i])) {
			for(j = i; string[j] != '\0'; j++) {
				string[j] = string[j + 1];
			}
		} else if(isupper(string[i])) {
			string[i] = tolower(string[i]);
		}
	}
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
*/
