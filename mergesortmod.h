#ifndef MERGESORTMOD_H
#define MERGESORTMOD_H

void mergeSort(void * array[], int lo, int hi, int size, int(*first)(const void*,const void*));
void merge(void * array[], int lo, int hi, int mid, int size, int(*first)(const void*,const void*));

#endif
