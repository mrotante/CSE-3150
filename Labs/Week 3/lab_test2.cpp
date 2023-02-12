#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"
#include "array_functions.h"

//two new functions, maxDepth & reorder
//other functions are tested in lab_test.cpp

TEST_CASE("Testing new functions") {
    SUBCASE("maxDepth & reorder") {
        //maxDepth
        int* arr1 = {};
        CHECK(maxDepth(arr1, 0) == 0);

        int arr2[] = {-1};
        CHECK(maxDepth(arr2, 1) == 0);

        int arr3[] = {1, -1, -1};
        CHECK(maxDepth(arr3, 3) == 2);

        int arr4[] = {-1, -1, -1, 1, 1};
        CHECK(maxDepth(arr4, 5) == 2);

        int arr5[] = {-1, 1, -1, 1, -1};
        CHECK(maxDepth(arr5, 5) == 0);

        int arr6[] = {1, -1, -1, -1, 1, 1, -1, 1, -1, 1, 1, -1, -1};
        CHECK(maxDepth(arr6, 13) == 3);

        int* y = reorder(arr3, 3, maxDepth(arr3, 3));
        CHECK(y[0] == 1);
        CHECK(y[1] == -1);
        CHECK(y[2] != 1);
        CHECK(y[2] != -1);

        int* z = reorder(arr4, 5, maxDepth(arr4, 5));
        CHECK(z[0] == 1);
        CHECK(z[1] == 1);
        CHECK(z[2] == -1);
        CHECK(z[3] == -1);
    };
}