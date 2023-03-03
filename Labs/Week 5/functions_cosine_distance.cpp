#include <iostream>
#include "vector.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

vector<vector<double> > readFile(char filepath[]) {
    vector<vector<double> > vectors;

    fstream file(filepath);
    string line;
    int val;

    while(getline(file, line)) {
        vector<double> vec;
        stringstream ss(line);
        int i = 0;

        while(ss >> val) {
            vec.push_back(val);
        }

        vectors.push_back(vec);
    }

    return vectors;
}

double vec_magnitude(vector<double> v) {
    double square_sum = 0;
    for(int i = 0; i < v.size(); i++) {
        square_sum += pow(v.at(i), 2);
    }

    return sqrt(square_sum);
}

double dot_product(vector<double> v1, vector<double> v2) {
    assert(v1.size() == v2.size());

    double product = 0;
    for(int i = 0; i < v1.size(); i++) {
        product += (v1.at(i) * v2.at(i));
    }

    return product;
}

double cos_distance(vector<double> v1, vector<double> v2) {
    return acos(dot_product(v1, v2) / (vec_magnitude(v1) * vec_magnitude(v2)));
}