#include <iostream>
#include <string>
#include <complex>
#include "SequenceClasses/DinamicArray.hpp"
#include "SequenceClasses/LinkedList.hpp"
#include "SequenceClasses/Sequence.hpp"
#include "StoredClasses/Student.hpp"
#include "StoredClasses/Teacher.hpp"
#include "Tuple.hpp"

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

    template <class T1, class T2>
    static void PrintTuple(const Tuple<T1, T2> &tuple) noexcept {
        T1 item1 = tuple.GetItem1();
        T2 item2 = tuple.GetItem2();
        cout << "(" << item1 << "; " << item2 << ")";
    }

    template <class T1, class T2>
    static void PrintSequenceOfTuples(const Sequence<Tuple<T1, T2>> &sequence) noexcept {
        size_t len = sequence.GetLength();
        if (len == 0) cout << "Impossible to print sequence, because it is empty\n";
        else {
            cout << "{";
            for (int i = 0; i < len; i++) {
                Tuple<T1, T2> el = sequence[i];
                PrintTuple(el);
                if (i != len - 1) cout << ",  ";
            }
            cout << "}\n";
        }
    }

    static void PrintSequenceLine(const Sequence<T> &sequence) noexcept {
        size_t len = sequence.GetLength();
        if (len == 0) cout << "Impossible to print sequence, because it is empty\n";
        else {
            cout << "{";
            for (int i = 0; i < len - 1; i++) {
                T el = sequence[i];
                cout << el << "; ";
            }
            T el = sequence[len - 1];
            cout << el << "}\n";
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

    static void PrintTeacher(const Teacher &teacher) noexcept {
        int id = teacher.GetID();
        string firstName = teacher.GetFirstName();
        string middleName = teacher.GetMiddleName();
        string lastName = teacher.GetLastName();
        string discipline = teacher.GetDiscipline();
        cout << "ID:" << id << " " << firstName << " " << middleName << " " << lastName << " " << discipline << "\n";
    }

    static void PrintComplex(const complex<T> &z) noexcept {
        T re = z.real();
        T im = z.imag();
        cout << re << " + "<< im << " * i";
    }


};

#endif