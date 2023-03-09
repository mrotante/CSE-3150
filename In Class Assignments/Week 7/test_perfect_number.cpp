#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "perfect_number.h"
#include "doctest.h"

TEST_CASE("Perfect number test") {
    SUBCASE("small tests") {
        CHECK(isPerfect(0) == false);
        CHECK(isPerfect(1) == false);
        CHECK(isPerfect(2) == false);
        CHECK(isPerfect(6) == true);
        CHECK(isPerfect(28) == true);
    };

    SUBCASE("big test") {
        int cur = 0;
        int perfects[] = {6, 28, 496, 8128};
        for(int i = 0; i < 10000; i++) {
            if(i == perfects[cur]) {
                CHECK(isPerfect(i) == true);
                cur++;
            } else {
                CHECK(isPerfect(i) == false);
            }
        }
    }
}