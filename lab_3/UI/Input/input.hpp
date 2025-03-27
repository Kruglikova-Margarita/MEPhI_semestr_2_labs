#include <complex>
#include "../../StoredClasses/Student.hpp"
#include "../../StoredClasses/Teacher.hpp"
#include "../../MainClasses/Matrix.hpp"
#include "../../MainClasses/Polynomial.hpp"

#ifndef input_h
#define input_h

int chooseActionQueue();
int chooseActionMatrix();
int chooseActionPolynomial();
int chooseActionAlgorithms();
int chooseTypeQueue();
int chooseTypeMatrix();
int chooseTypePolynomial();
int inputNatural();
int inputInt();
int inputNotNegative();
float inputFloat();
complex<float> inputComplex();
Student inputStudent();
Teacher inputTeacher();
Matrix<int> *inputMatrixInt();
Matrix<int> *inputMatrixInt(int rows, int columns);
Matrix<int> *inputMatrixInt(int rows);
Matrix<float> *inputMatrixFloat();
Matrix<float> *inputMatrixFloat(int rows, int columns);
Matrix<float> *inputMatrixFloat(int rows);
Matrix<complex<float>> *inputMatrixComplex();
Matrix<complex<float>> *inputMatrixComplex(int rows, int columns);
Matrix<complex<float>> *inputMatrixComplex(int rows);
Polynomial<int> *inputPolynomialInt();
Polynomial<float> *inputPolynomialFloat();
Polynomial<complex<float>> *inputPolynomialComplex();
Matrix<float> inputSquareMatrix(int n);
Polynomial<Matrix<float>> *inputPolynomialMatrix();

#endif
