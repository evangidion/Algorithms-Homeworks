#include "the4.h"

int max(int x, int y) {
    return x > y ? x : y;
}

int recursive_sln(int i, int*& arr, int &number_of_calls){ //direct recursive
    number_of_calls+=1;

    //your code here
    
    int a,b;
    if(i == 0) return arr[0];
    if(i == 1) return arr[0] > arr[1] ? arr[0] : arr[1];
    if(i == 2) {
        int m = arr[0];
        m = max(m, arr[1]);
        m = max(m, arr[2]);
        return m;
    }
    
    a = recursive_sln(i - 3, arr, number_of_calls) + arr[i];
    b = recursive_sln(i - 1, arr, number_of_calls);

    return a > b ? a : b; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int memoization_sln(int i, int*& arr, int*& mem){ //memoization

    //your code here
    
    if(mem[i] > -1) return mem[i];
    if(i == 0) {
        mem[i] = arr[0];
        return mem[i];
    }
    if(i == 1) {
        mem[0] = arr[0];
        mem[i] = arr[0] > arr[1] ? arr[0] : arr[1];
        return mem[i];
    }
    if(i == 2) {
        mem[0] = arr[0];
        mem[1] = arr[0] > arr[1] ? arr[0] : arr[1];
        int m = arr[0];
        m = max(m, arr[1]);
        m = max(m, arr[2]);
        mem[i] = m;
        return mem[i];
    }
    mem[i] = max(memoization_sln(i - 3, arr, mem) + arr[i], memoization_sln(i - 1, arr, mem));

    return mem[i]; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int dp_sln(int size, int*& arr, int*& mem){ //dynamic programming

    //your code here
    
    if(size == 1) return mem[0] = arr[0];
    if(size == 2) {
        mem[0] = arr[0];
        return mem[1] = arr[0] > arr[1] ? arr[0] : arr[1];
    }
    if(size == 3) {
        mem[0] = arr[0];
        mem[1] = arr[0] > arr[1] ? arr[0] : arr[1];
        int m = arr[0];
        m = max(m, arr[1]);
        m = max(m, arr[2]);
        return mem[2] = m;
    }
    mem[0] = arr[0];
    mem[1] = arr[0] > arr[1] ? arr[0] : arr[1];
    int m = arr[0];
    m = max(m, arr[1]);
    m = max(m, arr[2]);
    mem[2] = m;
    for(int i = 3; i < size; i++) {
        mem[i] = max(mem[i - 3] + arr[i], mem[i - 1]);
    }

    return mem[size - 1]; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}

