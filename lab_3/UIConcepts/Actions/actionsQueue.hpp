#include <iostream>
#include <complex>
#include <string>

#include "../../MainClasses/Queue.hpp"

#include "../../StoredClasses/Student.hpp"
#include "../../StoredClasses/Teacher.hpp"

#include "../../UI/Input/input.hpp"
#include "../../UI/Menu/menu.hpp"

#include "../PrintersConcepts.hpp"
#include "../Concepts.hpp"

using namespace std;

#ifndef actionsQueue_h
#define actionsQueue_h

void actionQueue2(Queue<int> *q) {
    cout << "Input number: ";
    int number = inputInt();
    q->Enqueue(number);
}

void actionQueue2(Queue<float> *q) {
    cout << "Input number: ";
    float number = inputFloat();
    q->Enqueue(number);
}

void actionQueue2(Queue<complex<float>> *q) {
    cout << "Input number:\n";
    complex<float> z = inputComplex();
    q->Enqueue(z);
}

void actionQueue2(Queue<string> *q) {
    cout << "Input string: ";
    string str;
    cin >> str;
    q->Enqueue(str);
}

void actionQueue2(Queue<Student> *q) {
    Student s = inputStudent();
    q->Enqueue(s);
}

void actionQueue2(Queue<Teacher> *q) {
    Teacher t = inputTeacher();
    q->Enqueue(t);
}



template <StoredTypesQueue T>
void actionQueue3(Queue<T> *q) {
    Printers<T> printer;
    try {
        T first = q->Dequeue();
        cout << "First element of queue: ";
        printer.PrintItem(first);
        cout << "\n";
    }
    catch(...) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}



template <StoredTypesQueue T>
void actionQueue4(Queue<T> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}



