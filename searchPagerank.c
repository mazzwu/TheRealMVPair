/*

    searchPagerank.c

    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

    By Marina W. & Vanessa M.

    PART 1 C - Graph structure-based Search Engine

    Given search terms (words) as commandline arguments
    Outputs (to stdout) top 10 pages in descending order of PageRank
    If number matches < 10 output allowed

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "graph.h"
#include "queue.h"
#include "selectionSort.h"
#include "readData.h"
#include "set.h"
#include "linkedlist.h"

//==================== STRUCTS ==============================//

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

//==================== FUNCTION HEADERS =====================//

void checkArg(int argc, char * argv[]);
List newList();
List PRList(List);
void newListNode(char *, List);
void printPRList(List);
void removeRank(char *, List);
void freeNode(rankNode);
int search(char *, char *);
void cleanString(char *);

//==========================================================//

int main(int argc, char * argv[])
{
    //checkArg(argc, argv);

    //convert everthing to normal text
    int convert = 1;
    while(convert != argc) {
        cleanString(argv[convert]);
        convert++;
    }

    List prList = newList();
    assert(prList != NULL);

    PRList(prList);

    int rmv = 1;
    while(rmv != argc) {
        removeRank(argv[rmv], prList);
        rmv++;
    }

    printPRList(prList);

    return EXIT_SUCCESS;
}

//==================== FUNCTIONS ==========================//

void newListNode(char * string, List list)
{
    rankNode newRank = malloc(sizeof(PRnodeRep));
    assert(newRank != NULL);

    newRank->word = strdup(string);

    //List is empty
    if(list->first == NULL) {
        list->first = newRank;
        list->last = newRank;

    } else {
        list->last->next = newRank;
        list->last = newRank;
    }
    list->size++;

    return;
}

//Make a new list
List newList()
{
    //Make the new list
    List newList = malloc(sizeof(struct ListRep));
    assert(newList != NULL);

    newList->first = NULL;
    newList->last = NULL;
    newList->size = 0;

    return newList;
}

//Make a list of pageranks
List PRList(List newList)
{
    char string[1000];

    FILE * fp = fopen("pageRankList.txt", "r");
    assert(fp != NULL);

    while(fscanf(fp, "%s", string) != EOF) {

        if(memcmp(string, "url", 3) == 0) {
            cleanString(string);
            newListNode(string, newList);
        }
    }
    fclose(fp);
    return newList;
}

//Checks if a word exists in the url
int search(char * word, char * url)
{
    FILE * fp;
    fp = fopen("invertedIndex.txt", "r");
    assert(fp != NULL);

    char buffer[1000];

    while(!feof(fp)) {

        fscanf(fp, "%s", buffer);

        //If thee word is in the buffer
        if(strcmp(word, buffer) == 0) {
            fscanf(fp, "%s", buffer);

            //Matching format
            while(memcmp(buffer, "url", 3) == 0) {
                fclose(fp);
                return 1;
            }
        } else {
            fgets(buffer, 1000, (FILE *) fp);
        }
    }
    fclose(fp);
    return 0;
}

void freeNode(rankNode node)
{
    free(node->word);
    free(node->pr);
    free(node);
}

//Filters out the pageranks that we don't need
void removeRank(char * string, List list)
{
    rankNode prev = NULL;
    rankNode curr = list->first;

    int flag = 1;
    while(flag == 1) {

        if(curr == list->last) {

            //Not found -> free memory and remove from list
            if(search(string, curr->word) != 1) {
                list->last = prev;
                freeNode(curr);
            } break;

        //at head of the list
        } else if (curr == list->first) {

            //Adjust node pointers
            prev = curr;
            curr = curr->next;

            //Not found so free memory and remove from list
            if(search(string, prev->word) != 1) {
                freeNode(prev);
                prev = NULL;

                list->first = curr;
            }
        //General cast - in the middle
        } else {

            if(search(string, curr->word) != 1) {

                //Adjust node pointers
                prev->next = curr->next;
                //Free node
                freeNode(curr);
                curr = prev->next;

            } else {
                curr = curr->next;
                prev = prev->next;
            }
        }
    }
    return;
}

//Checks correct usage
/* DOesn't compile for some reason
void checkArg(int argc, char * argv[])
{
    char * searchTerm[argc - 1];

    int i = 1;

    if(argc > 1) {

        while(i < argc) {
            searchTerm[i - 1] = strdup(argv[i]);
            i++;
        }
    } else {
        //printf("USAGE ERROR:\n");
        exit(1);
    }
}
*/

void printPRList(List list)
{
    rankNode curr = list->first;

    while(curr != NULL) {
        printf("%s\n", curr->word);
        curr = curr->next;
    }
}
