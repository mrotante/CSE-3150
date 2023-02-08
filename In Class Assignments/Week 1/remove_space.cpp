#include "remove_space.h"
#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void print_array(int array[], int length, int k) {
    if(length == 0) {
        cout << "[]\n" << endl;
        return;
    }

    cout << "[";
    for(int i = 0; i < k; i++) {
        cout << array[i] << ", ";
    }
    for(int i = k; i < length - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[length-1] << "]\n" << endl;
}

void ECRemoveSpace(int nums[], int val, int length) {
    cout << "initial array = ";
    print_array(nums, length, 0);

    int start = 0;
    int end = length - 1;

    while(start <= end && end != 0) {
        if(nums[start] == val) {
            swap(nums[start], nums[end]);
            end--;
            continue;
        }
        start++;
    }
    int elements_replaced = length - (end + 1);
    int k = length - elements_replaced;

    cout << "k = " << k << " new array = "; 
    print_array(nums, length, k);
}

int ECRemoveSpaceTest(int nums[], int val, int length)  {
    int start = 0;
    int end = length - 1;
    
    while(start <= end && end != 0) {
        if(nums[start] == val) {
            swap(nums[start], nums[end]);
            end--;
            continue;
        }
        start++;
    }
    int elements_replaced = length - (end + 1);
    int k = length - elements_replaced;
    return k;
}