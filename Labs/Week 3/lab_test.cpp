#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"
#include "array_functions.h"

//globals for testing
int a = 10;
int b = 20;
int c = 30;
int d = 40;
int* w = &a;
int* x = &b;
int* y = &c;
int* z = &d;

int arr1[] = {0, -1, 2, 3};
int arr2[] = {1, 2, 3, 4};
int arr3[] = {-1, -2, -3, -4};
int arr4[] = {0};

int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr6[] = {9, 3, 6, 1, 7, 44, 12, 16};

int arr7[] = {4, 6, 8, 7, 2, 9, 3, 10, 5, 1}; // output to seeded fisher yates scramble of arr5
int arr8[] = {7, 1, 3, 6, 44, 12, 16, 9}; // output to seeded fisher yates scramble of arr6

TEST_CASE("Testing prefix_sum functions") {
    SUBCASE("Non-negative") {
        CHECK(non_negative_sum(arr1, 4) == false);
        CHECK(non_negative_sum(arr2, 4) == true);
        CHECK(non_negative_sum(arr3, 4) == false);
        CHECK(non_negative_sum(arr4, 1) == true);
    };

    SUBCASE("Non-positive") {
        CHECK(non_positive_sum(arr1, 4) == false);
        CHECK(non_positive_sum(arr2, 4) == false);
        CHECK(non_positive_sum(arr3, 4) == true);
        CHECK(non_positive_sum(arr4, 1) == true);
    }
}

TEST_CASE("Testing lab_main functions") {
    SUBCASE("swap") {
        CHECK(a == 10);
        CHECK(b == 20);
        swap(w,x);
        CHECK(a == 20);
        CHECK(b == 10);
        CHECK(c == 30);
        CHECK(d == 40);
        swap(y,z);
        CHECK(c == 40);
        CHECK(d == 30);
    };
    
    SUBCASE("fisher_yates deterministic") {
        fisher_yates(arr5, 10, 3150);
        for(int i = 0; i < 10; i++) {
            CHECK(arr5[i] == arr7[i]);
        }

        fisher_yates(arr6, 8, 3150);
        for(int i = 0; i < 8; i++) {
            CHECK(arr6[i] == arr8[i]);
        }
    };

    SUBCASE("create_array") {
        int* arr9 = create_array(1);
        CHECK(arr9[0] == 1);
        CHECK(arr9[1] == -1);
        CHECK(arr9[2] == -1);
        delete arr9;

        int* arr10 = create_array(100);
        for(int i = 0; i < 201; i++) {
            if(i < 100) {
                CHECK(arr10[i] == 1);
            } else {
                CHECK(arr10[i] == -1);
            }
        }
        delete arr10;
    };
}