template <StoredTypesQueue T>
void actionQueue5(Queue<T> *q) {
    Printers<T> printer;
    cout << "Input index: ";
    int index = inputNotNegative();
    try {
        T el = (*q)[index];
        cout << "Element on " << index << " place: ";
        printer.PrintItem(el);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}



void actionQueue6(Queue<int> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueue(*q);
    } else {
        int *items = new int[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputInt();
        }
        Queue<int> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        Queue<int> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueue(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueue6(Queue<float> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<float> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueue(*q);
    } else {
        float *items = new float[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputFloat();
        }
        Queue<float> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        Queue<float> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueue(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueue6(Queue<complex<float>> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<float> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueue(*q);
    } else {
        complex<float> *items = new complex<float>[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
        }
        Queue<complex<float>> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        Queue<complex<float>> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueue(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueue6(Queue<string> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<string> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueue(*q);
    } else {
        string *items = new string[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            cin >> items[i];
        }
        Queue<string> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        Queue<string> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueue(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueue6(Queue<Student> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueue(*q);
    } else {
        Student *items = new Student[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputStudent();
        }
        Queue<Student> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        Queue<Student> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueue(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueue6(Queue<Teacher> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueue(*q);
    } else {
        Teacher *items = new Teacher[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputTeacher();
        }
        Queue<Teacher> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        Queue<Teacher> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueue(*q2);
        delete q2;
        delete [] items;
    }
}



template <StoredTypesQueue T>
void actionQueue7(Queue<T> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<T> *sub;
    Printers<T> printer;
    try {
        sub = q->GetSubQueue(start, end);
        cout << "Sub queue:\n";
        printer.PrintQueue(*sub);
        delete sub;
    }
    catch (out_of_range e) {
        cout << e.what();
    }
}



void actionQueue8(Queue<int> *q) {
    Printers<int> printer;
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    int *items = new int[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputInt();
    }
    Queue<int> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    bool check = q->Contains(q1);
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueue8(Queue<float> *q) {
    Printers<float> printer;
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    float *items = new float[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputFloat();
    }
    Queue<float> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    bool check = q->Contains(q1);
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueue8(Queue<complex<float>> *q) {
    Printers<complex<float>> printer;
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    complex<float> *items = new complex<float>[len];
    for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
    }
    Queue<complex<float>> q1(items, len);
    bool check = q->Contains(q1);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueue8(Queue<string> *q) {
    Printers<string> printer;
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    string *items = new string[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        cin >> items[i];
    }
    Queue<string> q1(items, len);
    bool check = q->Contains(q1);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueue8(Queue<Student> *q) {
    Printers<Student> printer;
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    Student *items = new Student[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputStudent();
    }
    Queue<Student> q1(items, len);
    bool check = q->Contains(q1);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueue8(Queue<Teacher> *q) {
    Printers<Teacher> printer;
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    Teacher *items = new Teacher[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputTeacher();
    }
    Queue<Teacher> q1(items, len);
    bool check = q->Contains(q1);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}



void actionQueue9(Queue<int> *q) {
    Printers<int> printer;
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    int *items = new int[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputInt();
    }
    Queue<int> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueue9(Queue<float> *q) {
    Printers<float> printer;
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    float *items = new float[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputFloat();
    }
    Queue<float> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueue9(Queue<complex<float>> *q) {
    Printers<complex<float>> printer;
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    complex<float> *items = new complex<float>[len];
    for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
    }
    Queue<complex<float>> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueue9(Queue<string> *q) {
    Printers<string> printer;
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    string *items = new string[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        cin >> items[i];
    }
    Queue<string> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueue9(Queue<Student> *q) {
    Printers<Student> printer;
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    Student *items = new Student[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputStudent();
    }
    Queue<Student> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueue9(Queue<Teacher> *q) {
    Printers<Teacher> printer;
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    Teacher *items = new Teacher[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputTeacher();
    }
    Queue<Teacher> q1(items, len);
    cout << "New queue:\n";
    printer.PrintQueue(q1);
    cout << "\n";
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}



void actionQueue10(Queue<int> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueue(*q);
    } else {
        int *items = new int[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputInt();
        }
        Queue<int> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueue(*q);
        delete [] items;
    }
}

void actionQueue10(Queue<float> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<float> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueue(*q);
    } else {
        float *items = new float[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputFloat();
        }
        Queue<float> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueue(*q);
        delete [] items;
    }
}

void actionQueue10(Queue<complex<float>> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<complex<float>> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueue(*q);
    } else {
        complex<float> *items = new complex<float>[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
        }
        Queue<complex<float>> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueue(*q);
        delete [] items;
    }
}

void actionQueue10(Queue<string> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<string> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueue(*q);
    } else {
        string *items = new string[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            cin >> items[i];
        }
        Queue<string> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueue(*q);
        delete [] items;
    }
}

void actionQueue10(Queue<Student> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueue(*q);
    } else {
        Student *items = new Student[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputStudent();
        }
        Queue<Student> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueue(*q);
        delete [] items;
    }
}

void actionQueue10(Queue<Teacher> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueue(*q);
    } else {
        Teacher *items = new Teacher[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputTeacher();
        }
        Queue<Teacher> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueue(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueue(*q);
        delete [] items;
    }
}



template <StoredTypesQueue T>
void actionsQueue(Queue<T> *queue) {
    Printers<T> printer;
    printMenuQueue();
    int action = chooseActionQueue();
    while (action != -1) {
        switch(action) {
            case(1):
                printer.PrintQueue(*queue);
                break;
            case(2):
                actionQueue2(queue);
                break;
            case(3):
                actionQueue3(queue);
                break;
            case(4):
                actionQueue4(queue);
                break;
            case(5):
                actionQueue5(queue);
                break;
            case(6):
                actionQueue6(queue);
                break;
            case(7):
                actionQueue7(queue);
                break;
            case(8):
                actionQueue8(queue);
                break;
            case(9):
                actionQueue9(queue);
                break;
            case(10):
                actionQueue10(queue);
                break;
            case(0):
                printMenuQueue();
                break;
        }
        action = chooseActionQueue();
    }
}

#endif