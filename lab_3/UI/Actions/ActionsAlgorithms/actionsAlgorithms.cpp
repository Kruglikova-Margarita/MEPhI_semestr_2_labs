#include <iostream>
#include "../../../SequenceClasses/Sequence.hpp"
#include "../../../Algorithms.hpp"
#include "../../../UIConcepts/PrintersConcepts.hpp"
#include "../../Input/input.hpp"

using namespace std;

void actionAlgorithms1() {
    Printers<int> printer;
    cout << "Input number: ";
    int number = inputNatural();
    Sequence<int> *s = multipliers(number);
    printer.PrintSequence(*s);
    delete s;
}

void actionAlgorithms2() {
    cout << "Input number: ";
    int number = inputNatural();
    bool prime = checkPrimeNumber(number);
    if (prime) cout << "The number is prime\n";
    else cout << "The number is not prime\n";
}

void actionAlgorithms3() {
    Printers<int> printer;
    cout << "Input number: ";
    int number = inputNatural();
    Sequence<int> *s = primeMultipliers(number);
    printer.PrintSequence(*s);
    delete s;
}

void actionAlgorithms4() {
    Printers<int> printer;
    cout << "Input number: ";
    int number = inputNatural();
    Sequence<int> *s = sieveOfEratosthenes(number);
    printer.PrintSequence(*s);
    delete s;
}