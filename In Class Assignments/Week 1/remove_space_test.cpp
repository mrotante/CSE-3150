#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "remove_space.h"

TEST_CASE("Testing remove_space.h functions") {
    SUBCASE("Testing ECRemoveSpaceTest") {
        int nums1[] = {3, 2, 2, 3}; //val = 3
        int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2}; //val = 2
        int nums3[] = {6, 4, 6, 4, 6, 4, 6, 4}; //val = 4
        int nums4[] = {1, 1, 1, 1, 2, 2, 2, 2}; //val = 2
        int nums5[] = {2, 2, 2, 2, 1, 1, 1, 1}; //val = 2
        int nums6[] = {1}; //val = 1
        int nums7[] = {}; // val = 1

        CHECK(ECRemoveSpaceTest(nums1, 3, 4) == 2);
        CHECK(ECRemoveSpaceTest(nums2, 2, 8) == 5);
        CHECK(ECRemoveSpaceTest(nums3, 4, 8) == 4);
        CHECK(ECRemoveSpaceTest(nums4, 2, 8) == 4);
        CHECK(ECRemoveSpaceTest(nums5, 2, 8) == 4);
        CHECK(ECRemoveSpaceTest(nums6, 1, 1) == 1);
        CHECK(ECRemoveSpaceTest(nums7, 1, 0) == 0);
    };

    SUBCASE("Testing swap function") {
        int a = 10;
        int b = 20;
        int c = 30;
        int d = 40;
        int* w = &a;
        int* x = &b;
        int* y = &c;
        int* z = &d;

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

    SUBCASE("Testing ECRemoveSpace (print)") {
        int nums1[] = {3, 2, 2, 3}; //val = 3
        int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2}; //val = 2
        int nums3[] = {6, 4, 6, 4, 6, 4, 6, 4}; //val = 4
        int nums4[] = {1, 1, 1, 1, 2, 2, 2, 2}; //val = 2
        int nums5[] = {2, 2, 2, 2, 1, 1, 1, 1}; //val = 2
        int nums6[] = {1}; //val = 1
        int nums7[] = {}; // val = 1

        ECRemoveSpace(nums1, 3, 4);
        ECRemoveSpace(nums2, 2, 8);
        ECRemoveSpace(nums3, 4, 8);
        ECRemoveSpace(nums4, 2, 8);
        ECRemoveSpace(nums5, 2, 8);
        ECRemoveSpace(nums6, 1, 1);
        ECRemoveSpace(nums7, 1, 0);
    }
}