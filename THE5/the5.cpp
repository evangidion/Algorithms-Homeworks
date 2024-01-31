#include "the5.h"
// do not add extra libraries here

/*
W: the width of the field
L: the length of the field
partitions: 2D Boolean array for partitions, if a partition of w x l exists then partitions[x][y] is true.
numberOfCalls/numberOfIterations: method specific control parameter
*/


int min(int x, int y, int z) {
    if(x < y && x < z) return x;
    else if(y < x && y < z) return y;
    else return z;
}

int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls){
    *numberOfCalls += 1;
    if(partitions[W][L] == true) return 0;
    int wa = W*L;
    int min1 = W*L;
    int min2 = W*L;
    for(int M = 1; M <= W/2; M++) {
        int x = recursiveMethod(W-M, L, partitions, numberOfCalls) + recursiveMethod(M, L, partitions, numberOfCalls);
        if(x < min1) min1 = x;
    }
    for(int N = 1; N <= L/2; N++) {
        int y = recursiveMethod(W, L-N, partitions, numberOfCalls) + recursiveMethod(W, N, partitions, numberOfCalls);
        if(y < min2) min2 = y;
    }
    
	return min(wa, min1, min2); // this is a dummy return value. YOU SHOULD CHANGE THIS!
}

int memoizationHelper(int W, int L, bool** partitions, int* numberOfCalls, int**& mem) {
    *numberOfCalls += 1;
    if(mem[W][L] < 1000000) return mem[W][L];
    if(partitions[W][L] == true) return mem[W][L] = 0;
    int wa = W*L;
    int min1 = W*L;
    int min2 = W*L;
    for(int M = 1; M <= W/2; M++) {
        int x = memoizationHelper(W-M, L, partitions, numberOfCalls, mem) + memoizationHelper(M, L, partitions, numberOfCalls, mem);
        if(x < min1) min1 = x;
    }
    for(int N = 1; N <= L/2; N++) {
        int y = memoizationHelper(W, L-N, partitions, numberOfCalls, mem) + memoizationHelper(W, N, partitions, numberOfCalls, mem);
        if(y < min2) min2 = y;
    }
    return mem[W][L] = min(wa, min1, min2);
}

int memoizationMethod(int W, int L, bool** partitions, int* numberOfCalls){
    *numberOfCalls += 1;
    int **mem = new int*[W+1];
    for(int i = 0; i <= W; i++) mem[i] = new int[L+1];
    for(int i = 0; i <= W; i++) {
        for(int j = 0; j <= L; j++) mem[i][j] = 1000000;
    }
    int m = memoizationHelper(W, L, partitions, numberOfCalls, mem);
    for(int i = 0; i <= W; i++) delete[] mem[i];
    delete[] mem;
	return m; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}

int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations){
    int **mem = new int*[W+1];
    for(int i = 0; i <= W; i++) mem[i] = new int[L+1];
    for(int i = 0; i <= W; i++) {
        for(int j = 0; j <= L; j++) mem[i][j] = i*j;
    }
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= L; j++) {
            if(partitions[i][j] == true) mem[i][j] = 0;
            else {
                int wa = i*j;
                int min1 = i*j;
                int min2 = i*j;
                for(int M = 1; M <= i; M++) {
                    *numberOfIterations += 1;
                    if(mem[i-M][j] + mem[M][j] < min1) min1 = mem[i-M][j] + mem[M][j];
                }
                for(int N = 1; N <= j; N++) {
                    *numberOfIterations += 1;
                    if(mem[i][j-N] + mem[i][N] < min2) min2 = mem[i][j-N] + mem[i][N];
                }
                mem[i][j] = min(wa, min1, min2);
            }
        }
    }
    int wa2 = mem[W][L];
    for(int i = 0; i <= W; i++) delete[] mem[i];
    delete[] mem;
	return wa2; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}
