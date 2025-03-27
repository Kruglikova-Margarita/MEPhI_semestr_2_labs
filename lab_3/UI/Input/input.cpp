#include <iostream>
#include <complex>
#include "../../MainClasses/Matrix.hpp"
#include "../../MainClasses/Polynomial.hpp"
#include "../../StoredClasses/Student.hpp"
#include "../../StoredClasses/Teacher.hpp"

int chooseActionQueue() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseActionMatrix() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 11) && (a != 12) && (a != 13) && (a != 14) && (a != 15) && (a != 16) && (a != 17) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 11) && (a != 12) && (a != 13) && (a != 14) && (a != 15) && (a != 16) && (a != 17) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseActionPolynomial() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseActionAlgorithms() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseTypeQueue() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose type: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseTypeMatrix() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose type: ";
    while ((a != 1) && (a != 2) && (a != 3)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseTypePolynomial() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose type: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int inputNatural() {
    int n = 0;
    int check = 0;
    while ((check != 1) || (n <= 0)) {
        check = scanf("%d", &n);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((check != 1) || (n <= 0)) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

int inputInt() {
    int n = 0;
    int check = 0;
    while (check != 1) {
        check = scanf("%d", &n);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

int inputNotNegative() {
    int n = 0;
    int check = 0;
    while ((check != 1) || (n < 0)) {
        check = scanf("%d", &n);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((check != 1) || (n < 0)) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;    
}

float inputFloat() {
    float n = 0;
    int check = 0;
    while (check != 1) {
        check = scanf("%f", &n);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

complex<float> inputComplex() {
    cout << "Input real part: ";
    float re = inputFloat();
    cout << "Input imaginary part: ";
    float im = inputFloat();
    complex<float> z(re, im);
    return z;
}

Student inputStudent() {
    string firstName;
    string middleName;
    string lastName;
    string group;
    cout << "Input information about student:\n";
    cout << "Input ID: ";
    int id = inputNatural();
    cout << "Input first name: ";
    cin >> firstName;
    cout << "Input middle name: ";
    cin >> middleName;
    cout << "Input last name: ";
    cin >> lastName;
    cout << "Input group: ";
    cin >> group;
    Student s(id, firstName, middleName, lastName, group);
    return s;
}

Teacher inputTeacher() {
    string firstName;
    string middleName;
    string lastName;
    string discipline;
    cout << "Input information about teacher:\n";
    cout << "Input ID: ";
    int id = inputNatural();
    cout << "Input first name: ";
    cin >> firstName;
    cout << "Input middle name: ";
    cin >> middleName;
    cout << "Input last name: ";
    cin >> lastName;
    cout << "Input discipline: ";
    cin >> discipline;
    Teacher t(id, firstName, middleName, lastName, discipline);
    return t;
}

Matrix<int> *inputMatrixInt() {
    std::cout << "Input number of rows: ";
    int rows = inputNatural();
    std::cout << "Input number of columns: ";
    int columns = inputNatural();
    int *items = new int[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * columns + j] = inputInt();
        }
    }
    Matrix<int> *matrix = new Matrix<int>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<int> *inputMatrixInt(int rows, int columns) {
    int *items = new int[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * columns + j] = inputInt();
        }
    }
    Matrix<int> *matrix = new Matrix<int>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<int> *inputMatrixInt(int rows) {
    std::cout << "Input number of columns: ";
    int columns = inputNatural();
    int *items = new int[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * columns + j] = inputInt();
        }
    }
    Matrix<int> *matrix = new Matrix<int>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<float> *inputMatrixFloat() {
    std::cout << "Input number of rows: ";
    int rows = inputNatural();
    std::cout << "Input number of columns: ";
    int columns = inputNatural();
    float *items = new float[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * columns + j] = inputFloat();
        }
    }
    Matrix<float> *matrix = new Matrix<float>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<float> *inputMatrixFloat(int rows, int columns) {
    float *items = new float[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * columns + j] = inputFloat();
        }
    }
    Matrix<float> *matrix = new Matrix<float>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<float> *inputMatrixFloat(int rows) {
    std::cout << "Input number of columns: ";
    int columns = inputNatural();
    float *items = new float[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * columns + j] = inputFloat();
        }
    }
    Matrix<float> *matrix = new Matrix<float>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<complex<float>> *inputMatrixComplex() {
    std::cout << "Input number of rows: ";
    int rows = inputNatural();
    std::cout << "Input number of columns: ";
    int columns = inputNatural();
    complex<float> *items = new complex<float>[rows * columns];
    int re;
    int im;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column:\n";
            cout << "Input real part: ";
            re = inputFloat();
            cout << "Input imaginary part: ";
            im = inputFloat();
            items[i * columns + j] = complex<float>(re, im);
        }
    }
    Matrix<complex<float>> *matrix = new Matrix<complex<float>>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<complex<float>> *inputMatrixComplex(int rows, int columns) {
    complex<float> *items = new complex<float>[rows * columns];
    int re;
    int im;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column:\n";
            cout << "Input real part: ";
            re = inputFloat();
            cout << "Input imaginary part: ";
            im = inputFloat();
            items[i * columns + j] = complex<float>(re, im);
        }
    }
    Matrix<complex<float>> *matrix = new Matrix<complex<float>>(items, rows, columns);
    delete [] items;
    return matrix;
}

