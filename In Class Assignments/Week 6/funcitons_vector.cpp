#include <iostream>
#include "vector.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<int_vector> readFile(char filepath[]) {
    vector<int_vector> vectors;

    fstream file(filepath);
    string line;
    int val;
    int id = 0;

    while(getline(file, line)) {
        int_vector vec;
        vec.id = id;

        stringstream ss(line);

        int i = 0;
        while(ss >> val) {
            if(i == 0) {
                vec.from = val; 
            } else {
                vec.to = val;
            }
            i++;
        }
        id++;

        vectors.push_back(vec);
    }

    return vectors;
}

/*
while(getline(file, line)) {
        
        stringstream ss(line);
        while(ss >> val) {
            cout << val << " ";
        }
        cout << "\n\n";
    }
    */