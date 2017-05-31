/*
	selectionSort.c

	COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

	By Marina W. & Vanessa M. 

	Modified selection sort algorithm taken from tutorials 
	Original written by John Shepherd
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(void*array[], int N, int(*first)(const void*,const void*)) {
	int i, minValInd;
	void * minVal;

	for(i = 0; i < N; i++) {
	    minValInd = i;
	    minVal = array[i];
	    for(int j = i + 1; j < N; j++)
	    {
	        if (first(array[j], minVal))
	        {
	            minVal = array[j];
	            minValInd = j;
	        }
	    }
	    array[minValInd] = array[i];
	    array[i] = minVal;
	}
}
