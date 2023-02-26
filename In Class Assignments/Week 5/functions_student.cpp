#include <iostream>
#include "student.h"

using namespace std;

double computeClassScore(const student & s) {
    double total{0.0};

    double sum{0.0}, hw{0.0};

    for(auto hw_score : s.hw_grades) {
        sum += hw_score;
    }

    hw = sum / s.hw_grades.size();

    total = 0.3 * s.midterm + 0.3 * s.final + 0.4 * hw;

    return total;
}

student getStudentData() {
    struct student s;

    cout << "Enter the student's id: " << endl;
    cin >> s.id;

    cout << "Enter the student's name: " << endl;
    cin >> s.name;

    cout << "Enter the student's midterm grade: " << endl;
    cin >> s.midterm;

    cout << "Enter the student's final grade: " << endl;
    cin >> s.final;

    cout << "Enter a homework score: " << endl;
    int score;

    while(cin >> score) {
        cout << "Enter a homework score (CTRL-D to exit): " << endl;
        s.hw_grades.push_back(score);
    }

    return s;
}

void outputStudentData(const student & s, const double & total) {
    cout << s.name << " earned an " << s.final << " on their final" << endl;

    for(auto score : s.hw_grades) {
        cout << score << " ";
    }

    cout << endl;
    cout << "Final total class score: " << total << endl;
}