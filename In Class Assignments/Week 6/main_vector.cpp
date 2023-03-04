#include <iostream>
#include "vector.h"
#include <vector>

using namespace std;

int main() {
    char filepath[256];
    
    cout << "Enter a filepath: ";
    cin >> filepath;

    vector<int_vector> vectors = readFile(filepath);

    for(int i = vectors.size()-1; i > 0; i--) {
        cout << vectors.at(i).id << ": " << vectors.at(i).from << " " << vectors.at(i).to << endl;
    }    
}