#include <iostream>
#include "vector.h"
#include <vector>

using namespace std;

int main() {
    char filepath[256];
    cout << "Enter filepath: ";
    cin >> filepath;

    vector<vector<double> > vectors = readFile(filepath);
    vector<double> distances;

    for(int i = 0; i < vectors.size(); i++) {
        for(int j = 0; j < vectors.size(); j++) {
            if(i == j) {
                continue;
            }
            distances.push_back(cos_distance(vectors.at(i), vectors.at(j)));
        }
    }

    sort(distances.begin(), distances.end());
    for(auto x : distances) {
        cout << x << " ";
    }
}