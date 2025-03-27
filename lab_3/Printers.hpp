#include <iostream>
#include <string>
#include <complex>
#include "SequenceClasses/DinamicArray.hpp"
#include "SequenceClasses/LinkedList.hpp"
#include "SequenceClasses/Sequence.hpp"
#include "MainClasses/Queue.hpp"
#include "MainClasses/Matrix.hpp"
#include "MainClasses/Polynomial.hpp"
#include "StoredClasses/Student.hpp"
#include "StoredClasses/Teacher.hpp"

#ifndef printers_h
#define printers_h

using namespace std;

template <class T>
class Printers {
public:
    Printers() {}

    static void PrintOption(const Option<T> &option) noexcept {
        bool hasValue = option.HasValue();
        if (hasValue) {
            T value = option.Get();
            cout << value << "\n";
        } else cout << "The value is not set\n";
    }

    static void PrintDinamicArray(const DinamicArray<T> &dinamicArray) noexcept {
        size_t len = dinamicArray.GetLength();
        if (len == 0) cout << "Impossible to print dinamic array, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                Option<T> option = dinamicArray.Get();
                cout << "DinamicArray[" << i << "] = ";
                PrintOption(option);
            }
        }
    }

    static void PrintLinkedList(const LinkedList<T> &list) noexcept {
        size_t len = list.GetLength();
        if (len == 0) cout << "Impossible to print linked list, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                T el = list.Get(i);
                cout << "LinkedList[" << i << "] = " << el << "\n";
            }
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

    static void PrintSequenceLine(const Sequence<T> &sequence) noexcept {
        size_t len = sequence.GetLength();
        if (len == 0) cout << "Impossible to print sequence, because it is empty\n";
        else {
            cout << "[";
            for (int i = 0; i < len - 1; i++) {
                T el = sequence[i];
                cout << el << "; ";
            }
            T el = sequence[len - 1];
            cout << el << "]\n";
        }
    }

    static void PrintQueue(const Queue<T> &queue) noexcept {
        size_t len = queue.GetLength();
        if (len == 0) cout << "Impossible to print queue, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                T el = queue[i];
                cout << "Queue[" << i << "] = " << el << "\n";
            }
        }
    }

    static void PrintMatrix(const Matrix<T> &matrix) noexcept {
        size_t m = matrix.GetRowsCount();
        size_t n = matrix.GetColumnsCount();
        if (m * n == 0) cout << "Impossible to print matrix, because it is empty\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                T el = matrix.GetElement(i, j);
                cout << el << "     ";
            }
            cout << "\n";
        }
    }

    static void PrintPolynomial(const Polynomial<T> &pol) noexcept {
        size_t deg = pol.GetDegree();
        if (deg == -1) cout << "Impossible to print polynomial, because it is empty\n";
        else {
            T k;
            cout << "P(x) = ";
            for (int i = deg; i > 1; i--) {
                k = pol.GetCoefficient(i);
                cout << k << " * x^" << i << " + ";
            }
            if (deg > 0) {
                k = pol.GetCoefficient(1);
                cout << k << " * x + ";
            }
            k = pol.GetCoefficient(0);
            cout << k << "\n";
        }
    }

    static void PrintStudent(const Student &student) noexcept {
        int id = student.GetID();
        string firstName = student.GetFirstName();
        string middleName = student.GetMiddleName();
        string lastName = student.GetLastName();
        string group = student.GetGroup();
        cout << "ID:" << id << " " << firstName << " " << middleName << " " << lastName << " " << group << "\n";
    }

    static void PrintQueueOfStudents(const Queue<Student> &queue) noexcept {
        size_t len = queue.GetLength();
        if (len == 0) std::cout << "Impossible to print queue, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                Student s = queue[i];
                cout << "Queue[" << i << "] : ";
                PrintStudent(s);
            }
        }
    }

    static void PrintTeacher(const Teacher &teacher) noexcept {
        int id = teacher.GetID();
        string firstName = teacher.GetFirstName();
        string middleName = teacher.GetMiddleName();
        string lastName = teacher.GetLastName();
        string discipline = teacher.GetDiscipline();
        cout << "ID:" << id << " " << firstName << " " << middleName << " " << lastName << " " << discipline << "\n";
    }

    static void PrintQueueOfTeachers(const Queue<Teacher> &queue) noexcept {
        size_t len = queue.GetLength();
        if (len == 0) std::cout << "Impossible to print queue, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                Teacher s = queue[i];
                cout << "Queue[" << i << "] : ";
                PrintTeacher(s);
            }
        }
    }

    static void PrintComplex(const complex<T> &z) noexcept {
        T re = z.real();
        T im = z.imag();
        cout << re << " + "<< im << " * i";
    }

    static void PrintQueueOfComplex(const Queue<complex<T>> &queue) noexcept {
        size_t len = queue.GetLength();
        if (len == 0) std::cout << "Impossible to print queue, because it is empty\n";
        for (int i = 0; i < len; i++) {
            complex z = queue[i];
            cout << "Queue[" << i << "] = ";
            PrintComplex(z);
            cout << "\n";
        }
    }

    static void PrintMatrixOfComplex(const Matrix<complex<T>> &matrix) noexcept {
        size_t m = matrix.GetRowsCount();
        size_t n = matrix.GetColumnsCount();
        if (m * n == 0) cout << "Impossible to print matrix, because it is empty\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                complex<T> z = matrix(i, j);
                PrintComplex(z);
                cout << "     ";
            }
            cout << "\n";
        }        
    }

    static void PrintPolynomialOfComplex(const Polynomial<complex<T>> &pol) noexcept {
        size_t deg = pol.GetDegree();
        if (deg == -1) cout << "Impossible to print polynomial, because it is empty\n";
        else {
            cout << "P(x) = ";
            complex<T> k;
            for (int i = deg; i > 1; i--) {
                k = pol.GetCoefficient(i);
                cout << "(";
                PrintComplex(k);
                cout << ") * x^" << i << " + ";
            }
            if (deg > 0) {
                k = pol.GetCoefficient(1);
                cout << "(";
                PrintComplex(k);
                cout << ") * x" << " + ";
            }
            k = pol.GetCoefficient(0);
            PrintComplex(k);
            cout << "\n";
        }
    }

    static void PrintPolynomialOfMatrix(const Polynomial<Matrix<T>> &pol) noexcept {
        size_t deg = pol.GetDegree();
        if (deg == -1) cout << "Impossible to print polynomial, because it is empty\n";
        else {
            cout << "P(x) = \n";
            Matrix<T> k;
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

    static void PrintSequenceOfSequences(const Sequence<Sequence<T>> &seq) noexcept {
        int len = seq->GetLength();
        if (len == 0) cout << "Impossible to print sequence, because it is empty\n";
        else {
            for (int i = 0; i < len; i++) {
                Sequence<T> sub = seq(i);
                PrintSequenceLine(sub);
            }
        }
    }

};

#endif