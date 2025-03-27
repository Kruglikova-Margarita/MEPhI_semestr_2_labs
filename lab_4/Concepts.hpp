#include <complex>
#include <string>
#include "StoredClasses/Student.hpp"
#include "StoredClasses/Teacher.hpp"

#ifndef concepts_h
#define concepts_h

template <class T>
concept StoredTypes = same_as<T, int> || same_as<T, float> || same_as<T, complex<float>> || same_as<T, string> || same_as<T, Student> || same_as<T, Teacher>;

template <class T>
concept TotalOrdering = 
requires(T a, T b) {
    a < b;
    a > b;
    a == b;
};

#endif