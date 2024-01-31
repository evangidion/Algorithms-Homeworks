#include "the1.h"


//You can add your own helper functions

void sillySorthelper(int* arr, int start, int end, long &comparison, long &swap, int size, int &num_of_calls) {
    num_of_calls++;
    if(size >= 4) {
        sillySorthelper(arr, start, start + size/2 - 1, comparison, swap, size/2, num_of_calls);
        sillySorthelper(arr, start + size/4, start + size/4 + size/2 - 1, comparison, swap, size/2, num_of_calls);
        sillySorthelper(arr, start + size/2, start + size - 1, comparison, swap, size/2, num_of_calls);
        sillySorthelper(arr, start, start + size/2 - 1, comparison, swap, size/2, num_of_calls);
        sillySorthelper(arr, start + size/4, start +  size/4 + size/2 - 1, comparison, swap, size/2, num_of_calls);
        sillySorthelper(arr, start, start + size/2 - 1, comparison, swap, size/2, num_of_calls);
    }
    else {
        if(size == 2) {
            comparison++;
            if(arr[start] > arr[end]) {
                swap++;
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
            }
        }
        
    }
}

int sillySort(int* arr, long &comparison, long & swap, int size) 
{

    int num_of_calls=1;
	
	//Your code here
	
	sillySorthelper(arr, 0, size-1, comparison, swap, size, num_of_calls);
	
	
	return num_of_calls - 1;
}

void Merge2(int* h, int q1[], int q3[], int size, long& comparison, int start) {
    int i = 0, j = 0, k = start;
    while(i < size/2 && j < size/2) {
        if(q1[i] <= q3[j]) {
            h[k] = q1[i];
            i++;
        }
        else {
            h[k] = q3[j];
            j++;
        }
        comparison++;
        k++;
    }
    while(i < size/2) {
        h[k] = q1[i];
        i++;
        k++;
    } 
    while(j < size/2) {
        h[k] = q3[j];
        j++;
        k++;
    }
}


void Merge(int* h, int q1[], int q3[], int size, long& comparison) {
    int i = 0, j = 0, k = 0;
    while(i < size/4 && j < size/4) {
        if(q1[i] <= q3[j]) {
            h[k] = q1[i];
            i++;
        }
        else {
            h[k] = q3[j];
            j++;
        }
        comparison++;
        k++;
    }
    while(i < size/4) {
        h[k] = q1[i];
        i++;
        k++;
    } 
    while(j < size/4) {
        h[k] = q3[j];
        j++;
        k++;
    }
}

void crossMergeSorthelper(int *arr, int start, int end, long &comparison, int size, int &num_of_calls) {
    num_of_calls++;
    if(size >= 4) {
        crossMergeSorthelper(arr, start, start + size/4 - 1, comparison, size/4, num_of_calls);
        crossMergeSorthelper(arr, start + size/4, start + size/2 - 1, comparison, size/4, num_of_calls);
        crossMergeSorthelper(arr, start + size/2, start + size/2 + size/4 - 1, comparison, size/4, num_of_calls);
        crossMergeSorthelper(arr, start + size*3/4, start + size - 1, comparison, size/4, num_of_calls);
        
        int q1[size/4], q2[size/4], q3[size/4], q4[size/4], h1[size/2], h2[size/2];
        int* h11 = h1;
        int* h22 = h2;
        for(int i = 0; i < size / 4; i++) q1[i] = arr[start + i];
        for(int j = 0; j < size / 4; j++) q2[j] = arr[start + size/4 + j];
        for(int k = 0; k < size / 4; k++) q3[k] = arr[start + size/2 + k];
        for(int z = 0; z < size / 4; z++) q4[z] = arr[start + size*3/4 + z];
        Merge(h11, q1, q3, size, comparison);
        Merge(h22, q2, q4, size, comparison);
        Merge2(arr, h1, h2, size, comparison, start);
        
    }
    else {
        if(size == 2) {
            comparison++;
            if(arr[start] > arr[end]) {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
            }
        }
    }
}

int crossMergeSort(int *arr, long &comparison, int size)
{
	
	int num_of_calls=1;
	
	// Your code here
	
	crossMergeSorthelper(arr, 0, size - 1, comparison, size, num_of_calls);
	
	return num_of_calls - 1;
	
}