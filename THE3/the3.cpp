#include "the3.h"

// do not add extra libraries here


/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
    
    you can use ceil function from cmath
    
*/

void countSort(std::string arr[], bool ascending, int n, int l, long x, int& c) {
    c++;
    int a = pow(26,l);
    int* C = new int[a]{0};
    std::string* B = new std::string[n];
    if(ascending) {
        for(int i = 0; i < n; i++) {
            long temp = 0;
            for(int j = 0; j < arr[i].length(); j++) temp += (long(arr[i][j]) - 65) * pow(26, arr[i].length() - 1 - j);
            C[(temp/x)%a]++;
            c++;
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            long temp = 0;
            for(int j = 0; j < arr[i].length(); j++) temp += (long(arr[i][j]) - 65) * pow(26, arr[i].length() - 1 - j);
            C[a - (temp/x) % a - 1]++;
            c++;
        }
    }
    for(int i = 1; i < a; i++) {
        C[i] += C[i - 1];
        c++;
    }
    if(ascending) {
        for(int i = n - 1; i >= 0; i--) {
            long temp = 0;
            for(int j = 0; j < arr[i].length(); j++) temp += (long(arr[i][j]) - 65) * pow(26, arr[i].length() - 1 - j);
            B[C[(temp/x) % a] - 1] = arr[i];
            C[(temp/x) % a]--;
            c++;
        }
    }
    else {
        for(int i = n - 1; i >= 0; i--) {
            long temp = 0;
            for(int j = 0; j < arr[i].length(); j++) temp += (long(arr[i][j]) - 65) * pow(26, arr[i].length() - 1 - j);
            B[C[a - (temp/x) % a - 1]-1] = arr[i];
            C[a - (temp/x) % a - 1]--;
            c++;
        }
    }
    for(int i = 0; i < n; i++) {
        arr[i] = B[i];
        c++;
    }
    delete[] C;
    delete[] B;
    
}

int radixSort(std::string arr[], bool ascending, int n, int l){
    
    int c = 0;
    long x = 1;
    for(int i = 0; i < ceil(arr[i].length()/l); i++) {
        countSort(arr, ascending, n, l, x, c);
        x *= pow(26,l);
    }
    
    return c;
    
}
