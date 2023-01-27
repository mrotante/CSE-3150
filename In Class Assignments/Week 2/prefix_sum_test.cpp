#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

//globals for testing
int arr1[] = {2, 2, 2, 2};
int arr2[] = {10, 20, 30, 40, 50};
int arr3[] = {-4, -5, -2, -3};
int arr4[] = {1, 2, 3, 4, -5, -6, 7, 8, 9, -10, 11, 12, 13, 14, 15};
int nums_1[] = {2,-3,3,2};
int nums_2[] = {1,1,-1,-1};
int nums_3[] = {-1,-1,1,1};



TEST_CASE("Testing Prefix Sum functions") {
    SUBCASE("Testing prefix sum function") {
        CHECK(prefix_sum(arr1, 2) == 4);
        CHECK(prefix_sum(arr1, 4) == 8);
        CHECK(prefix_sum(arr2, 3) == 60);
        CHECK(prefix_sum(arr4, 6) == -1);
        CHECK(prefix_sum(nums_1, 2) == -1);
    };

    SUBCASE("Testing non-negative prefix sum function") {
        CHECK(non_negative_sum(nums_1, 4) == false);
        CHECK(non_negative_sum(nums_2, 4) == true);
        CHECK(non_negative_sum(nums_3, 4) == false);
        CHECK(non_negative_sum(arr1, 4) == true);
        CHECK(non_negative_sum(arr4, 15) == false);
        CHECK(non_negative_sum(arr3, 5) == false);
    };

    SUBCASE("Testig non-positive prefix sum function") {
        CHECK(non_positive_sum(nums_1, 4) == false);
        CHECK(non_positive_sum(nums_2, 4) == false);
        CHECK(non_positive_sum(nums_3, 4) == true);
        CHECK(non_positive_sum(arr1, 4) == false);
        CHECK(non_positive_sum(arr4, 15) == false);
        CHECK(non_positive_sum(arr3, 5) == true);
    };
}