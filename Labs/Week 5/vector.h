#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <vector>
#include <iostream>

std::vector<std::vector<double> > readFile(char filepath[]);
double vec_magnitude(std::vector<double> v);
double dot_product(std::vector<double> v1, std::vector<double> v2);
double cos_distance(std::vector<double> v1, std::vector<double> v2);

#endif