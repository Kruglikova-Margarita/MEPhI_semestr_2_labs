#include <iostream>
#include "../../MainClasses/Matrix.hpp"
#include "testsMatrix.hpp"

using namespace std;

void testsMatrix() {
    bool check = true;
    cout << "== Tesing functions of the Matrix class ==\n";

    testGetRowsCount(&check);
    testGetColumnsCount(&check);
    testOperator1Matrix(&check);
    testOperator2Matrix(&check);
    testOperator3Matrix(&check);
    testOperator4Matrix(&check);
    testGetNormRow(&check);
    testGetNormColumn(&check);
    testGetNormSquare(&check);
    testSet(&check);
    testSwapRows(&check);
    testSwapColumns(&check);
    testMultRowOnScalar(&check);
    testMultColumnOnScalar(&check);
    testLineCombRow(&check);
    testLineCombColumn(&check);
    testOperator5Matrix(&check);

    if (check) cout << "All functions of the Matrix class are correct\n";
    else cout << "Error! Not all functions of the Matrix class are correct\n";
}

void testGetRowsCount(bool *check) {
    int *ar = new int[6];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    Matrix<int> m1(ar, 2, 3);
    Matrix<int> m2;
    int rows1 = m1.GetRowsCount();
    int rows2 = m2.GetRowsCount();
    if ((rows1 == 2) && (rows2 == 0)) cout << "GetRowsCount                       : passed\n";
    else {
        cout << "GetRowsCount                       : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testGetColumnsCount(bool *check) {
    int *ar = new int[6];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    Matrix<int> m1(ar, 2, 3);
    Matrix<int> m2;
    int columns1 = m1.GetColumnsCount();
    int columns2 = m2.GetColumnsCount();
    if ((columns1 == 3) && (columns2 == 0)) cout << "GetColumnsCount                    : passed\n";
    else {
        cout << "GetColumnsCount                    : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testOperator1Matrix(bool *check) {
    int *ar = new int[6];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    Matrix<int> m1(ar, 2, 3);
    bool check1 = false;
    try {
        int el = m1(-1, 2);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        int el = m1(1, 3);
    }
    catch (...) {
        check2 = true;
    }
    int el = m1(1, 1);
    if (check1 && check2 && (el == 5)) cout << "Operator () (function GetElement)  : passed\n";
    else {
        cout << "Operator () (function GetElement)  : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testOperator2Matrix(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 2;
    ar2[1] = 4;
    ar2[2] = 6;
    ar2[3] = 8;
    ar2[4] = 10;
    ar2[5] = 12;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    Matrix<int> m3 = m1 + m1;
    Matrix<int> m4(ar1, 3, 2);
    bool check1 = false;
    try {
        Matrix<int> m5 = m1 + m4;
    }
    catch (...) {
        check1 = true;
    }
    if ((m2 == m3) && check1) cout << "Operator +                         : passed\n";
    else {
        cout << "Operator +                         : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testOperator3Matrix(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 2;
    ar2[1] = 4;
    ar2[2] = 6;
    ar2[3] = 8;
    ar2[4] = 10;
    ar2[5] = 12;
    Matrix<int> m0;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    Matrix<int> m3 = m1 * 2;
    Matrix<int> m4 = m0 * 5;
    if ((m2 == m3) && (m0 == m4)) cout << "Operator * (function MultOnScalar) : passed\n";
    else {
        cout << "Operator * (function MultOnScalar) : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testOperator4Matrix(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[4];
    ar2[0] = 22;
    ar2[1] = 28;
    ar2[2] = 49;
    ar2[3] = 64;
    Matrix<int> m0;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar1, 3, 2);
    Matrix<int> m3(ar2, 2, 2);
    bool check1 = false;
    try {
        Matrix<int> m4 = m0 * m1;
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        Matrix<int> m4 = m1 * m1;
    }
    catch (...) {
        check2 = true;
    }
    Matrix<int> m4 = m1 * m2;
    if (check1 && check2 && (m3 == m4)) cout << "Operator * (function Mult)         : passed\n";
    else {
        cout << "Operator * (function Mult)         : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testGetNormRow(bool *check) {
    int *ar = new int[6];
    ar[0] = 8;
    ar[1] = 8;
    ar[2] = 3;
    ar[3] = -2;
    ar[4] = 8;
    ar[5] = -8;
    Matrix<int> m0;
    Matrix<int> m1(ar, 3, 2);
    bool check1 = false;
    try {
        int n = m0.GetNormRow();
    }
    catch (...) {
        check1 = true;
    }
    int n = m1.GetNormRow();
    if (check1 && (n == 16)) cout << "GetNormRow                         : passed\n";
    else {
        cout << "GetNormRow                         : passed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testGetNormColumn(bool *check) {
    int *ar = new int[6];
    ar[0] = 8;
    ar[1] = 8;
    ar[2] = 3;
    ar[3] = -2;
    ar[4] = 8;
    ar[5] = -8;
    Matrix<int> m0;
    Matrix<int> m1(ar, 3, 2);
    bool check1 = false;
    try {
        int n = m0.GetNormColumn();
    }
    catch (...) {
        check1 = true;
    }
    int n = m1.GetNormColumn();
    if (check1 && (n == 19)) cout << "GetNormColumn                      : passed\n";
    else {
        cout << "GetNormColumn                      : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testGetNormSquare(bool *check) {
    int *ar = new int[6];
    ar[0] = 8;
    ar[1] = 8;
    ar[2] = 3;
    ar[3] = -2;
    ar[4] = 8;
    ar[5] = -8;
    Matrix<int> m0;
    Matrix<int> m1(ar, 3, 2);
    bool check1 = false;
    try {
        int n = m0.GetNormSquare();
    }
    catch (...) {
        check1 = true;
    }
    int n = m1.GetNormSquare();
    if (check1 && (n == 16)) cout << "GetNormSquare                      : passed\n";
    else {
        cout << "GetNormSquare                      : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testSet(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 1;
    ar2[1] = 2;
    ar2[2] = 3;
    ar2[3] = 4;
    ar2[4] = 10;
    ar2[5] = 6;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    bool check1 = false;
    try {
        m1.Set(-1, 1, 10);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.Set(1, 5, 10);
    }
    catch (...) {
        check2 = true;
    }
    m1.Set(1, 1, 10);
    if (check1 && check2 && (m1 == m2)) cout << "Set                                : passed\n";
    else {
        cout << "Set                                : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testSwapRows(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 5;
    ar2[1] = 6;
    ar2[2] = 3;
    ar2[3] = 4;
    ar2[4] = 1;
    ar2[5] = 2;
    Matrix<int> m1(ar1, 3, 2);
    Matrix<int> m2(ar2, 3, 2);
    bool check1 = false;
    try {
        m1.SwapRows(-1, 1);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.SwapRows(1, 3);
    }
    catch (...) {
        check2 = true;
    }
    m1.SwapRows(0, 2);
    if (check1 && check2 && (m1 == m2)) cout << "SwapRows                           : passed\n";
    else {
        cout << "SwapRows                           : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testSwapColumns(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 3;
    ar2[1] = 2;
    ar2[2] = 1;
    ar2[3] = 6;
    ar2[4] = 5;
    ar2[5] = 4;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    bool check1 = false;
    try {
        m1.SwapColumns(-1, 1);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.SwapColumns(1, 3);
    }
    catch (...) {
        check2 = true;
    }
    m1.SwapColumns(0, 2);
    if (check1 && check2 && (m1 == m2)) cout << "SwapColumns                        : passed\n";
    else {
        cout << "SwapColumns                        : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testMultRowOnScalar(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 1;
    ar2[1] = 2;
    ar2[2] = 3;
    ar2[3] = 8;
    ar2[4] = 10;
    ar2[5] = 12;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    bool check1 = false;
    try {
        m1.MultRowOnScalar(-1, 5);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.MultRowOnScalar(3, 5);
    }
    catch (...) {
        check2 = true;
    }
    m1.MultRowOnScalar(1, 2);
    if (check1 && check2 && (m1 == m2)) cout << "MultRowOnScalar                    : passed\n";
    else {
        cout << "MultRowOnScalar                    : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testMultColumnOnScalar(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 1;
    ar2[1] = 6;
    ar2[2] = 3;
    ar2[3] = 4;
    ar2[4] = 15;
    ar2[5] = 6;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    bool check1 = false;
    try {
        m1.MultColumnOnScalar(-1, 5);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.MultColumnOnScalar(3, 5);
    }
    catch (...) {
        check2 = true;
    }
    m1.MultColumnOnScalar(1, 3);
    if (check1 && check2 && (m1 == m2)) cout << "MultColumnOnScalar                 : passed\n";
    else {
        cout << "MultColumnOnScalar                 : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testLineCombRow(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 9;
    ar2[1] = 12;
    ar2[2] = 15;
    ar2[3] = 4;
    ar2[4] = 5;
    ar2[5] = 6;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    bool check1 = false;
    try {
        m1.LineCombRow(-1, 1, 2);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.LineCombRow(0, 2, 2);
    }
    catch (...) {
        check2 = true;
    }
    m1.LineCombRow(0, 1, 2);
    if (check1 && check2 && (m1 == m2)) cout << "LineCombRow                        : passed\n";
    else {
        cout << "LineCombRow                        : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testLineCombColumn(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 1;
    ar2[1] = 8;
    ar2[2] = 3;
    ar2[3] = 4;
    ar2[4] = 17;
    ar2[5] = 6;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    bool check1 = false;
    try {
        m1.LineCombColumn(-1, 1, 2);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        m1.LineCombColumn(0, 3, 2);
    }
    catch (...) {
        check2 = true;
    }
    m1.LineCombColumn(1, 2, 2);
    if (check1 && check2 && (m1 == m2)) cout << "LineCombColumn                     : passed\n";
    else {
        cout << "LineCombColumn                     : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}

void testOperator5Matrix(bool *check) {
    int *ar1 = new int[6];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    ar1[4] = 5;
    ar1[5] = 6;
    int *ar2 = new int[6];
    ar2[0] = 1;
    ar2[1] = 8;
    ar2[2] = 3;
    ar2[3] = 4;
    ar2[4] = 17;
    ar2[5] = 6;
    Matrix<int> m1(ar1, 2, 3);
    Matrix<int> m2(ar2, 2, 3);
    Matrix<int> m3(ar1, 2, 2);
    if ((m1 == m1) && !(m1 == m3) && !(m1 == m2)) cout << "Operator ==                        : passed\n";
    else {
        cout << "Operator ==                        : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
}