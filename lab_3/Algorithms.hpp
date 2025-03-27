#include "SequenceClasses/Sequence.hpp"

#ifndef algorithms_h
#define algorithms_h

Sequence<int> *multipliers(int number) {
    if (number <= 0) throw std::out_of_range("Number must be positive\n");
    Sequence<int> *result = new ArraySequence<int>;
    for (int i = 2; i <= (number / 2); i++) {
        if (number % i == 0) result->Append(i);
    }
    result->Append(number);
    return result;
}

bool checkPrimeNumber(int number) {
    if (number <= 0) throw std::out_of_range("Number must be positive\n");
    for (int i = 2; i <= (number / 2); i++) {
        if (number % i == 0) return false;
    }
    return true;
}

Sequence<int> *primeMultipliers(int number) {
    if (number <= 0) throw std::out_of_range("Number must be positive\n");
    Sequence<int> *result = new ArraySequence<int>;
    for (int i = 2; i <= number; i++) {
        if (checkPrimeNumber(i) && (number % i == 0)) result->Append(i);
    }
    return result;
}

Sequence<int> *sieveOfEratosthenes(int number) {
    if (number <= 0) throw std::out_of_range("Number must be positive\n");
    bool *flags = new bool[number + 1];
    flags[0] = false;
    flags[1] = false;
    for (int i = 2; i <= number; i++) {
        flags[i] = true;
    }
    for (int i = 2; (i * i) <= number; i++) {
        if (flags[i]) {
            for (int j = (i * i); j <= number; j += i) {
                flags[j] = false;
            }
        }
    }
    Sequence<int> *result = new ArraySequence<int>;
    for (int i = 0; i <= number; i++) {
        if (flags[i]) result->Append(i);
    }
    delete [] flags;
    return result;
}

#endif