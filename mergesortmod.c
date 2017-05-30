/*
    mergesortmod.c

    COMP1927 ASSIGNMENT 2 - SIMPLE SEARCH ENGINES

    By Marina W. & Vanessa M.

    Modified mergesort algorithm
    Original written by John Shepherd
*/

#include <stdio.h>
#include <stdlib.h>

#include "mergesortmod.h"


void mergeSort(void * array[], int lo, int hi, int size, int(*first)(const void*,const void*))
{
    int mid = (lo + hi) / 2;

    if(hi <= lo) return;

    mergeSort(array, lo, mid, size, first);
    mergeSort(array, mid + 1, hi, size, first);

    merge(array, lo, mid, hi, size, first);
}

void merge(void * array[], int lo, int mid, int hi, int size, int(*first)(const void*,const void*))
{
    int i, j, k = 0;
    int nitems = hi - lo + 1;

    //Create temporary array
    void ** tmp = malloc(nitems * size);

    i = lo, j = mid + 1; nitems = hi - lo + 1;

    //scan both segements, copying to tmp
    while(i <= mid && j <= hi) {
        if(first(array[i],array[j]))
            tmp[k++] = array[i++];
        else
            tmp[k++] = array[j++];
    }
    //copy items from unfinished segment
    while(i <= mid) tmp[k++] = array[i++];
    while(j <= hi) tmp[k++] = array[j++];

    //cpoy tmp back to main array
    for(i = lo, k = 0; i <= hi; i++, k++)
        array[i] = tmp[k];
    free(tmp);
}
