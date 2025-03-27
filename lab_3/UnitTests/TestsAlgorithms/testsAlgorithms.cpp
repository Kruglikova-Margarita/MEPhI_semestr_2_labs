#include <iostream>
#include "../../SequenceClasses/Sequence.hpp"
#include "../../Algorithms.hpp"
#include "testsAlgorithms.hpp"

using namespace std;

void testsAlgorithms() {
    bool check = true;
    cout << "== Tesing algorithms ==\n";

    testMultipliers(&check);
    testCheckPrimeNumber(&check);
    testPrimeMultipliers(&check);
    testSieveOfEratosthenes(&check);

    if (check) cout << "All algorithms are correct\n";
    else cout << "Error! Not all algorithms are correct\n";
}

void testMultipliers(bool *check) {
    int *ar = new int[5];
    ar[0] = 2;
    ar[1] = 3;
    ar[2] = 4;
    ar[3] = 6;
    ar[4] = 12;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 5);
    Sequence<int> *s2 = multipliers(12);
    bool check1 = false;
    try {
        Sequence<int> *s3 = multipliers(-10);
    }
    catch (...) {
        check1 = true;
    }
    if (((*s1) == (*s2)) && check1) cout << "Multipliers         : passed\n";
    else {
        cout << "Multipliers         : failed\n";
        (*check) = false;
    }
    delete [] ar;
    delete s1;
    delete s2;
}

void testCheckPrimeNumber(bool *check) {
    bool check1 = false;
    try {
        bool c = checkPrimeNumber(-10);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = checkPrimeNumber(7);
    bool check3 = checkPrimeNumber(6);
    if (check1 && check2 && !check3) cout << "CheckPrimeNumber    : passed\n";
    else {
        cout << "CheckPrimeNumber    : failed\n";
        (*check) = false;
    }
}

void testPrimeMultipliers(bool *check) {
    int *ar = new int[3];
    ar[0] = 2;
    ar[1] = 3;
    ar[2] = 7;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 3);
    Sequence<int> *s2 = primeMultipliers(42);
    bool check1 = false;
    try {
        Sequence<int> *s3 = primeMultipliers(-10);
    }
    catch (...) {
        check1 = true;
    }
    if (((*s1) == (*s2)) && check1) cout << "PrimeMultipliers    : passed\n";
    else {
        cout << "PrimeMultipliers    : passed\n";
        (*check) = false;
    }
    delete [] ar;
    delete s1;
    delete s2;
}

void testSieveOfEratosthenes(bool *check) {
    int *ar = new int[8];
    ar[0] = 2;
    ar[1] = 3;
    ar[2] = 5;
    ar[3] = 7;
    ar[4] = 11;
    ar[5] = 13;
    ar[6] = 17;
    ar[7] = 19;
    Sequence<int> *s0 = new ArraySequence<int>;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 8);
    Sequence<int> *s2 = sieveOfEratosthenes(20);
    Sequence<int> *s3 = sieveOfEratosthenes(1);
    bool check1 = false;
    try {
        Sequence<int> *s4 = sieveOfEratosthenes(-10);
    }
    catch (...) {
        check1 = true;
    }
    if (((*s1) == (*s2)) && ((*s0) == (*s3)) && check1) cout << "SieveOfEratosthenes : passed\n";
    else {
        cout << "SieveOfEratosthenes : failed\n";
        (*check) = false;
    }
    delete [] ar;
    delete s0;
    delete s1;
    delete s2;
    delete s3;
}