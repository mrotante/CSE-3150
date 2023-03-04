#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "vector.h"
#include "doctest.h"
#include <vector>


using namespace std;

TEST_CASE("Testing int_vector constructors") {
    SUBCASE("Base constructor") {
        //base constructor
        int_vector v1;
        CHECK(v1.id == -1);
        CHECK(v1.from == 0);
        CHECK(v1.to == 0);

        v1.id = 0;
        v1.from = 1;
        v1.to = 10;
        CHECK(v1.id == 0);
        CHECK(v1.from == 1);
        CHECK(v1.to == 10);
    };

    SUBCASE("Copy constructor") {
        int_vector v2;
        v2.id = 5;
        v2.from = 10;
        v2.to = 50;

        CHECK(v2.id == 5);
        CHECK(v2.from == 10);
        CHECK(v2.to == 50);

        int_vector v3{v2};
        CHECK(v3.id == v2.id);
        CHECK(v3.from == v2.from);
        CHECK(v3.to == v2.to);

        int_vector v4;
        int_vector v5{v4};

        CHECK(v4.id == v5.id);
        CHECK(v4.id == -1);

        CHECK(v4.from == v5.from);
        CHECK(v4.from == 0);

        CHECK(v4.to == v5.to);
        CHECK(v4.from == 0);
    };

    SUBCASE("Reading from files") {
        vector<int_vector> vectors1 = readFile("vector_1.txt");
        int vectors1_froms[] = {1, 1, 1, 2, -5, 9};
        int vectors1_tos[] = {2,3,4,7,2001,11};

        vector<int_vector> vectors2 = readFile("vector_2.txt");
        int vectors2_froms[] = {2, 5, -1, 3};
        int vectors2_tos[] = {4, 10, 46, 66};

        vector<int_vector> vectors3 = readFile("vector_3.txt"); //empty

        //testing vectors1
        for(int i = 0; i < vectors1.size(); i++) {
            CHECK(vectors1.at(i).to == vectors1_tos[i]);
            CHECK(vectors1.at(i).from == vectors1_froms[i]);
        }

        //testing vectors2
        for(int i = 0; i < vectors2.size(); i++) {
            CHECK(vectors2.at(i).to == vectors2_tos[i]);
            CHECK(vectors2.at(i).from == vectors2_froms[i]);
        }

        CHECK(vectors3.size() == 0);
    }
}