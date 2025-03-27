#include <iostream>
#include <complex>

#include "../../MainClasses/Matrix.hpp"

#include "../../UI/Input/input.hpp"
#include "../../UI/Menu/menu.hpp"

#include "../PrintersConcepts.hpp"
#include "../Concepts.hpp"

using namespace std;

#ifndef actionsMatrix_h
#define actionsMatrix_h

template <StoredTypesMatrix T>
void actionMatrix2(Matrix<T> *matrix) {
    int rows = matrix->GetRowsCount();
    cout << "Number of rows: " << rows << "\n";
}



template <StoredTypesMatrix T>
void actionMatrix3(Matrix<T> *matrix) {
    int columns = matrix->GetColumnsCount();
    cout << "Number of rows: " << columns << "\n";
}



template <StoredTypesMatrix T>
void actionMatrix4(Matrix<T> *matrix) {
    Printers<T> printer;
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    try {
        T el = (*matrix)(i, j);
        cout << "Element: ";
        printer.PrintItem(el);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionMatrix5(Matrix<int> *matrix) {
    cout << "Input added matrix:\n";
    int rows = matrix->GetRowsCount();
    int columns = matrix->GetColumnsCount();
    Matrix<int> *matrix1 = inputMatrixInt(rows, columns);
    Printers<int> printer;
    cout << "Added matrix:\n";
    printer.PrintMatrix(*matrix1);
    Matrix<int> matrix2 = (*matrix) + (*matrix1);
    cout << "Sum of matrices:\n";
    printer.PrintMatrix(matrix2);
    delete matrix1;
}

void actionMatrix5(const Matrix<float> *matrix) {
    cout << "Input added matrix:\n";
    int rows = matrix->GetRowsCount();
    int columns = matrix->GetColumnsCount();
    Matrix<float> *matrix1 = inputMatrixFloat(rows, columns);
    Printers<float> printer;
    cout << "Added matrix:\n";
    printer.PrintMatrix(*matrix1);
    Matrix<float> matrix2 = (*matrix) + (*matrix1);
    cout << "Sum of matrices:\n";
    printer.PrintMatrix(matrix2);
    delete matrix1;
}

void actionMatrix5(const Matrix<complex<float>> *matrix) {
    cout << "Input added matrix:\n";
    int rows = matrix->GetRowsCount();
    int columns = matrix->GetColumnsCount();
    Matrix<complex<float>> *matrix1 = inputMatrixComplex(rows, columns);
    Printers<complex<float>> printer;
    cout << "Added matrix:\n";
    printer.PrintMatrix(*matrix1);
    Matrix<complex<float>> matrix2 = (*matrix) + (*matrix1);
    cout << "Sum of matrices:\n";
    printer.PrintMatrix(matrix2);
    delete matrix1;
}



void actionMatrix6(const Matrix<int> *matrix) {
    cout << "Input scalar: ";
    int num = inputInt();
    Matrix<int> matrix1 = (*matrix) * num;
    Printers<int> printer;
    cout << "Result matrix:\n";
    printer.PrintMatrix(matrix1);
}

void actionMatrix6(const Matrix<float> *matrix) {
    cout << "Input scalar: ";
    float num = inputFloat();
    Matrix<float> matrix1 = (*matrix) * num;
    Printers<float> printer;
    cout << "Result matrix:\n";
    printer.PrintMatrix(matrix1);
}

void actionMatrix6(const Matrix<complex<float>> *matrix) {
    cout << "Input scalar:\n";
    complex<float> num = inputComplex();
    Matrix<complex<float>> matrix1 = (*matrix) * num;
    Printers<complex<float>> printer;
    cout << "Result matrix:\n";
    printer.PrintMatrix(matrix1);
}



void actionMatrix7(const Matrix<int> *matrix) {
    cout << "Input multiplied matrix:\n";
    int columns = matrix->GetColumnsCount();
    Matrix<int> *matrix1 = inputMatrixInt(columns);
    cout << "Multiplied matrix:\n";
    Printers<int> printer;
    printer.PrintMatrix(*matrix1);
    Matrix<int> matrix2 = (*matrix) * (*matrix1);
    cout << "Result:\n";
    printer.PrintMatrix(matrix2);
    delete matrix1;
}

void actionMatrix7(const Matrix<float> *matrix) {
    cout << "Input multiplied matrix:\n";
    int columns = matrix->GetColumnsCount();
    Matrix<float> *matrix1 = inputMatrixFloat(columns);
    cout << "Multiplied matrix:\n";
    Printers<float> printer;
    printer.PrintMatrix(*matrix1);
    Matrix<float> matrix2 = (*matrix) * (*matrix1);
    cout << "Result:\n";
    printer.PrintMatrix(matrix2);
    delete matrix1;
}

void actionMatrix7(const Matrix<complex<float>> *matrix) {
    cout << "Input multiplied matrix:\n";
    int columns = matrix->GetColumnsCount();
    Matrix<complex<float>> *matrix1 = inputMatrixComplex(columns);
    cout << "Multiplied matrix:\n";
    Printers<complex<float>> printer;
    printer.PrintMatrix(*matrix1);
    Matrix<complex<float>> matrix2 = (*matrix) * (*matrix1);
    cout << "Result:\n";
    printer.PrintMatrix(matrix2);
    delete matrix1;
}



template <IntFloat T>
void actionMatrix8(const Matrix<T> *matrix) {
    T n = matrix->GetNormRow();
    cout << "Norm by rows: " << n << "\n";
}

void actionMatrix8(const Matrix<complex<float>> *matrix) {
    cout << "Impossible to get norm of matrix because elements are complex\n";

}



template <IntFloat T>
void actionMatrix9(const Matrix<T> *matrix) {
    T n = matrix->GetNormColumn();
    cout << "Norm by columns: " << n << "\n";
}

void actionMatrix9(const Matrix<complex<float>> *matrix) {
    cout << "Impossible to get norm of matrix because elements are complex\n";
}




template <StoredTypesMatrix T>
void actionMatrix10(const Matrix<T> *matrix) {
    T n = matrix->GetNormSquare();
    cout << "Norm by square root of sum of squares of elements: ";
    Printers<T> printer;
    printer.PrintItem(n);
    cout << "\n";
}




void actionMatrix11(Matrix<int> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    cout << "Input value: ";
    int value = inputInt();
    try{
        matrix->Set(i, j, value);
    }
    catch(out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix11(Matrix<float> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    cout << "Input value: ";
    float value = inputFloat();
    try{
        matrix->Set(i, j, value);
    }
    catch(out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix11(Matrix<complex<float>> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    cout << "Input value: ";
    complex<float> value = inputComplex();
    try{
        matrix->Set(i, j, value);
    }
    catch(out_of_range e) {
        cout << e.what() << "\n";
    }
}



template <StoredTypesMatrix T>
void actionMatrix12(Matrix<T> *matrix) {
    Printers<T> printer;
    cout << "Input index of first row: ";
    int i1 = inputNotNegative();
    cout << "Input index of second row: ";
    int i2 = inputNotNegative();
    try {
        matrix->SwapRows(i1, i2);
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



template <StoredTypesMatrix T>
void actionMatrix13(Matrix<T> *matrix) {
    Printers<T> printer;
    cout << "Input index of first column: ";
    int j1 = inputNotNegative();
    cout << "Input index of second column: ";
    int j2 = inputNotNegative();
    try {
        matrix->SwapColumns(j1, j2);
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionMatrix14(Matrix<int> *matrix) {
    cout << "Input index of row: ";
    int i = inputNotNegative();
    cout << "Input scalar: ";
    int s = inputInt();
    try {
        matrix->MultRowOnScalar(i, s);
        Printers<int> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix14(Matrix<float> *matrix) {
    cout << "Input index of row: ";
    int i = inputNotNegative();
    cout << "Input scalar: ";
    float s = inputFloat();
    try {
        matrix->MultRowOnScalar(i, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix14(Matrix<complex<float>> *matrix) {
    cout << "Input index of row: ";
    int i = inputNotNegative();
    cout << "Input scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->MultRowOnScalar(i, s);
        Printers<complex<float>> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionMatrix15(Matrix<int> *matrix) {
    cout << "Input index of column: ";
    int j = inputNotNegative();
    cout << "Input scalar: ";
    int s = inputInt();
    try {
        matrix->MultColumnOnScalar(j, s);
        Printers<int> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix15(Matrix<float> *matrix) {
    cout << "Input index of column: ";
    int j = inputNotNegative();
    cout << "Input scalar: ";
    float s = inputFloat();
    try {
        matrix->MultColumnOnScalar(j, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix15(Matrix<complex<float>> *matrix) {
    cout << "Input index of column: ";
    int j = inputNotNegative();
    cout << "Input scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->MultColumnOnScalar(j, s);
        Printers<complex<float>> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionMatrix16(Matrix<int> *matrix) {
    cout << "Input index of changed row: ";
    int i1 = inputNotNegative();
    cout << "Input index of added row: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    int s = inputInt();
    try {
        matrix->LineCombRow(i1, i2, s);
        Printers<int> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix16(Matrix<float> *matrix) {
    cout << "Input index of changed row: ";
    int i1 = inputNotNegative();
    cout << "Input index of added row: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    float s = inputFloat();
    try {
        matrix->LineCombRow(i1, i2, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix16(Matrix<complex<float>> *matrix) {
    cout << "Input index of changed row: ";
    int i1 = inputNotNegative();
    cout << "Input index of added row: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->LineCombRow(i1, i2, s);
        Printers<complex<float>> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionMatrix17(Matrix<int> *matrix) {
    cout << "Input index of changed column: ";
    int i1 = inputNotNegative();
    cout << "Input index of added column: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    int s = inputInt();
    try {
        matrix->LineCombColumn(i1, i2, s);
        Printers<int> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix17(Matrix<float> *matrix) {
    cout << "Input index of changed column: ";
    int i1 = inputNotNegative();
    cout << "Input index of added column: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    float s = inputFloat();
    try {
        matrix->LineCombColumn(i1, i2, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrix17(Matrix<complex<float>> *matrix) {
    cout << "Input index of changed column: ";
    int i1 = inputNotNegative();
    cout << "Input index of added column: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->LineCombColumn(i1, i2, s);
        Printers<complex<float>> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



template <StoredTypesMatrix T>
void actionsMatrix(Matrix<T> *matrix) {
    Printers<T> printer;
    printMenuMatrix();
    int action = chooseActionMatrix();
    while (action != -1) {
        switch(action) {
            case(1):
                printer.PrintMatrix(*matrix);
                break;
            case(2):
                actionMatrix2(matrix);
                break;
            case(3):
                actionMatrix3(matrix);
                break;
            case(4):
                actionMatrix4(matrix);
                break;
            case(5):
                actionMatrix5(matrix);
                break;
            case(6):
                actionMatrix6(matrix);
                break;
            case(7):
                actionMatrix7(matrix);
                break;
            case(8):
                actionMatrix8(matrix);
                break;
            case(9):
                actionMatrix9(matrix);
                break;
            case(10):
                actionMatrix10(matrix);
                break;
            case(11):
                actionMatrix11(matrix);
                break;
            case(12):
                actionMatrix12(matrix);
                break;
            case(13):
                actionMatrix13(matrix);
                break;
            case(14):
                actionMatrix14(matrix);
                break;
            case(15):
                actionMatrix15(matrix);
                break;
            case(16):
                actionMatrix16(matrix);
                break;
            case(17):
                actionMatrix17(matrix);
                break;
            case(0):
                printMenuMatrix();
                break;
        }
        action = chooseActionMatrix();
    }
}

#endif