#include "the0.h"

void insertionSort(int* arr, long &comparison, long & swap, int size) 
{
    
    //Your Code Here
    int i = 1;
    while(i < size) {
        int x = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            swap++;
            comparison++;
            j--;
        }
        comparison++;
        arr[j + 1] = x;
        i++;
    }
    
}