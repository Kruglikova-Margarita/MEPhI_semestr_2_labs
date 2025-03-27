#include <iostream>
#include <math.h>
#include "../SequenceClasses/Sequence.hpp"

#ifndef matrix_h
#define matrix_h

using namespace std;

template <class T>
concept StoredTypesMatrix = same_as<T, int> || same_as<T, float> || same_as<T, complex<float>>;

template <StoredTypesMatrix T>
class Matrix {
private:
    Sequence<T> *elements;
    size_t rows;
    size_t columns;

public:
    Matrix(T *items, int m, int n) {
        if (m <= 0) throw std::out_of_range("Invalid value of number of rows\n");
        if (n <= 0) throw std::out_of_range("Invalid value of number of columns\n");
        try {
            elements = new ArraySequence<T>(items, (m * n));
            rows= m;
            columns = n;
        }
        catch (...) {
            throw;
        }
    }

    Matrix(T *items, int n) {
        if (n <= 0) throw std::out_of_range("Invalid value of number of columns\n");
        try {
            elements = new ArraySequence<T>(items, (n * n));
            rows= n;
            columns = n;
        }
        catch (...) {
            throw;
        }
    }

    Matrix(Matrix<T> &&matrix) noexcept : elements() {
        rows = matrix.rows;
        columns = matrix.columns;
        std::swap(elements, matrix.elements);
    }

    Matrix(const Matrix<T> &matrix) noexcept {
        rows = matrix.rows;
        columns = matrix.columns;
        elements = new ArraySequence<T>(*(matrix.elements));
    }

    Matrix() noexcept {
        rows = 0;
        columns = 0;
        elements = new ArraySequence<T>;
    }

    ~Matrix() {
        delete elements;
    }

    size_t GetRowsCount() const noexcept {
        return rows;
    }

    size_t GetColumnsCount() const noexcept {
        return columns;
    }

    T GetElement(int i, int j) const {
        if ((i < 0) || (i >= rows) || (j < 0) || (j >= columns)) throw std::out_of_range("Index is out of range\n");
        return elements->Get(i * columns + j);
    }

