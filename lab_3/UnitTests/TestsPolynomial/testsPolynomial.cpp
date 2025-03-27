#include <iostream>
#include "../../MainClasses/Polynomial.hpp"
#include "testsPolynomial.hpp"

using namespace std;

void testsPolynomial() {
    bool check = true;
    cout << "== Tesing functions of the Polynomial class ==\n";

    testGetDegree(&check);
    testGetCoefficient(&check);  
    testOperator1Polynomial(&check);
    testOperator2Polynomial(&check);
    testOperator3Polynomial(&check);
    testOperator4Polynomial(&check);
    testComposition1(&check);
    testComposition2(&check);
    testOperator5Polynomial(&check);

    if (check) cout << "All functions of the Polynomial class are correct\n";
    else cout << "Error! Not all functions of the Polynomial class are correct\n";
}

void testGetDegree(bool *check) {
    int *ar = new int[3];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    Polynomial<int> p0;
    Polynomial<int> p1(ar, 3);
    int deg0 = p0.GetDegree();
    int deg1 = p1.GetDegree();
    if ((deg0 == -1) && (deg1 == 2)) cout << "GetDegree                          : passed\n";
    else {
        cout << "GetDegree                          : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testGetCoefficient(bool *check) {
    int *ar = new int[3];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    Polynomial<int> p(ar, 3);
    bool check1 = false;
    try {
        int k = p.GetCoefficient(-1);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        int k = p.GetCoefficient(3);
    }
    catch (...) {
        check2 = true;
    }
    int k = p.GetCoefficient(1);
    if (check1 && check2 && (k == 2)) cout << "GetCoefficient                     : passed\n";
    else {
        cout << "GetCoefficient                     : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testOperator1Polynomial(bool *check) {
    int *ar = new int[3];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    Polynomial<int> p0;
    Polynomial<int> p1(ar, 3);
    bool check1 = false;
    try {
        int v = p0(1);
    }
    catch (...) {
        check1 = true;
    }
    int v = p1(2);
    if (check1 && (v == 17)) cout << "Operator () (function GetValue)    : passed\n";
    else {
        cout << "Operator () (function GetValue)    : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testOperator2Polynomial(bool *check) {
    int *ar1 = new int[8];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    ar1[6] = 7;
    ar1[7] = 8;
    int *ar2 = new int[5];
    ar2[0] = 7;
    ar2[1] = 9;
    ar2[2] = 11;
    ar2[3] = 4;
    ar2[4] = 5;
    Polynomial<int> p0;
    Polynomial<int> p1(ar1, 5);
    Polynomial<int> p2(ar1 + 5, 3);
    Polynomial<int> p3(ar2, 5);
    bool check1 = false;
    try {
        Polynomial<int> *p4 = p0 + p1;
    }
    catch (...) {
        check1 = true;
    }
    Polynomial<int> *p4 = p1 + p2;
    if (check1 && (p3 == (*p4))) cout << "Operator +                         : passed\n";
    else {
        cout << "Operator +                         : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete p4;
}

void testOperator3Polynomial(bool *check) {
    int *ar1 = new int[5];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    int *ar2 = new int[7];
    ar2[0] = 1;
    ar2[1] = 4;
    ar2[2] = 10;
    ar2[3] = 16;
    ar2[4] = 22;
    ar2[5] = 22;
    ar2[6] = 15;
    Polynomial<int> p0;
    Polynomial<int> p1(ar1, 3);
    Polynomial<int> p2(ar1, 5);
    Polynomial<int> p3(ar2, 7);
    bool check1 = false;
    try {
        Polynomial<int> *p4 = p0 * p1;
    }
    catch (...) {
        check1 = true;
    }
    Polynomial<int> *p4 = p1 * p2;
    if (check1 && (p3 == (*p4))) cout << "Operator * (function Mult)         : passed\n";
    else {
        cout << "Operator * (function Mult)         : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete p4;
}

void testOperator4Polynomial(bool *check) {
    int *ar1 = new int[4];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    int *ar2 = new int[4];
    ar2[0] = 3;
    ar2[1] = 6;
    ar2[2] = 9;
    ar2[3] = 12;
    Polynomial<int> p0;
    Polynomial<int> p1(ar1, 4);
    Polynomial<int> p2(ar2, 4);
    bool check1 = false;
    try {
        Polynomial<int> * p3 = p0 * 2;
    }
    catch (...) {
        check1 = true;
    }
    Polynomial<int> *p3 = p1 * 3;
    if (check1 && (p2 == (*p3))) cout << "Operator * (function MultOnScalar) : passed\n";
    else {
        cout << "Operator * (function MultOnScalar) : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete p3;
}

void testComposition1(bool *check) {
    int *ar1 = new int[5];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    Polynomial<int> p0;
    Polynomial<int> p1(ar1, 3);
    Polynomial<int> p2(ar1 + 3, 2);
    bool check1 = false;
    try {
        int v = p1.Composition(p0, 1);
    }
    catch (...) {
        check1 = true;
    }
    int v = p1.Composition(p2, 2);
    if (check1 && (v == 617)) cout << "Composition (get value)            : passed\n";
    else {
        cout << "Composition (get value)            : failed\n";
        (*check) = false;
    }
    delete [] ar1;
}

void testComposition2(bool *check) {
    int *ar1 = new int[5];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    int *ar2 = new int[3];
    ar2[0] = 57;
    ar2[1] = 130;
    ar2[2] = 75;
    Polynomial<int> p0;
    Polynomial<int> p1(ar1, 3);
    Polynomial<int> p2(ar1 + 3, 2);
    Polynomial<int> p3(ar2, 3);
    bool check1 = false;
    try {
        Polynomial<int> *p4 = p1.Composition(p0);
    }
    catch (...) {
        check1 = true;
    }
    Polynomial<int> *p4 = p1.Composition(p2);
    if (check1 && (p3 == (*p4))) cout << "Composition (get polynomial)       : passed\n";
    else {
        cout << "Composition (get polynomial)       : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete p4;
}

void testOperator5Polynomial(bool *check) {
    int *ar1 = new int[5];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    Polynomial<int> p0;
    Polynomial<int> p1(ar1, 3);
    Polynomial<int> p2(ar1 + 2, 3);
    Polynomial<int> p3(ar1, 4);
    if (!(p0 == p1) && (p1 == p1) && !(p1 == p2) && !(p1 == p3)) cout << "Operator ==                        : passed\n";
    else {
        cout << "Operator ==                        : failed\n";
        (*check) = false;
    }
    delete [] ar1;
}