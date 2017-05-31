#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node * Node;

struct node
{
    char * name;
    Node next;
};

Node newNode(char *);
Node addNode(Node, char *);
Node nextNode(Node);
char * NodeName(Node);
void disposeList(Node);

#endif
