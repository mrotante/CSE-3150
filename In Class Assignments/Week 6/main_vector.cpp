#include <iostream>
#include "vector.h"
#include <vector>

using namespace std;

int main() {
    vector<int_vector> vectors = readFile("vector_1.txt");

    for(int i = 0; i < vectors.size(); i++) {
        cout << vectors.at(i).id << " " << vectors.at(i).from << " " << vectors.at(i).to << endl;
    }    
}