Matrix<complex<float>> *inputMatrixComplex(int rows) {
    std::cout << "Input number of columns: ";
    int columns = inputNatural();
    complex<float> *items = new complex<float>[rows * columns];
    int re;
    int im;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Input element on " << i << " row, " << j << " column:\n";
            cout << "Input real part: ";
            re = inputFloat();
            cout << "Input imaginary part: ";
            im = inputFloat();
            items[i * columns + j] = complex<float>(re, im);
        }
    }
    Matrix<complex<float>> *matrix = new Matrix<complex<float>>(items, rows, columns);
    delete [] items;
    return matrix;
}

Polynomial<int> *inputPolynomialInt() {
    cout << "Input degree: ";
    int deg = inputNotNegative();
    cout << "Input coefficients:\n";
    int *items = new int[deg + 1];
    for (int i = 0; i <= deg; i++) {
        cout << "a" << i << " = ";
        items[i] = inputInt();
    }
    Polynomial<int> *p = new Polynomial<int>(items, deg + 1);
    delete [] items;
    return p;
}

Polynomial<float> *inputPolynomialFloat() {
    cout << "Input degree: ";
    int deg = inputNotNegative();
    cout << "Input coefficients:\n";
    float *items = new float[deg + 1];
    for (int i = 0; i <= deg; i++) {
        cout << "a" << i << " = ";
        items[i] = inputFloat();
    }
    Polynomial<float> *p = new Polynomial<float>(items, deg + 1);
    delete [] items;
    return p;
}

Polynomial<complex<float>> *inputPolynomialComplex() {
    cout << "Input degree: ";
    int deg = inputNotNegative();
    cout << "Input coefficients:\n";
    complex<float> *items = new complex<float>[deg + 1];
    for (int i = 0; i <= deg; i++) {
        cout << "a" << i << ":\n";
        items[i] = inputComplex();
    }
    Polynomial<complex<float>> *p = new Polynomial<complex<float>>(items, deg + 1);
    delete [] items;
    return p;
}

Matrix<float> inputSquareMatrix(int n) {
    float *items = new float[n * n];
    cout << "Input elemets:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Input element on " << i << " row, " << j << " column: ";
            items[i * n + j] = inputFloat();
        }
    }
    Matrix<float> matrix(items, n);
    delete [] items;
    return matrix;
}

Polynomial<Matrix<float>> *inputPolynomialMatrix() {
    cout << "Input degree: ";
    int deg = inputNotNegative();
    cout << "Input number of rows and columns: ";
    int n = inputInt(); 
    cout << "Input coefficients:\n";
    Matrix<float> items[deg + 1];
    for (int i = 0; i <= deg; i++) {
        cout << "a" << i << ":\n";
        items[i] = inputSquareMatrix(n);
    }
    Polynomial<Matrix<float>> *p = new Polynomial<Matrix<float>>(items, deg + 1);
    return p;
}