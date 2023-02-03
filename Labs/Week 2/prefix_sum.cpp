#include "prefix_sum.h"
#include <iostream>

//gets the prefix_sum of array of integers up to element last
//i.e. prefix_sum({2,2,2,2}, 2) = 4, prefix_sum({2,2,2,2}, 3) = 6
int prefix_sum(int array[], int last) {
    int sum = 0;

    for(int i = 0; i < last; i++) {
        sum += array[i];
    }
    return sum;
}

bool non_negative_sum(int array[], int length) {
    for(int i = 0; i < length; i++) {
        if(prefix_sum(array, i) < 0) {
            return false;
        }
    }
    return true;
}

bool non_positive_sum(int array[], int length) {
    for(int i = 0; i < length; i++) {
        if(prefix_sum(array, i) > 0) {
            return false;
        }
    }
    return true;
}