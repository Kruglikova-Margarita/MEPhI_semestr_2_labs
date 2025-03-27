#include <iostream>

using namespace std;

void printMenuQueue() {
    cout << "You can:\n";
    cout << "1 - print queue\n";
    cout << "2 - append element in queue\n";
    cout << "3 - take first element of queue\n";
    cout << "4 - get length of queue\n";
    cout << "5 - view element by index\n";
    cout << "6 - concat two queues\n";
    cout << "7 - get sub queue\n";
    cout << "8 - check if this queue contains another queue\n";
    cout << "9 - find another queue in this queue\n";
    cout << "10 - connect this queue with another queue\n";
    cout << "0 - print menu\n";
    cout << "-1 - finish programm execution\n";
}

void printMenuMatrix() {
    cout << "You can:\n";
    cout << "1 - print matrix\n";
    cout << "2 - get number of rows\n";
    cout << "3 - get number of columns\n";
    cout << "4 - get element by indexes\n";
    cout << "5 - sum two matrices\n";
    cout << "6 - mult matrix on scalar\n";
    cout << "7 - mult two matrices\n";
    cout << "8 - get norm of matrix by rows\n";
    cout << "9 - get norm of matrix by columns\n";
    cout << "10 - get norm of matrix by square root of sum of squares of elements\n";
    cout << "11 - set value by indexes\n";
    cout << "12 - swap rows\n";
    cout << "13 - swap columns\n";
    cout << "14 - mult row on scalar\n";
    cout << "15 - mult column on scalar\n";
    cout << "16 - linear combine one row with another row\n";
    cout << "17 - linear combine one columns with another column\n";
    cout << "0 - print menu\n";
    cout << "-1 - finish programm execution\n";
}

void printMenuPolynomial() {
    cout << "You can:\n";
    cout << "1 - print polynomial\n";
    cout << "2 - get degree of polinomial\n";
    cout << "3 - get coefficient at degree\n";
    cout << "4 - calculate value of polynomial\n";
    cout << "5 - sum two polynomials\n";
    cout << "6 - mult two polynomials\n";
    cout << "7 - mult polynomial on scalar\n";
    cout << "8 - calculate value of composition of two polynomials\n";
    cout << "9 - get composition of two polynomials\n";
    cout << "0 - print menu\n";
    cout << "-1 - finish programm execution\n";
}

void printMenuAlgorithms() {
    cout << "You can:\n";
    cout << "1 - get multipliers of number\n";
    cout << "2 - check if number is prime\n";
    cout << "3 - get prime multipliers of number\n";
    cout << "4 - get all prime numbers that are less than number\n";
    cout << "0 - print menu\n";
    cout << "-1 - finish programm execution\n";
}

void printMenuOfTypesQueue() {
    cout << "You can create queue of these types:\n";
    cout << "1 - integer numbers\n";
    cout << "2 - real numbers\n";
    cout << "3 - complex numbers\n";
    cout << "4 - strings\n";
    cout << "5 - students\n";
    cout << "6 - teachers\n";
}

void printMenuOfTypesMatrix() {
    cout << "You can create matrix of these types:\n";
    cout << "1 - integer numbers\n";
    cout << "2 - real numbers\n";
    cout << "3 - complex numbers\n";
}

void printMenuOfTypesPolynomial() {
    cout << "You can create polynomial of these types:\n";
    cout << "1 - integer numbers\n";
    cout << "2 - real numbers\n";
    cout << "3 - complex numbers\n";
    cout << "4 - square matrix\n";
}