/*



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main(void) {

	array[5] = {fish1, fish2, hello, merp, hah};

	selectionSort(array, 5, compareOutgoingEdge);
	selectionSort(array, 5, comparePageRank);

	for(int i = 0; i < 5, i++){
		printf("%s, ", array[i]);
	}

	printf("\n");

	return EXIT_SUCCESS;
} */

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
