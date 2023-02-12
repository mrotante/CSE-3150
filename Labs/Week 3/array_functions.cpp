#include <iostream>
#include <random>
#include "array_functions.h"
#include "prefix_sum.h"

using namespace std;

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void print_array(int array[], int length) {
    for(int i = 0; i < length - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[length-1] << endl;
}

void fisher_yates(int array[], int length, int seed) {
    srand(seed);
    for(int i = length - 1; i > 1; i--) {
        int j = rand() % i;
        swap(array[i], array[j]);
    }
}

int* create_array(int n) {
    int* array = (int*)malloc(sizeof(int)*((2*n)+1));

    for(int i = 0; i < n; i++) {
        array[i] = 1;
    }

    for(int i = 0; i < n+1; i++) {
        array[i+n] = -1;
    }

    return array;
}

int maxDepth(int array[], int length) { //returns index of first occurence of max depth
    int sum = 0;
    int best = 0;
    int index = 0;

    for(int i = 0; i < length; i++) {
        sum += array[i];
        if(sum < best) {
            best = sum;
            index = i;
        }
    }
    return index;
}

int* reorder(int array[], int length, int index) {
    if(length == 0) {
        return NULL;
    }
    int* new_array = (int*)malloc(sizeof(int)*(length-1));
    int j = 0;
    for(int i = index+1; i < length; i++) {
        new_array[j++] = array[i];
    }

    for(int i = 0; i < index; i++) {
        new_array[j++] = array[i];
    }

    return new_array;
}