    T operator()(int i, int j) const {
        T result;
        try {
            result = this->GetElement(i, j);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    Matrix<T> Sum(const Matrix<T> &matrix) const {
        size_t m = matrix.GetRowsCount();
        size_t n = matrix.GetColumnsCount();
        Matrix<T> sumMatrix;
        if ((rows != m) || (columns != n)) throw std::out_of_range("Impossible to sum matrices with different sizes\n");
        if ((rows == 0) && (columns == 0)) {
            Matrix<T> sumMatrix;
            return sumMatrix;
        }
        T *items = new T[rows * columns];
        for (int i = 0; i < (rows * columns); i++) {
            items[i] = (*elements)[i] + (*(matrix.elements))[i];
        }
        sumMatrix = Matrix<T>(items, rows, columns);
        delete [] items;
        return sumMatrix;
    }

    Matrix<T> operator+(const Matrix<T> &matrix) const {
        Matrix<T> result;
        try {
            result = this->Sum(matrix);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    Matrix<T> MultOnScalar(T k) const noexcept {
        Matrix<T> result;
        if ((rows == 0) && (columns == 0)) {
            Matrix<T> result;
            return result;
        }
        T *items = new T[rows * columns];
        for (int i = 0; i < (rows * columns); i++) {
            items[i] = (*elements)[i] * k;
        }
        result = Matrix<T>(items, rows, columns);
        delete [] items;
        return result;
    }

    Matrix<T> operator*(T k) const noexcept {
        Matrix<T> result = this->MultOnScalar(k);
        return result;
    }

    Matrix<T> Mult(const Matrix<T> &matrix) const {
        size_t m = matrix.GetRowsCount();
        size_t n = matrix.GetColumnsCount();
        if ((rows == 0) || (m == 0)) throw std::out_of_range("Impossible to multiply empty matrix\n");
        if (columns != m) throw std::out_of_range("Impossible to multiply matrices of this sizes\n");
        size_t newRows = rows;
        size_t newColumns = n;
        T *items = new T[newRows * newColumns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < n; j++) {
                T sum = (this->GetElement(i, 0)) * (matrix.GetElement(0, j));
                for (int k = 1; k < columns; k++) {
                    sum += (this->GetElement(i, k)) * (matrix.GetElement(k, j));
                }
                items[i * newColumns + j] = sum;
            }
        }
        Matrix<T> result(items, newRows, newColumns);
        delete [] items;
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &matrix) const {
        Matrix<T> result;
        try {
            result = this->Mult(matrix);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    T GetNormRow() const {
        if ((rows == 0) && (columns == 0)) throw std::out_of_range("Impossible to find norm of empty matrix\n");
        T *sumModules = new T[rows];
        for (int i = 0; i < rows; i++) {
            sumModules[i] = abs(this->GetElement(i, 0));
            for (int j = 1; j < columns; j++) {
                sumModules[i] += abs(this->GetElement(i, j));
            }
        }
        T max = sumModules[0];
        for (int i = 1; i < rows; i++) {
            if (sumModules[i] > max) max = sumModules[i];
        }
        delete [] sumModules;
        return max;
    }

    T GetNormColumn() const {
        if ((rows == 0) && (columns == 0)) throw std::out_of_range("Impossible to find norm of empty matrix\n");
        T *sumModules = new T[columns];
        for (int j = 0; j < columns; j++) {
            sumModules[j] = abs(this->GetElement(0, j));
            for (int i = 1; i < rows; i++) {
                sumModules[j] += abs(this->GetElement(i, j));
            }
        }
        T max = sumModules[0];
        for (int j = 1; j < columns; j++) {
            if (sumModules[j] > max) max = sumModules[j];
        }
        delete [] sumModules;
        return max;
    }

    T GetNormSquare() const {
        if ((rows == 0) && (columns == 0)) throw std::out_of_range("Impossible to find norm of empty matrix\n");
        T sumSquares = ((*elements)[0]) * ((*elements)[0]);
        for (int i = 1; i < rows * columns; i++) {
            sumSquares += (*elements)[i] * (*elements)[i];
        }
        return sqrt(sumSquares);
    }

    void Set(int i, int j, T value) {
        if ((i < 0) || (i >= rows) || (j < 0) || (j >= columns)) throw std::out_of_range("Index is out of range\n");
        try {
            elements->Set(i * columns + j, value);
        }
        catch(...) {
            throw;
        }
    }

    void SwapRows(int i1, int i2) {
        if ((i1 < 0) || (i1 >= rows) || (i2 < 0) || (i2 >= rows)) throw std::out_of_range("Index is out of range\n");
        for (int j = 0; j < columns; j++) {
            T el1 = this->GetElement(i1, j);
            T el2 = this->GetElement(i2, j);
            try {
                elements->Set(i1 * columns + j, el2);
                elements->Set(i2 * columns + j, el1);
            }
            catch (...) {
                throw;
            }
        }
    }

    void SwapColumns(int j1, int j2) {
        if ((j1 < 0) || (j2 >= columns) || (j2 < 0) || (j2 >= columns)) throw std::out_of_range("Index is out of range\n");
        for (int i = 0; i < rows; i++) {
            T el1 = this->GetElement(i, j1);
            T el2 = this->GetElement(i, j2);
            try {
                elements->Set(i * columns + j1, el2);
                elements->Set(i * columns + j2, el1);
            }
            catch (...) {
                throw;
            }
        }
    }

    void MultRowOnScalar(int index, T k) {
        if ((index < 0) || (index >= rows)) throw std::out_of_range("Index is out of range\n");
        for (int j = 0; j < columns; j++) {
            T el = this->GetElement(index, j);
            elements->Set(index * columns + j, el * k);
        }
    }

    void MultColumnOnScalar(int index, T k) {
        if ((index < 0) || (index >= columns)) throw std::out_of_range("Index is out of range\n");
        for (int i = 0; i < rows; i++) {
            T el = this->GetElement(i, index);
            elements->Set(i * columns + index, el * k);
        }
    }

    void LineCombRow(int indexChange, int indexAdd, T k) {
        if ((indexChange < 0) || (indexChange >= rows) || (indexAdd < 0) || (indexAdd >= rows)) throw std::out_of_range("Index is out of range\n");
        for (int j = 0; j < columns; j++) {
            T el1 = this->GetElement(indexChange, j);
            T el2 = this->GetElement(indexAdd, j);
            elements->Set(indexChange * columns + j, el1 + el2 * k);
        }
    }

    void LineCombColumn(int indexChange, int indexAdd, T k) {
        if ((indexChange < 0) || (indexChange >= columns) || (indexAdd < 0) || (indexAdd >= columns)) throw std::out_of_range("Index is out of range\n");
        for (int i = 0; i < rows; i++) {
            T el1 = this->GetElement(i, indexChange);
            T el2 = this->GetElement(i, indexAdd);
            elements->Set(i * columns + indexChange, el1 + el2 * k);
        }
    }

    bool operator==(const Matrix<T> &matrix) const noexcept {
        size_t cmpRows = matrix.GetRowsCount();
        size_t cmpColumns = matrix.GetColumnsCount();
        if ((rows != cmpRows) || (columns != cmpColumns)) return false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                T el1 = (*this)(i, j);
                T el2 = matrix(i, j);
                if (!(el1 == el2)) return false;
            }
        }
        return true;
    }

    void operator=(const Matrix<T> &matrix) {
        delete elements;
        elements = new ArraySequence(*(matrix.elements));
        rows = matrix.rows;
        columns = matrix.columns;
    }

};

#endif