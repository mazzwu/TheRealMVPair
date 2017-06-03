#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BSTree.h"
#include "linkedlist.h"

//Create a new node
Node newNode(char * urlName)
{
    Node new = malloc(sizeof(Node));

    if(new == NULL) printf("NO NEW NODE SADNESS\n");

    new->name = strdup(urlName);
    new->next = NULL;

    return new;
}

//Add node to the front of the list

//FIX THIS

Node addNode(Node first, char * urlName)
{
    Node addNode = newNode(urlName);

    if(first == NULL){
        return addNode;
    } else {

        //Move to the end of the list
        while(first->next != NULL) {
            first = first->next;
        }

        addNode->name = strdup(urlName);
        addNode->next = NULL;
    }

    return addNode;
}

Node nextNode(Node first)
{
    return first->next;
}

char * NodeName(Node first)
{
    return first->name;
}

void disposeList(Node first)
{
    if(first == NULL) return;

    disposeList(first->next);
    free(first->name);
    free(first);
}
