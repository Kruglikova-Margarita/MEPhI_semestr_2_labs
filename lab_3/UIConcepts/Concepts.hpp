#include <concepts>
#include <complex>
#include <string>

#include "../MainClasses/Matrix.hpp"

#include "../StoredClasses/Student.hpp"
#include "../StoredClasses/Teacher.hpp"


#ifndef concepts_h
#define concepts_h

using namespace std;

template <class T>
concept SimpleTypes = same_as<T, int> || same_as<T, float> || same_as<T, string>;

template <class T>
concept IntFloat = same_as<T, int> || same_as<T, float>;

#endif