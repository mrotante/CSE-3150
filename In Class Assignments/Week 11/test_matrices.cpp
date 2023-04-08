#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrices.h"

//DEFINING FUNCTIONS IN TEST FILE INSTEAD OF LINKING MAIN FILE BECAUSE OF DUPLICATE SYMBOL ERORR
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

TEST_CASE("Bigint fractions functions") {
    SUBCASE("addBigFraction") {
        fraction<bigint, bigint> a (0,0);
        fraction<bigint, bigint> b (0,0);
        fraction<bigint, bigint> c = addBigFraction(a,b);

        CHECK(c.numerator == 0);
        CHECK(c.denominator == 0);

        fraction<bigint, bigint> d (1,2);
        fraction<bigint, bigint> e (3,4);
        fraction<bigint, bigint> f = addBigFraction(d,e);

        CHECK(f.numerator == 5);
        CHECK(f.denominator == 4);

        fraction<bigint, bigint> g (1132,2543);
        fraction<bigint, bigint> h (3652,42345);
        fraction<bigint, bigint> i = addBigFraction(g,h);


        CHECK(i.numerator == 57221576);
        CHECK(i.denominator == 107683335);
    }; 

    SUBCASE("multBigFraction") {
        fraction<bigint, bigint> a (0,0);
        fraction<bigint, bigint> b (0,0);
        fraction<bigint, bigint> c = multBigFraction(a,b);

        CHECK(c.numerator == 0);
        CHECK(c.denominator == 0);

        fraction<bigint, bigint> d (1,2);
        fraction<bigint, bigint> e (3,4);
        fraction<bigint, bigint> f = multBigFraction(d,e);

        CHECK(f.numerator == 3);
        CHECK(f.denominator == 8);

        fraction<bigint, bigint> g (1132,2543);
        fraction<bigint, bigint> h (3652,42345);
        fraction<bigint, bigint> i = multBigFraction(g,h);


        CHECK(i.numerator == 4134064);
        CHECK(i.denominator == 107683335);
    }; 

    SUBCASE("multiplyMatrices") {
        matrix a;
        a.rows = 2;
        a.cols = 2;
        a.data.push_back(fraction<bigint, bigint>(1, 2));
        a.data.push_back(fraction<bigint, bigint>(1, 4));
        a.data.push_back(fraction<bigint, bigint>(2, 3));
        a.data.push_back(fraction<bigint, bigint>(5, 8));

        matrix b;
        b.rows = 2;
        b.cols = 2;
        b.data.push_back(fraction<bigint, bigint>(3, 4));
        b.data.push_back(fraction<bigint, bigint>(2, 5));
        b.data.push_back(fraction<bigint, bigint>(-1, 6));
        b.data.push_back(fraction<bigint, bigint>(4, 9));

        matrix c;
        c.rows = 3;
        c.cols = 3;
        c.data.push_back(fraction<bigint, bigint>(1, 2));
        c.data.push_back(fraction<bigint, bigint>(2, 3));
        c.data.push_back(fraction<bigint, bigint>(-1, 4));
        c.data.push_back(fraction<bigint, bigint>(0, 0));
        c.data.push_back(fraction<bigint, bigint>(1, 1));
        c.data.push_back(fraction<bigint, bigint>(2, 1));
        c.data.push_back(fraction<bigint, bigint>(-3, 5));
        c.data.push_back(fraction<bigint, bigint>(1, 7));
        c.data.push_back(fraction<bigint, bigint>(2, 1));


        matrix d;
        d.rows = 3;
        d.cols = 3;
        d.data.push_back(fraction<bigint, bigint>(1, 1));
        d.data.push_back(fraction<bigint, bigint>(2, 1));
        d.data.push_back(fraction<bigint, bigint>(3, 1));
        d.data.push_back(fraction<bigint, bigint>(4, 1));
        d.data.push_back(fraction<bigint, bigint>(5, 1));
        d.data.push_back(fraction<bigint, bigint>(6, 1));
        d.data.push_back(fraction<bigint, bigint>(7, 1));
        d.data.push_back(fraction<bigint, bigint>(8, 1));
        d.data.push_back(fraction<bigint, bigint>(9, 1));

        matrix y = multiplyMatrices(a,b);
        matrix z = multiplyMatrices(c,d);

        bigint matrix_y_numerators[] {3, 14, 1, 49};
        bigint matrix_y_denominators[] {8, 45, 2, 90};

        bigint matrix_z_numerators[] {13, 7, 7, 0, 0, 0, 102, 16, 18};
        bigint matrix_z_denominators[] {6, 3, 2, 0, 0, 0, 7, 1, 1};

        for(int i = 0; i < y.data.size(); i++) {
            CHECK(y.data.at(i).numerator == matrix_y_numerators[i]);
            CHECK(y.data.at(i).denominator == matrix_y_denominators[i]);
        }

        for(int i = 0; i < z.data.size(); i++) {
            CHECK(z.data.at(i).numerator == matrix_z_numerators[i]);
            CHECK(z.data.at(i).denominator == matrix_z_denominators[i]);
        }
    }; 
}