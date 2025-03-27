#include <iostream>
#include <complex>
#include "../../../MainClasses/Polynomial.hpp"
#include "../../Input/input.hpp"
#include "../../../Printers.hpp"

using namespace std;

void actionPolinomialInt2(const Polynomial<int> *p) {
    int deg = p->GetDegree();
    cout << "Degree of polynomial: " << deg << "\n";
}

void actionPolinomialInt3(const Polynomial<int> *p) {
    cout << "Input degree at coefficient, that you want get: ";
    int k = inputNotNegative();
    int c;
    try {
        c = p->GetCoefficient(k);
        cout << "Coefficient: " << c << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionPolinomialInt4(const Polynomial<int> *p) {
    cout << "Input argument: ";
    int x = inputInt();
    int v = (*p)(x);
    cout << "Value of polynomial: " << v << "\n";
}

void actionPolinomialInt5(const Polynomial<int> *p) {
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

void actionPolinomialInt6(const Polynomial<int> *p) {
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

void actionPolinomialInt7(const Polynomial<int> *p) {
    cout << "Input scalar: ";
    int s = inputInt();
    Polynomial<int> *p1 = (*p) * s;
    cout << "Result:\n";
    Printers<int> printer;
    printer.PrintPolynomial(*p1);
    delete p1;
}

void actionPolinomialInt8(const Polynomial<int> *p) {
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

void actionPolinomialInt9(const Polynomial<int> *p) {
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



void actionPolinomialFloat2(const Polynomial<float> *p) {
    int deg = p->GetDegree();
    cout << "Degree of polynomial: " << deg << "\n";
}

void actionPolinomialFloat3(const Polynomial<float> *p) {
    cout << "Input degree at coefficient, that you want get: ";
    int k = inputNotNegative();
    float c;
    try {
        c = p->GetCoefficient(k);
        cout << "Coefficient: " << c << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionPolinomialFloat4(const Polynomial<float> *p) {
    cout << "Input argument: ";
    float x = inputFloat();
    float v = (*p)(x);
    cout << "Value of polynomial: " << v << "\n";
}

void actionPolinomialFloat5(const Polynomial<float> *p) {
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

void actionPolinomialFloat6(const Polynomial<float> *p) {
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

void actionPolinomialFloat7(const Polynomial<float> *p) {
    cout << "Input scalar: ";
    float s = inputFloat();
    Polynomial<float> *p1 = (*p) * s;
    cout << "Result:\n";
    Printers<float> printer;
    printer.PrintPolynomial(*p1);
    delete p1;
}

void actionPolinomialFloat8(const Polynomial<float> *p) {
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

void actionPolinomialFloat9(const Polynomial<float> *p) {
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



void actionPolinomialComplex2(const Polynomial<complex<float>> *p) {
    int deg = p->GetDegree();
    cout << "Degree of polynomial: " << deg << "\n";
}

void actionPolinomialComplex3(const Polynomial<complex<float>> *p) {
    cout << "Input degree at coefficient, that you want get: ";
    int k = inputNotNegative();
    complex<float> c = p->GetCoefficient(k);
    cout << "Coefficient: ";
    Printers<float> printer;
    printer.PrintComplex(c);
    cout << "\n";
}

void actionPolinomialComplex4(const Polynomial<complex<float>> *p) {
    cout << "Input argument: ";
    complex<float> x = inputComplex();
    complex<float> v = (*p)(x);
    cout << "Value of polynomial: ";
    Printers<float> printer;
    printer.PrintComplex(v);
    cout << "\n";
}

void actionPolinomialComplex5(const Polynomial<complex<float>> *p) {
    cout << "Input added polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Added polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfComplex(*p1);
    Polynomial<complex<float>> *p2 = (*p) + (*p1);
    cout << "Result:\n";
    printer.PrintPolynomialOfComplex(*p2);
    delete p1;
    delete p2;
}

void actionPolinomialComplex6(const Polynomial<complex<float>> *p) {
    cout << "Input multiplied polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Multiplied polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfComplex(*p1);
    Polynomial<complex<float>> *p2 = (*p) * (*p1);
    cout << "Result:\n";
    printer.PrintPolynomialOfComplex(*p2);
    delete p1;
    delete p2;
}

void actionPolinomialComplex7(const Polynomial<complex<float>> *p) {
    cout << "Input scalar: ";
    complex<float> s = inputComplex();
    Polynomial<complex<float>> *p1 = (*p) * s;
    cout << "Result:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfComplex(*p1);
    delete p1;
}

void actionPolinomialComplex8(const Polynomial<complex<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfComplex(*p1);
    cout << "Input argument: ";
    complex<float> x = inputComplex();
    complex<float> v = p->Composition(*p1, x);
    cout << "Value of composition: ";
    printer.PrintComplex(v);
    cout << "\n";
    delete p1;
}

void actionPolinomialComplex9(const Polynomial<complex<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<complex<float>> *p1 = inputPolynomialComplex();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfComplex(*p1);
    Polynomial<complex<float>> *p2 = p->Composition(*p1);
    cout << "Composition:\n";
    printer.PrintPolynomialOfComplex(*p2);
    delete p1;
    delete p2;
}



void actionPolinomialMatrix2(const Polynomial<Matrix<float>> *p) {
    int deg = p->GetDegree();
    cout << "Degree of polynomial: " << deg << "\n";
}

void actionPolinomialMatrix3(const Polynomial<Matrix<float>> *p) {
    cout << "Input degree at coefficient, that you want get: ";
    int k = inputNotNegative();
    Matrix<float> c;
    try {
        c = p->GetCoefficient(k);
        cout << "Coefficient:\n";
        Printers<float> printer;
        printer.PrintMatrix(c);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionPolinomialMatrix4(const Polynomial<Matrix<float>> *p) {
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

void actionPolinomialMatrix5(const Polynomial<Matrix<float>> *p) {
    cout << "Input added polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Added polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfMatrix(*p1);
    try {
        Polynomial<Matrix<float>> *p2 = (*p) + (*p1);
        cout << "Result:\n";
        printer.PrintPolynomialOfMatrix(*p2);
        delete p2;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}

void actionPolinomialMatrix6(const Polynomial<Matrix<float>> *p) {
    cout << "Input multiplied polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Multiplied polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfMatrix(*p1);
    try {
        Polynomial<Matrix<float>> *p2 = (*p) * (*p1);
        cout << "Result:\n";
        printer.PrintPolynomialOfMatrix(*p2);
        delete p2;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}

void actionPolinomialMatrix7(const Polynomial<Matrix<float>> *p) {
    cout << "Input scalar:\n";
    cout << "Input number of rows and columns: ";
    int n = inputInt(); 
    Matrix<float> s = inputSquareMatrix(n);
    try {
        Polynomial<Matrix<float>> *p1 = (*p) * s;
        cout << "Result:\n";
        Printers<float> printer;
        printer.PrintPolynomialOfMatrix(*p1);
        delete p1;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionPolinomialMatrix8(const Polynomial<Matrix<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfMatrix(*p1);
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

void actionPolinomialMatrix9(const Polynomial<Matrix<float>> *p) {
    cout << "Input second polynomial:\n";
    Polynomial<Matrix<float>> *p1 = inputPolynomialMatrix();
    cout << "Second polynomial:\n";
    Printers<float> printer;
    printer.PrintPolynomialOfMatrix(*p1);
    try {
        Polynomial<Matrix<float>> *p2 = p->Composition(*p1);
        cout << "Composition:\n";
        printer.PrintPolynomialOfMatrix(*p2);
        delete p2;
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
    delete p1;
}
