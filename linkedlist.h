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
void disposeList(Node);

#endif
