/*
    mergesortmod.c

    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

    By Marina W. & Vanessa M.

    Modified mergesort algorithm
    Original written by John Shepherd
*/

// functions on ints

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mergesortmod.h"


void mergeSort(void * array[], int lo, int hi, int size, int (*first) (const void *, const void *))
{
    //Base case
    if(hi <= lo) return;

    //Find the midpoint
    int mid = (lo + hi) / 2;

    //Left merge
    mergeSort(array, lo, mid, size, first);
    //Right merge
    mergeSort(array, mid + 1, hi, size, first);
    //Merge
}

void merge(void * array[], int lo, int mid, int hi, int size, int (*first) (const void *, const void *))
{
    int i, j, k, nitems = hi - lo + 1;
    void ** tmp = malloc(nitems * size);

    i = lo;
    j = mid + 1;
    k = 0;

    //scan both segments, copying to tmp
    while(i <= mid && j <= hi) {

        if(first(array[i], array[j]))
            tmp[k++] = array[i++];
        else
            tmp[k++] = array[j++];

    }

        //copy items from the unfinished segment
        while(i <= mid) tmp[k++] = array[i++];
        while(j <= hi) tmp[k++] = array[j++];

        //copy tmp back to main array
        for(i = lo, k = 0; i <= hi; i++, k++)
            array[i] = tmp[k];
        free(tmp);
}
