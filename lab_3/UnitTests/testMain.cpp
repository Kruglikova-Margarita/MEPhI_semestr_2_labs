#include <iostream>
#include "TestsQueue/testsQueue.hpp"
#include "TestsMatrix/testsMatrix.hpp"
#include "TestsPolynomial/testsPolynomial.hpp"
#include "TestsAlgorithms/testsAlgorithms.hpp"

int main() {
    testsQueue();
    std::cout << "\n";
    testsMatrix();
    std::cout << "\n";
    testsPolynomial();
    std::cout << "\n";
    testsAlgorithms();

    return 0;
}