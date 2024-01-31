#include "the2.h"

//You may write your own helper functions here

void swapy(unsigned short* arr, int i, int j, long &swap, double &avg_dist, double &max_dist, double &distance2) {
    unsigned short temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    swap++;
    double distance = (i - j) > 0 ? i - j : j - i;
    if(distance > max_dist) max_dist = distance;
    distance2 += (i - j) > 0 ? i - j : j - i;
    avg_dist = distance2/swap ;
}

void swap2(unsigned short *arr, int i, int j, long &swap) {
    unsigned short temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    swap++;
}

int quickSortClassicalPartition(unsigned short* arr, long &swap, double &avg_dist, double &max_dist, int start, int end, double &distance2) {
    unsigned short x = arr[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j++) {
        if(arr[j] >= x) {
            i++;
            swapy(arr, i, j, swap, avg_dist, max_dist, distance2);
        }
    }
    swapy(arr, i + 1, end, swap, avg_dist, max_dist, distance2);
    return i + 1;
}

int quickSortHoarePartition(unsigned short* arr, long &swap, double &avg_dist, double &max_dist, int start, int end, double &distance2, int size) {
    unsigned short x = arr[start + (size - 1)/2];
    int i = start - 1;
    int j = end + 1;
    while(true) {
        do {
            j--;
        } while(arr[j] < x);
        do {
            i++;
        } while(arr[i] > x);
        if(i < j) swapy(arr, i, j, swap, avg_dist, max_dist, distance2); 
        else return j;
    }
}

void quickSortHelper(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size, int start, int end, double &distance2) {
    if(size > 1) {
        if (!hoare) {
            int p = quickSortClassicalPartition(arr, swap, avg_dist, max_dist, start, end, distance2);
            quickSortHelper(arr, swap, avg_dist, max_dist, hoare, p - start, start, p - 1, distance2);
            quickSortHelper(arr, swap, avg_dist, max_dist, hoare, end - p, p + 1, end, distance2);
        }
        
        else {
            int p = quickSortHoarePartition(arr, swap, avg_dist, max_dist, start, end, distance2, size);
            quickSortHelper(arr, swap, avg_dist, max_dist, hoare, p - start + 1, start, p, distance2);
            quickSortHelper(arr, swap, avg_dist, max_dist, hoare, end - p, p + 1, end, distance2);
        }
    }
}

void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
    //Your code here
	
	double distance2 = 0;
	quickSortHelper(arr, swap, avg_dist, max_dist, hoare, size, 0, size - 1, distance2);
}

void quickSort3Partition(unsigned short *arr, long &swap, long &comparison, int start, int end, int size, int &l, int &r) {
    int i = start;
    int j = start;
    int p = end;
    while(i < p) {
        if(arr[i] > arr[end]) {
            comparison++;
            swap2(arr, i, j, swap);
            i++;
            j++;
        }
        else if(arr[i] == arr[end]) {
            comparison += 2;
            p--;
            swap2(arr, i, p, swap);
        }
        else {
            comparison += 2;
            i++;
        }
    }
    int m = p - j < end - p + 1 ? p - j : end - p + 1;
    for(int c = 1; c <= m; c++) {
        swap2(arr, j + c - 1, end + c - m, swap);
    }
    l = j;
    r = p - j;
}

void quickSort3Helper(unsigned short *arr, long &swap, long &comparison, int size, int start, int end) {
    if(size > 1) {
        int l, r;
        quickSort3Partition(arr, swap, comparison, start, end, size, l, r);
        quickSort3Helper(arr, swap, comparison, l - start, start, l - 1);
        quickSort3Helper(arr, swap, comparison, end - start - (size - r) + 1, start + (size - r), end);
    }
}

void quickSort3(unsigned short *arr, long &swap, long &comparison, int size) {
	
    //Your code here
	quickSort3Helper(arr, swap, comparison, size, 0, size - 1);
}