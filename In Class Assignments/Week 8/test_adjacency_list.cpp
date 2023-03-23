#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "graph.h"

TEST_CASE("adjacency list tests") {
    SUBCASE("data/lists.txt") {
        char filepath[] = "data/lists.txt";
        std::vector<std::vector<int> > graph = rFile(filepath);

        CHECK(graph.size() == 0);
    };

    SUBCASE("data/lists2.txt") {
        char filepath[] = "data/lists2.txt";
        std::vector<std::vector<int> > graph = rFile(filepath);

        CHECK(graph.size() == 3);
        CHECK(graph.at(0).size() == 2);
        CHECK(graph.at(1).size() == 4);
        CHECK(graph.at(2).size() == 1);
    }
    
    SUBCASE("data/lists1.txt") {
        char filepath[] = "data/lists1.txt";
        std::vector<std::vector<int> > graph = rFile(filepath);

        CHECK(graph.size() == 4);
        for(int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph.at(i).size(); j++) {
                if(i == 0) {
                    if(j == 0) {
                        CHECK(graph.at(i).at(j) == 1);
                    } else if(j == 1) {
                        CHECK(graph.at(i).at(j) == 2);
                    } else if(j == 2) {
                        CHECK(graph.at(i).at(j) == 3);
                    }
                } else if(i == 1) {
                    if(j == 0) {
                        CHECK(graph.at(i).at(j) == 2);
                    } else if(j == 1) {
                        CHECK(graph.at(i).at(j) == 3);
                    }
                } else if(i == 2) {
                    if(j == 0) {
                        CHECK(graph.at(i).at(j) == 3);
                    } else if(j == 1) {
                        CHECK(graph.at(i).at(j) == 2);
                    }
                } else if(i == 3) {
                    if(j == 0) {
                        CHECK(graph.at(i).at(j) == 4);
                    } else if(j == 1) {
                        CHECK(graph.at(i).at(j) == 1);
                    }
                }
            }
        }
    };
}