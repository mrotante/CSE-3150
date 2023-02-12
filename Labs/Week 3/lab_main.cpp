#include <iostream>
#include <random>
#include "array_functions.h"
#include "prefix_sum.h"

using namespace std;

int main() {
    int runs;
    int n;

    cout << "Enter the number of runs" << endl;
    cin >> runs;
    cout << "Enter a value for n" << endl;
    cin >> n;

    for(int i = 0; i < runs; i++) {
        int* arr = create_array(n);
        fisher_yates(arr, (2*n)+1, rand());
        int* y = reorder(arr, (2*n)+1, maxDepth(arr, (2*n)+1));
        cout << "Original List: "; 
        print_array(arr, (2*n)+1);
        cout << "Reordered (balanced) list: ";
        print_array(y, 2*n);
        cout << endl;
        delete arr;
    }

}