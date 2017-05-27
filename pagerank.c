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

    Read web pages from the collection in file collection.txt
    and build a graph structure using Adjacency List Representation

    Queue q = newQueue();
    collect data to input
    Graph g = newGraph(IDK WHAT SIZE YET)

    pageRank(g, d, diffPR, maxIt);

    Program should output a list of urls in descending order of PageRank values (8sf)
    Print to file named pagerankList.txt
    List includes out links (number of outgoing links) for each url along with PageRank value

    SAVE TO MEMORY SOMEHOW
*/

    return EXIT_SUCCESS;
}


//=================== FUNCTIONS ====================//

//Calculates the page rank
void pageRank(Graph g, float d, float diffPR, int maxIterations)
{
    //Need to create 2 arrays -> one of old page rank, one for new
        //Maybe not array but need to store somehow -> actually maybe int is good enough

        //calculate difference between old and new pageRank

    //Used for iterating loops
    int i, j, iteration = 0;

    //Old pageRank
    int oldPR = 0;

    //Number of urls in the collection
    int N = nVertices(g);

    float sum = 0;
    float diff = diffPR; //to enter the while loop

    //Array to hold the new pageranks
    float PR[nVertices(g)];

    //For each url in the collection - assign default rank
    for(i = 0; i < N; i++) PR[i] = 1 / N;

    //iteration = 0; - for reference only
    //diff = diffPR - for reference only, enters this loop

    while(iteration < maxIterations && diff >= diffPR) {
        //increment interation - grab next url
        iteration++;
        //Reset diff to zero
        diff = 0;

        //Do the maths
        //1. Save old pagerank for later comparison
        //2. If pages are connected -> add pagerank to the overall sum
        //3. Do the final pagerank algorithm

        i = 0;
        //Go through every url
        for(i = 0; i < N; i++) {
            //Save the old pagerank/ - needed for final algorithm
            oldPR = PR[i];
            //Reset the sum value for new calculation
            sum = 0;

            //Go through every page
            for(j = 0; j < N; j++) {
                //Find ones that are connected and add to the pageRank sum
                //Use isConnected from graph.c
                if(isConnected(g, vertexName(g, j), vertexName (g, i)))
                //Add the edges to the running sum
                    sum += PR[j] / nEdges(g, i);
            }

            //Do the final pageRank algorithm
            PR[i] = (1 - d) / N + (d * sum);

            //fabs - absolute value
            diff += fabs(PR[i] - oldPR);
        }
    }
    //Print to a file (WRITE FUNCTION FOR THIS)
}

//Prints all the pageRanks from function to an output file
void printPR(Graph g, float * PR)
{
    //Make an array for the pageranks
        //Make the nodes for each pageRank -> initalise to struct EXIT_SUCCESS

    //Sort the nodes by pagerank value

    //Do the file pointer stuff :P
        //Check not null -> print values, print to file -> free things -> close file
}
