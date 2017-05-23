/*

    pagerank.c

    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

    By Marina W. & Vanessa M.

    Part 1 A
    Reads data from a given collection of pages in file collection.txt
    Builds graph structure using Adjacency Matrix or List Representation

    Program should output a list of urls in descending order of PageRank values (8sf)
    Print to file named pagerankList.txt
    List includes out links (number of outgoing links) for each url along with PageRank value

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "graph.h"
#include "queue.h"

/*
    #include other supporting files*
    maybe a sorting one? --> needs to print everything in order
*/

//Need a pageRank node structure
typedef struct pageRankNode
{
    //Figure out what to put in the struct

    float rankValue;            //PageRank value
    char * urlName;             //Name of url
    int outLinks;               //Number of out links
} *pageRankNode;

//Function to calculate page rank
void pageRank(Graph g, float d, float diffPR, int maxIterations);

//Print PageRank to a files - pointer to the pageRank value?
void printPR(Graph g, float *PR);

int main(int argc, char * argv[])
{
    //Check argc/argv usage

    //Initial variables
/*
    float d, diffPR;
    int maxIt;

    Queue q = newQueue();
    collect data to input
    Graph g = newGraph(IDK WHAT SIZE YET)

    pageRank(g, d, diffPR, maxIt);


    SAVE TO MEMORY SOMEHOW
*/

    return EXIT_SUCCESS;
}


//=================== FUNCTIONS ====================//

void pageRank(Graph g, float d, float diffPR, int maxIterations)
{
    
}

void printPR(Graph g, float *PR)
{

}
