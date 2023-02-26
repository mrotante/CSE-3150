#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "student.h"

using namespace std;

TEST_CASE("Testing computeClassScore") {
    student s1;
    s1.final = 100;
    s1.midterm = 100;
    s1.hw_grades.push_back(100);
    s1.hw_grades.push_back(100);

    CHECK(computeClassScore(s1) == 100);

    student s2;
    s2.final = 50;
    s2.midterm = 50;
    s2.hw_grades.push_back(50);

    CHECK(computeClassScore(s2) == 50);

    student s3;
    s3.final = 0;
    s3.midterm = 0;
    s3.hw_grades.push_back(0);

    CHECK(computeClassScore(s3) == 0);

    student s4;
    s4.final = 75;
    s4.midterm = 75;
    s4.hw_grades.push_back(100);
    s4.hw_grades.push_back(75);
    s4.hw_grades.push_back(50);

    CHECK(computeClassScore(s4) == 75);

    student s5;
    s5.final = 80;
    s5.midterm = 90;
    s5.hw_grades.push_back(74);
    s5.hw_grades.push_back(42);
    s5.hw_grades.push_back(33);
    s5.hw_grades.push_back(89);

    CHECK(computeClassScore(s5) == 74.8);


    student s6;
    s6.final = 12;
    s6.midterm = 100;
    s6.hw_grades.push_back(75);
    
    int score = 50;
    for(int i = 0; i < 5; i++) {
        s6.hw_grades.push_back(score);
        score += 7;
    }

    double s6_score = computeClassScore(s6);
    CHECK(s6_score > 59);
    CHECK(s6_score < 60);
}