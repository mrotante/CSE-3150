#include "matrices.h"

fraction<bigint, bigint> reduceFraction(bigint num, bigint den) {
    bigint gcd = big_gcd(num, den);
    if(gcd > (bigint)1) {
        num /= gcd;
        den /= gcd;
    }

    return fraction<bigint, bigint> (num, den);
}

fraction<bigint, bigint> addBigFraction(fraction<bigint, bigint> f1, fraction<bigint, bigint> f2) {
    bigint num = f1.numerator*f2.denominator + f1.denominator*f2.numerator;
    bigint den = f1.denominator*f2.denominator;
    return reduceFraction(num, den);
}

fraction<bigint, bigint> multBigFraction(fraction<bigint, bigint> f1, fraction<bigint, bigint> f2) {
    bigint num = f1.numerator * f2.numerator;
    bigint den = f1.denominator * f2.denominator;
    return reduceFraction(num, den);
}

void printFraction(fraction<bigint, bigint> f) {
    cout << "(" << f.numerator << "/" << f.denominator << ")";
}

matrix multiplyMatrices(matrix a, matrix b) {
    assert(a.cols == b.rows);

    matrix result;
    result.rows = a.rows;
    result.cols = b.cols;

    for (int i = 0; i < result.rows * result.cols; i++) {
        result.data.push_back(fraction<bigint, bigint>(0, 1));
    }

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i * result.cols + j] = addBigFraction(
                    result.data[i * result.cols + j],
                    multBigFraction(a.data[i * a.cols + k], b.data[k * b.cols + j])
                );
            }
        }
    }

    return result;
}

void printMatrix(matrix m) {
    for(int i = 0; i < m.data.size(); i++) {
        printFraction(m.data.at(i));

        if((i+1) % m.cols == 0) {
            cout << '\n';
        } else {
            cout << " ";
        }
    }
}