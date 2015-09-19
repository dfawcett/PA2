//============================================================================
// Name        : bubble-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class Sort
  */
    for (int k = 1; k < n; k++){
    	bool cont = false;
    	for (int j = 0; j < n - k; j++){
    		if (A[j+1] < A[j]){
    			int tmp = A[j];
    			A[j] = A[j+1];
    			A[j+1] = tmp;
    			cont = true;
    		}
    		if (!cont) break;
    	}
    }
}
