#include <iostream>
#include <string>
#include <vector>

#include "student.h"

using namespace std;

int main() {
    student s = getStudentData();
    double score = computeClassScore(s);
    outputStudentData(s, score);

    return 0;
}