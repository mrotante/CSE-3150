#include <iostream>
#include <random>
#include "array_functions.h"
#include "prefix_sum.h"

using namespace std;

int main() {
    int runs;
    int n;
    int nonPos = 0;
    int nonNeg = 0;

    cout << "Enter the number of runs" << endl;
    cin >> runs;
    cout << "Enter a value for n" << endl;
    cin >> n;

    for(int i = 0; i < runs; i++) {
        int* arr = create_array(n);
        fisher_yates(arr, 2*n, rand());
        if(non_negative_sum(arr, 2*n)) {
            nonNeg++;
        } if(non_positive_sum(arr, 2*n)) {
            nonPos++;
        }
        delete arr;
    }

    cout << "Non Negative: " << nonNeg << " or " << ((float)nonNeg / (float)runs)*100 << "%" << endl;
    cout << "Non Positive: " << nonPos << " or " << ((float)nonPos / (float)runs)*100 << "%" << endl;
    
}