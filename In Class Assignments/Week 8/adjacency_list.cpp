#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "graph.h"

using namespace std;

std::vector<std::vector<int> > rFile(char filepath[]) {
    vector<vector<int> > v;
    ifstream file(filepath);
    string line;

    while(getline(file, line)) {
        vector<int> adjacency_list;
        stringstream lineStream(line);
        int val;
        
        while(lineStream >> val) {
            adjacency_list.push_back(val);
        }
        v.push_back(adjacency_list);
    }
    return v;
}
