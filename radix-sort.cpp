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
#include <deque>

using namespace std;

const int base = 10; 
int digit(int k, int num)
{
	int r; 
	r = num/(int)pow(base, k);
	return r % base;
}

deque<int> mergeArr(deque<int> A,deque<int> B){
    deque <int> AB(A.size()+B.size());
    for (int i=B.size()-1; i>=0; i--){
        AB.push_front(B[i]);
    }
    for (int i= 0; i<A.size(); i++){
        AB.push_front(A[i]);
    }
    
    return AB;
}

void radixsort(deque<int>& A, int size){
    int d = 5; //radix sort can sort up to 2^15-1 = 32767
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


void
RadixSort::sort(int A[], int size)
{
    deque<int> positive;
    deque<int> negative;
    
    for (int e=0; e<size; e++){
        if (A[e]<0) {
            negative.push_back(A[e]);
        } else {
            positive.push_back(A[e]);
        }
    }
    
    radixsort(positive,positive.size());
    
    //sorting negative, make it positive and insert inversely
    for (int i=0; i<negative.size();i++){
        negative[i]*=-1;
    }
    radixsort(negative,negative.size());
    
    for (int i=0; i<negative.size();i++){
        negative[i]*=-1;
    }
    
    deque<int> result(size);
    result=mergeArr(negative,positive);
    positive.clear(); positive.shrink_to_fit();
    negative.clear(); negative.shrink_to_fit();
    copy(result.begin(), result.end(),A);
    
  
}





