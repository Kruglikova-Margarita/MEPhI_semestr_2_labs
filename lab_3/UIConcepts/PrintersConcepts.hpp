#include <iostream>
#include <string>
#include <complex>

#include "../MainClasses/Queue.hpp"
#include "../MainClasses/Matrix.hpp"
#include "../MainClasses/Polynomial.hpp"

#include "../StoredClasses/Student.hpp"
#include "../StoredClasses/Teacher.hpp"

#include "Concepts.hpp"


#ifndef printers_h
#define printers_h

template <class T>
class Printers {
public:
    Printers() {}

    template <SimpleTypes T1>
    static void PrintItem(const T1 &item) noexcept {
        cout << item;
    }

    static void PrintItem(const complex<float> &z) noexcept {
        float re = z.real();
        float im = z.imag();
        cout << re << " + "<< im << " * i";
    }

    static void PrintItem(const Student &student) noexcept {
        int id = student.GetID();
        string firstName = student.GetFirstName();
        string middleName = student.GetMiddleName();
        string lastName = student.GetLastName();
        string group = student.GetGroup();
        cout << "ID:" << id << " " << firstName << " " << middleName << " " << lastName << " " << group << "\n";
    }

    static void PrintItem(const Teacher &teacher) noexcept {
        int id = teacher.GetID();
        string firstName = teacher.GetFirstName();
        string middleName = teacher.GetMiddleName();
        string lastName = teacher.GetLastName();
        string discipline = teacher.GetDiscipline();
        cout << "ID:" << id << " " << firstName << " " << middleName << " " << lastName << " " << discipline << "\n";
    }

    static void PrintItem(const Matrix<float> &matrix) noexcept {
        size_t m = matrix.GetRowsCount();
        size_t n = matrix.GetColumnsCount();
        if (m * n == 0) cout << "Impossible to print matrix, because it is empty\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                float el = matrix.GetElement(i, j);
                PrintItem(el);
                cout << "     ";
            }
            cout << "\n";
        }
    }


    template <StoredTypesQueue T1>
    static void PrintQueue(const Queue<T1> &queue) noexcept {
        size_t len = queue.GetLength();
        if (len == 0) std::cout << "Impossible to print queue, because it is empty\n";
        for (int i = 0; i < len; i++) {
            T1 item = queue[i];
            cout << "Queue[" << i << "] = ";
            PrintItem(item);
            cout << "\n";
        }
    }


    template <StoredTypesMatrix T1>
    static void PrintMatrix(const Matrix<T1> &matrix) noexcept {
        size_t m = matrix.GetRowsCount();
        size_t n = matrix.GetColumnsCount();
        if (m * n == 0) cout << "Impossible to print matrix, because it is empty\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                T1 el = matrix.GetElement(i, j);
                PrintItem(el);
                cout << "     ";
            }
            cout << "\n";
        }
    }


    template <class T1>
    requires(same_as<T1, int> || same_as<T1, float> || same_as<T1, complex<float>>)
    static void PrintPolynomial(const Polynomial<T1> &pol) noexcept {
        size_t deg = pol.GetDegree();
        if (deg == -1) cout << "Impossible to print polynomial, because it is empty\n";
        else {
            cout << "P(x) = ";
            T1 k;
            for (int i = deg; i > 1; i--) {
                k = pol.GetCoefficient(i);
                cout << "(";
                PrintItem(k);
                cout << ") * x^" << i << " + ";
            }
            if (deg > 0) {
                k = pol.GetCoefficient(1);
                cout << "(";
                PrintItem(k);
                cout << ") * x" << " + ";
            }
            k = pol.GetCoefficient(0);
            PrintItem(k);
            cout << "\n";
        }
    }

    static void PrintPolynomial(const Polynomial<Matrix<float>> &pol) noexcept {
        size_t deg = pol.GetDegree();
        if (deg == -1) cout << "Impossible to print polynomial, because it is empty\n";
        else {
            cout << "P(x) = \n";
            Matrix<float> k;
            for (int i = deg; i > 1; i--) {
                k = pol.GetCoefficient(i);
                PrintMatrix(k);
                cout << " * x^" << i << " + \n\n";
            }
            if (deg > 0) {
                k = pol.GetCoefficient(1);
                PrintMatrix(k);
                cout << " * x" << " + \n\n";
            }
            k = pol.GetCoefficient(0);
            PrintMatrix(k);
            cout << "\n";
        }
    }


    static void PrintSequence(const Sequence<T> &sequence) noexcept {
        size_t len = sequence.GetLength();
        if (len == 0) cout << "Impossible to print sequence, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                T el = sequence[i];
                cout << "Sequence[" << i << "] = " << el << "\n";
            }
        }
    }

};

#endif