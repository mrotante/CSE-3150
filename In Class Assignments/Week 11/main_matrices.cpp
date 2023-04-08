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

int main() {
    matrix a;
    a.rows = 2;
    a.cols = 2;
    a.data.push_back(fraction<bigint, bigint> (1, 2));
    a.data.push_back(fraction<bigint, bigint> (1, 4));
    a.data.push_back(fraction<bigint, bigint> (2, 3));
    a.data.push_back(fraction<bigint, bigint> (5, 8));


    matrix b;
    b.rows = 2;
    b.cols = 2;
    b.data.push_back(fraction<bigint, bigint> (2, 5));
    b.data.push_back(fraction<bigint, bigint> (1, 9));
    b.data.push_back(fraction<bigint, bigint> (2, 5));
    b.data.push_back(fraction<bigint, bigint> (1, 2));

    matrix c = multiplyMatrices(a, b);

    matrix d;
    d.rows = 4;
    d.cols = 4;
    d.data.push_back(fraction<bigint, bigint> (24, 51));
    d.data.push_back(fraction<bigint, bigint> (76, 99));
    d.data.push_back(fraction<bigint, bigint> (1, 66));
    d.data.push_back(fraction<bigint, bigint> (43, 512));
    d.data.push_back(fraction<bigint, bigint> (245, 5143));
    d.data.push_back(fraction<bigint, bigint> (7, 101));
    d.data.push_back(fraction<bigint, bigint> (2, 663));
    d.data.push_back(fraction<bigint, bigint> (431, 51233));
    d.data.push_back(fraction<bigint, bigint> (1, 2));
    d.data.push_back(fraction<bigint, bigint> (3, 949));
    d.data.push_back(fraction<bigint, bigint> (2, 3));
    d.data.push_back(fraction<bigint, bigint> (444444, 111111111));
    d.data.push_back(fraction<bigint, bigint> (2134, 7345));
    d.data.push_back(fraction<bigint, bigint> (432, 756754));
    d.data.push_back(fraction<bigint, bigint> (1, 22));
    d.data.push_back(fraction<bigint, bigint> (432, 657567));

    matrix e (d); 

    matrix f = multiplyMatrices(d, e);

    cout << "MATRIX A :" << endl;
    printMatrix(a);

    cout << "\nMATRIX B : " << endl;
    printMatrix(b);

    cout << "\nAxB :" << endl;
    printMatrix(c);

    cout << "\nMATRIX D :" << endl;
    printMatrix(d);

    cout << "\nMATRIX E : " << endl;
    printMatrix(e);

    cout << "\nDxE :" << endl;
    printMatrix(f);
}