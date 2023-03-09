#include <iostream>
#include <numeric>
#include <vector>

#include "perfect_number.h"

using namespace std;

bool isPerfect(int x) {
    if(x <= 1) { //perfect numbers to have divisors excluding themselves
        return false;
    }

    vector<int> v (x-1);
    std::iota(v.begin(), v.end(), 1); // fills vector 1,2,3,...,n-1
    int sum = 0;

    for_each(v.begin(), v.end(), [&x, &sum](const int &d) {
        if(x % d == 0) {
            sum += d;
        }
    });

    return sum == x;
}