#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>
#include "vector.h"
#include "doctest.h"
#include <cmath>

using namespace std;

TEST_CASE("Testing cosine distance functions") {
    SUBCASE("vec_magnitude") {
        vector<double> v1;
        v1.push_back(5);
        v1.push_back(5);
        CHECK(vec_magnitude(v1) == sqrt(50));

        vector<double> v2;
        v2.push_back(1);
        v2.push_back(3);
        CHECK(vec_magnitude(v2) == sqrt(10));

        vector<double> v3;
        v3.push_back(2);
        v3.push_back(4);
        v3.push_back(6);
        CHECK(vec_magnitude(v3) == sqrt(56));
    };

    SUBCASE("dot_product") {
        vector<double> v4;
        v4.push_back(1);
        v4.push_back(2);
        v4.push_back(3);

        vector<double> v5;
        v5.push_back(4);
        v5.push_back(-5);
        v5.push_back(6);
        CHECK(dot_product(v4, v5) == 12);

        vector<double> v6;
        v6.push_back(-4);
        v6.push_back(-9);

        vector<double> v7;
        v7.push_back(-1);
        v7.push_back(2);

        CHECK(dot_product(v6, v7) == -14);

        vector<double> v8;
        v8.push_back(1);
        v8.push_back(2);
        v8.push_back(3);

        vector<double> v9;
        v9.push_back(4);
        v9.push_back(5);
        v9.push_back(6);

        CHECK(dot_product(v8, v9) == 32);
    };

    SUBCASE("cosine distance") {
        vector<vector<double> > vectors = readFile("vectors1.txt");
        vector<double> distances;
        double vals[] = {0.161871, 0.161871, 0.225726, 0.225726, 0.387597, 0.387597, 0.532132, 0.532132, 0.653822, 0.653822, 0.84352, 0.84352};

        //all permutations of cosine distances
        for(int i = 0; i < vectors.size(); i++) {
            for(int j = 0; j < vectors.size(); j++) {
                if(i == j) {
                    continue;
                }

                distances.push_back(cos_distance(vectors.at(i), vectors.at(j)));
            }
        }
    
        //sorted by closeness
        sort(distances.begin(), distances.end());

        for(int i = 0; i < distances.size(); i++) {
            CHECK(round(distances.at(i) * 1000.0) / 1000.0 == round(vals[i] * 1000.0) / 1000.0); //rounds to 3 decimal places.
        }
    };
}