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
    int* array = (int*)malloc(sizeof(int)*2*n);

    for(int i = 0; i < n; i++) {
        array[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        array[i+n] = -1;
    }

    return array;
}