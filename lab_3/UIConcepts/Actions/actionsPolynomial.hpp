#include <iostream>
#include <complex>

#include "../../MainClasses/Matrix.hpp"
#include "../../MainClasses/Polynomial.hpp"

#include "../../UI/Input/input.hpp"
#include "../../UI/Menu/menu.hpp"

#include "../PrintersConcepts.hpp"
#include "../Concepts.hpp"

using namespace std;

#ifndef actionsPolynomial_h
#define actionsPolynomial_h

template <StoredTypesPolynomial T>
void actionPolynomial2(const Polynomial<T> *p) {
    int deg = p->GetDegree();
    cout << "Degree of polynomial: " << deg << "\n";
}



template <StoredTypesPolynomial T>
void actionPolynomial3(const Polynomial<T> *p) {
    Printers<T> printer;
    cout << "Input degree at coefficient, that you want get: ";
    int k = inputNotNegative();
    try {
        T c = p->GetCoefficient(k);
        cout << "Coefficient:\n";
        printer.PrintItem(c);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionPolynomial4(const Polynomial<int> *p) {
    cout << "Input argument: ";
    int x = inputInt();
    int v = (*p)(x);
    cout << "Value of polynomial: " << v << "\n";
}

void actionPolynomial4(const Polynomial<float> *p) {
    cout << "Input argument: ";
    float x = inputFloat();
    float v = (*p)(x);
    cout << "Value of polynomial: " << v << "\n";
}

void actionPolynomial4(const Polynomial<complex<float>> *p) {
    cout << "Input argument: ";
    complex<float> x = inputComplex();
    complex<float> v = (*p)(x);
    cout << "Value of polynomial: ";
    Printers<float> printer;
    printer.PrintItem(v);
    cout << "\n";
}

void actionPolynomial4(const Polynomial<Matrix<float>> *p) {
    cout << "Input argument:\n";
    cout << "Input number of rows and columns: ";
    int n = inputInt(); 
    Matrix<float> x = inputSquareMatrix(n);
    Matrix<float> v;
    try {
        v = (*p)(x);
        cout << "Value of polynomial:\n";
        Printers<float> printer;
        printer.PrintMatrix(v);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionPolynomial5(const Polynomial<int> *p) {
    cout << "Input added polynomial:\n";
    Polynomial<int> *p1 = inputPolynomialInt();
    cout << "Added polynomial:\n";
    Printers<int> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<int> *p2 = (*p) + (*p1);
    cout << "Result:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial5(const Polynomial<float> *p) {
    cout << "Input added polynomial:\n";
    Polynomial<float> *p1 = inputPolynomialFloat();
    cout << "Added polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<float> *p2 = (*p) + (*p1);
    cout << "Result:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial5(const Polynomial<complex<float>> *p) {
    cout << "Input added polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Added polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<complex<float>> *p2 = (*p) + (*p1);
    cout << "Result:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial5(const Polynomial<Matrix<float>> *p) {
    cout << "Input added polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Added polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    try {
        Polynomial<Matrix<float>> *p2 = (*p) + (*p1);
        cout << "Result:\n";
        printer.PrintPolynomial(*p2);
        delete p2;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}



void actionPolynomial6(const Polynomial<int> *p) {
    cout << "Input multiplied polynomial:\n";
    Polynomial<int> *p1 = inputPolynomialInt();
    cout << "Multiplied polynomial:\n";
    Printers<int> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<int> *p2 = (*p) * (*p1);
    cout << "Result:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial6(const Polynomial<float> *p) {
    cout << "Input multiplied polynomial:\n";
    Polynomial<float> *p1 = inputPolynomialFloat();
    cout << "Multiplied polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<float> *p2 = (*p) * (*p1);
    cout << "Result:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial6(const Polynomial<complex<float>> *p) {
    cout << "Input multiplied polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Multiplied polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<complex<float>> *p2 = (*p) * (*p1);
    cout << "Result:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial6(const Polynomial<Matrix<float>> *p) {
    cout << "Input multiplied polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Multiplied polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    try {
        Polynomial<Matrix<float>> *p2 = (*p) * (*p1);
        cout << "Result:\n";
        printer.PrintPolynomial(*p2);
        delete p2;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}



void actionPolynomial7(const Polynomial<int> *p) {
    cout << "Input scalar: ";
    int s = inputInt();
    Polynomial<int> *p1 = (*p) * s;
    cout << "Result:\n";
    Printers<int> printer;
    printer.PrintPolynomial(*p1);
    delete p1;
}

void actionPolynomial7(const Polynomial<float> *p) {
    cout << "Input scalar: ";
    float s = inputFloat();
    Polynomial<float> *p1 = (*p) * s;
    cout << "Result:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    delete p1;
}

void actionPolynomial7(const Polynomial<complex<float>> *p) {
    cout << "Input scalar: ";
    complex<float> s = inputComplex();
    Polynomial<complex<float>> *p1 = (*p) * s;
    cout << "Result:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    delete p1;
}

void actionPolynomial7(const Polynomial<Matrix<float>> *p) {
    cout << "Input scalar:\n";
    cout << "Input number of rows and columns: ";
    int n = inputInt(); 
    Matrix<float> s = inputSquareMatrix(n);
    try {
        Polynomial<Matrix<float>> *p1 = (*p) * s;
        cout << "Result:\n";
        Printers<float> printer;
        printer.PrintPolynomial(*p1);
        delete p1;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionPolynomial8(const Polynomial<int> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<int> *p1 = inputPolynomialInt();
    cout << "Second polynomial:\n";
    Printers<int> printer;
    printer.PrintPolynomial(*p1);
    cout << "Input argument: ";
    int x = inputInt();
    int v = p->Composition(*p1, x);
    cout << "Value of composition: " << v << "\n";
    delete p1;
}

void actionPolynomial8(const Polynomial<float> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<float> *p1 = inputPolynomialFloat();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    cout << "Input argument: ";
    float x = inputInt();
    float v = p->Composition(*p1, x);
    cout << "Value of composition: " << v << "\n";
    delete p1;
}

void actionPolynomial8(const Polynomial<complex<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    cout << "Input argument: ";
    complex<float> x = inputComplex();
    complex<float> v = p->Composition(*p1, x);
    cout << "Value of composition: ";
    printer.PrintItem(v);
    cout << "\n";
    delete p1;
}

void actionPolynomial8(const Polynomial<Matrix<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    cout << "Input argument: ";
    cout << "Input number of rows and columns: ";
    int n = inputInt(); 
    Matrix<float> x = inputSquareMatrix(n);
    try {
        Matrix<float> v = p->Composition(*p1, x);
        cout << "Value of composition:\n";
        printer.PrintMatrix(v);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}



void actionPolynomial9(const Polynomial<int> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<int> *p1 = inputPolynomialInt();
    cout << "Second polynomial:\n";
    Printers<int> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<int> *p2 = p->Composition(*p1);
    cout << "Composition:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial9(const Polynomial<float> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<float> *p1 = inputPolynomialFloat();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<float> *p2 = p->Composition(*p1);
    cout << "Composition:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial9(const Polynomial<complex<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    Polynomial<complex<float>> *p2 = p->Composition(*p1);
    cout << "Composition:\n";
    printer.PrintPolynomial(*p2);
    delete p1;
    delete p2;
}

void actionPolynomial9(const Polynomial<Matrix<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    try {
        Polynomial<Matrix<float>> *p2 = p->Composition(*p1);
        cout << "Composition:\n";
        printer.PrintPolynomial(*p2);
        delete p2;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}



template <StoredTypesPolynomial T>
void actionsPolynomial(Polynomial<T> *pol) {
    Printers<T> printer;
    printMenuPolynomial();
    int action = chooseActionPolynomial();
    while (action != -1) {
        switch(action) {
            case(1):
                printer.PrintPolynomial(*pol);
                break;
            case(2):
                actionPolynomial2(pol);
                break;
            case(3):
                actionPolynomial3(pol);
                break;
            case(4):
                actionPolynomial4(pol);
                break;
            case(5):
                actionPolynomial5(pol);
                break;
            case(6):
                actionPolynomial6(pol);
                break;
            case(7):
                actionPolynomial7(pol);
                break;
            case(8):
                actionPolynomial8(pol);
                break;
            case(9):
                actionPolynomial9(pol);
                break;
            case(0):
                printMenuPolynomial();
                break;
        }
        action = chooseActionPolynomial();
    }
}


#endif
