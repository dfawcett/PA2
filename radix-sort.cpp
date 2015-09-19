//============================================================================
// Name        : radix-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of radix sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
#include <tgmath.h>

const int base = 10; 
int digit(int k, int num)
{
	int r; 
	r = num/(int)pow(base, k);
	return r % base;
}

void
RadixSort::sort(int A[], int size)
{
	int d = 10;
  /*
     Complete this function with the implementation of radix sort
     algorithm.
  */
  // int* input = A;
  // long count[256];
  // int shift = 0;
  // int* tmp_array = new int[size];
  // while(shift < 32){
  // 	memset(count, 0, sizeof(count));
  // 	for(int i = 0;  i < size; ++i){
  // 		int bits = (input[i] >> shift) & 255;
  // 		count[bits]++;
  // 	}
  // 	for(int i = 1; i < 256; ++i){
  // 		count[i] += count[i];
  // 	}
  // 	for(int i = size; i >= 0; i--){
  // 		int bits = (input[i] >> shift) & 255;
  // 		count[bits];
  // 		tmp_array[count[bits]] = input[i];
  // 	}
  // 	memcpy(input, tmp_array, size*sizeof(input));
  // 	shift += 8;
  // }
  // delete[] tmp_array;
	int i, j, m;
	int *C = new int[base];
	int *B = new int[size];
	for(m = 0; m < d; m++){
		for(i = 0; i < base; i++) C[i] = 0;
		for(j = 0; j < size; j++) C[digit(m, A[j])]++; 
		for(i = 1; i < base; i++) C[i] += C[i-1];
		for(j = size-1; j >= 0; j--){
			i = C[digit(m, A[j])]--;
			i--;
			B[i] = A[j];
		}
		for (j=0; j<size; j++) A[j] = B[j];
	}
	delete[] B; delete[] C;
}





