#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node * Node;

struct node
{
    char * name;
    Node next;
};

//Structs used for searchPagerank

typedef struct PRnodeRep * rankNode;

struct PRnodeRep
{
    char * word;
    char * pr;
    rankNode next;
} PRnodeRep;

typedef struct ListRep * List;

struct ListRep
{
    int size;
    rankNode first;
    rankNode last;
} ListRep;

void checkArg(int argc, char * argv[]);

Node newNode(char *);
Node addNode(Node, char *);
Node nextNode(Node);
char * NodeName(Node);
void disposeList(Node);

//Used in searchPagerank
List newList();
List PRList(List);
void newListNode(char *, List);
void printPRList(List);
void removeRank(char *, List);
void freeNode(rankNode);
int search(char *, char *);
void cleanString(char *);


#endif
