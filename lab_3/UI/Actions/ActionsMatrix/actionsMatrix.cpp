#include <iostream>
#include <complex>
#include "../../../MainClasses/Matrix.hpp"
#include "../../Input/input.hpp"
#include "../../../Printers.hpp"

using namespace std;

void actionMatrixInt2(const Matrix<int> *matrix) {
    int rows = matrix->GetRowsCount();
    cout << "Number of rows: " << rows << "\n";
}

void actionMatrixInt3(const Matrix<int> *matrix) {
    int columns = matrix->GetColumnsCount();
    cout << "Number of rows: " << columns << "\n";
}

void actionMatrixInt4(const Matrix<int> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    int el;
    try {
        el = (*matrix)(i, j);
        cout << "Element: " << el << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixInt5(const Matrix<int> *matrix) {
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

void actionMatrixInt6(const Matrix<int> *matrix) {
    cout << "Input scalar: ";
    int num = inputInt();
    Matrix<int> matrix1 = (*matrix) * num;
    Printers<int> printer;
    cout << "Result matrix:\n";
    printer.PrintMatrix(matrix1);
}

void actionMatrixInt7(const Matrix<int> *matrix) {
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

void actionMatrixInt8(const Matrix<int> *matrix) {
    int n = matrix->GetNormRow();
    cout << "Norm by rows: " << n << "\n";
}

void actionMatrixInt9(const Matrix<int> *matrix) {
    int n = matrix->GetNormColumn();
    cout << "Norm by columns: " << n << "\n";
}

void actionMatrixInt10(const Matrix<int> *matrix) {
    int n = matrix->GetNormSquare();
    cout << "Norm by square root of sum of squares of elements: " << n << "\n";
}

void actionMatrixInt11(Matrix<int> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    cout << "Input value: ";
    int value = inputInt();
    matrix->Set(i, j, value);
}

void actionMatrixInt12(Matrix<int> *matrix) {
    cout << "Input index of first row: ";
    int i1 = inputNotNegative();
    cout << "Input index of second row: ";
    int i2 = inputNotNegative();
    try {
        matrix->SwapRows(i1, i2);
        Printers<int> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixInt13(Matrix<int> *matrix) {
    cout << "Input index of first column: ";
    int j1 = inputNotNegative();
    cout << "Input index of second column: ";
    int j2 = inputNotNegative();
    try {
        matrix->SwapColumns(j1, j2);
        Printers<int> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixInt14(Matrix<int> *matrix) {
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

void actionMatrixInt15(Matrix<int> *matrix) {
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

void actionMatrixInt16(Matrix<int> *matrix) {
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

void actionMatrixInt17(Matrix<int> *matrix) {
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



void actionMatrixFloat2(const Matrix<float> *matrix) {
    int rows = matrix->GetRowsCount();
    cout << "Number of rows: " << rows << "\n";
}

void actionMatrixFloat3(const Matrix<float> *matrix) {
    int columns = matrix->GetColumnsCount();
    cout << "Number of rows: " << columns << "\n";
}

void actionMatrixFloat4(const Matrix<float> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    float el;
    try {
        el = (*matrix)(i, j);
        cout << "Element: " << el << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixFloat5(const Matrix<float> *matrix) {
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

void actionMatrixFloat6(const Matrix<float> *matrix) {
    cout << "Input scalar: ";
    float num = inputFloat();
    Matrix<float> matrix1 = (*matrix) * num;
    Printers<float> printer;
    cout << "Result matrix:\n";
    printer.PrintMatrix(matrix1);
}

void actionMatrixFloat7(const Matrix<float> *matrix) {
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

void actionMatrixFloat8(const Matrix<float> *matrix) {
    float n = matrix->GetNormRow();
    cout << "Norm by rows: " << n << "\n";
}

void actionMatrixFloat9(const Matrix<float> *matrix) {
    float n = matrix->GetNormColumn();
    cout << "Norm by columns: " << n << "\n";
}

void actionMatrixFloat10(const Matrix<float> *matrix) {
    float n = matrix->GetNormSquare();
    cout << "Norm by square root of sum of squares of elements: " << n << "\n";
}

void actionMatrixFloat11(Matrix<float> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    cout << "Input value: ";
    float value = inputFloat();
    matrix->Set(i, j, value);
}

void actionMatrixFloat12(Matrix<float> *matrix) {
    cout << "Input index of first row: ";
    int i1 = inputNotNegative();
    cout << "Input index of second row: ";
    int i2 = inputNotNegative();
    try {
        matrix->SwapRows(i1, i2);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixFloat13(Matrix<float> *matrix) {
    cout << "Input index of first column: ";
    int j1 = inputNotNegative();
    cout << "Input index of second column: ";
    int j2 = inputNotNegative();
    try {
        matrix->SwapColumns(j1, j2);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrix(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixFloat14(Matrix<float> *matrix) {
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

void actionMatrixFloat15(Matrix<float> *matrix) {
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

void actionMatrixFloat16(Matrix<float> *matrix) {
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

void actionMatrixFloat17(Matrix<float> *matrix) {
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



void actionMatrixComplex2(const Matrix<complex<float>> *matrix) {
    int rows = matrix->GetRowsCount();
    cout << "Number of rows: " << rows << "\n";
}

void actionMatrixComplex3(const Matrix<complex<float>> *matrix) {
    int columns = matrix->GetColumnsCount();
    cout << "Number of rows: " << columns << "\n";
}

void actionMatrixComplex4(const Matrix<complex<float>> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    complex<float> el;
    try {
        el = (*matrix)(i, j);
        cout << "Element: ";
        Printers<float> printer;
        printer.PrintComplex(el);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixComplex5(const Matrix<complex<float>> *matrix) {
    cout << "Input added matrix:\n";
    int rows = matrix->GetRowsCount();
    int columns = matrix->GetColumnsCount();
    Matrix<complex<float>> *matrix1 = inputMatrixComplex(rows, columns);
    Printers<float> printer;
    cout << "Added matrix:\n";
    printer.PrintMatrixOfComplex(*matrix1);
    Matrix<complex<float>> matrix2 = (*matrix) + (*matrix1);
    cout << "Sum of matrices:\n";
    printer.PrintMatrixOfComplex(matrix2);
    delete matrix1;
}

void actionMatrixComplex6(const Matrix<complex<float>> *matrix) {
    cout << "Input scalar:\n";
    complex<float> num = inputComplex();
    Matrix<complex<float>> matrix1 = (*matrix) * num;
    Printers<float> printer;
    cout << "Result matrix:\n";
    printer.PrintMatrixOfComplex(matrix1);
}

void actionMatrixComplex7(const Matrix<complex<float>> *matrix) {
    cout << "Input multiplied matrix:\n";
    int columns = matrix->GetColumnsCount();
    Matrix<complex<float>> *matrix1 = inputMatrixComplex(columns);
    cout << "Multiplied matrix:\n";
    Printers<float> printer;
    printer.PrintMatrixOfComplex(*matrix1);
    Matrix<complex<float>> matrix2 = (*matrix) * (*matrix1);
    cout << "Result:\n";
    printer.PrintMatrixOfComplex(matrix2);
    delete matrix1;
}

void actionMatrixComplex8(const Matrix<complex<float>> *matrix) {
    cout << "Impossible to get norm of matrix because elements are complex\n";
}

void actionMatrixComplex9(const Matrix<complex<float>> *matrix) {
    cout << "Impossible to get norm of matrix because elements are complex\n";
}

void actionMatrixComplex10(const Matrix<complex<float>> *matrix) {
    complex<float> n = matrix->GetNormSquare();
    cout << "Norm by square root of sum of squares of elements: " << n << "\n";
}

void actionMatrixComplex11(Matrix<complex<float>> *matrix) {
    cout << "Input number of row: ";
    int i = inputNotNegative();
    cout << "Input number of column: ";
    int j = inputNotNegative();
    cout << "Input value: ";
    complex<float> value = inputComplex();
    matrix->Set(i, j, value);
}

void actionMatrixComplex12(Matrix<complex<float>> *matrix) {
    cout << "Input index of first row: ";
    int i1 = inputNotNegative();
    cout << "Input index of second row: ";
    int i2 = inputNotNegative();
    try {
        matrix->SwapRows(i1, i2);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrixOfComplex(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixComplex13(Matrix<complex<float>> *matrix) {
    cout << "Input index of first column: ";
    int j1 = inputNotNegative();
    cout << "Input index of second column: ";
    int j2 = inputNotNegative();
    try {
        matrix->SwapColumns(j1, j2);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrixOfComplex(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixComplex14(Matrix<complex<float>> *matrix) {
    cout << "Input index of row: ";
    int i = inputNotNegative();
    cout << "Input scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->MultRowOnScalar(i, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrixOfComplex(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixComplex15(Matrix<complex<float>> *matrix) {
    cout << "Input index of column: ";
    int j = inputNotNegative();
    cout << "Input scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->MultColumnOnScalar(j, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrixOfComplex(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixComplex16(Matrix<complex<float>> *matrix) {
    cout << "Input index of changed row: ";
    int i1 = inputNotNegative();
    cout << "Input index of added row: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->LineCombRow(i1, i2, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrixOfComplex(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionMatrixComplex17(Matrix<complex<float>> *matrix) {
    cout << "Input index of changed column: ";
    int i1 = inputNotNegative();
    cout << "Input index of added column: ";
    int i2 = inputNotNegative();
    cout << "Input value of scalar: ";
    complex<float> s = inputComplex();
    try {
        matrix->LineCombColumn(i1, i2, s);
        Printers<float> printer;
        cout << "Matrix:\n";
        printer.PrintMatrixOfComplex(*matrix);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}
