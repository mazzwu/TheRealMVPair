#ifndef MERGESORTMOD_H
#define MERGESORTMOD_H

void mergeSort(void * [], int, int, int, int (*) (const void *, const void *));
void merge(void * [], int, int, int, int, int (*less) (const void *, const void *));

#endif
