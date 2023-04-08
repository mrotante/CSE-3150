#ifndef __MATRICES_H__
#define __MATRICES_H__

//MACROS FOR BIGINT FRACTIONS (REPRESENTED BY PAIRS)
#define numerator first
#define denominator second
#define fraction pair

#include <iostream>
#include <vector>
#include "bigint.h"

using namespace std;


struct matrix {
    int rows;
    int cols;

    vector<fraction<bigint, bigint> > data;
};

fraction<bigint, bigint> addBigFraction(fraction<bigint, bigint> f1, fraction<bigint, bigint> f2);
fraction<bigint, bigint> multBigFraction(fraction<bigint, bigint> f1, fraction<bigint, bigint> f2);
fraction<bigint, bigint> reduceFraction(bigint num, bigint den);
void printFraction(fraction<bigint, bigint> f);
matrix multiplyMatrices(matrix a, matrix b);
void printMatrix(matrix m);

#endif