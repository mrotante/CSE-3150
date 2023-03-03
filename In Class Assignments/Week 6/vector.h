#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <vector>
#include <iostream>


struct int_vector {
    int id;
    int from;
    int to;
    int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {};
    int_vector() : id(-1), from(0), to(0) {};
};

std::vector<int_vector> readFile(char filepath[]);

#endif