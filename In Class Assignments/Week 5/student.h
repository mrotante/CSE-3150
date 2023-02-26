#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
    int id;
    string name;
    int final;
    int midterm;
    vector<int> hw_grades;
};

double computeClassScore(const student & s);
student getStudentData();
void outputStudentData(const student & s, const double & total);

#endif