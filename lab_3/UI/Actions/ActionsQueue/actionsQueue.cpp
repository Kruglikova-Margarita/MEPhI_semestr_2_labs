#include <iostream>
#include <complex>
#include <string>
#include "../../../MainClasses/Queue.hpp"
#include "../../../StoredClasses/Student.hpp"
#include "../../../StoredClasses/Teacher.hpp"
#include "../../Input/input.hpp"
#include "../../../Printers.hpp"

using namespace std;

void actionQueueInt2(Queue<int> *q) {
    cout << "Input number: ";
    int number = inputInt();
    q->Enqueue(number);
}

void actionQueueInt3(Queue<int> *q) {
    int first;
    try {
        first = q->Dequeue();
        cout << "First element of queue: " << first << "\n";
    }
    catch (out_of_range e) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}

void actionQueueInt4(Queue<int> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}

void actionQueueInt5(Queue<int> *q) {
    cout << "Input index: ";
    int index = inputNotNegative();
    int el;
    try {
        el = (*q)[index];
        cout << "Element on " << index << " place: " << el << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionQueueInt6(Queue<int> *q) {
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

void actionQueueInt7(Queue<int> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<int> *sub;
    Printers<int> printer;
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

void actionQueueInt8(Queue<int> *q) {
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    int *items = new int[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputInt();
    }
    Queue<int> q1(items, len);
    bool check = q->Contains(q1);
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueueInt9(Queue<int> *q) {
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    int *items = new int[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputInt();
    }
    Queue<int> q1(items, len);
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueueInt10(Queue<int> *q) {
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



void actionQueueFloat2(Queue<float> *q) {
    cout << "Input number: ";
    float number = inputFloat();
    q->Enqueue(number);
}

void actionQueueFloat3(Queue<float> *q) {
    float first;
    try {
        first = q->Dequeue();
        cout << "First element of queue: " << first << "\n";
    }
    catch (out_of_range e) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}

void actionQueueFloat4(Queue<float> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}

void actionQueueFloat5(Queue<float> *q) {
    cout << "Input index: ";
    int index = inputNotNegative();
    float el;
    try {
        el = (*q)[index];
        cout << "Element on " << index << " place: " << el << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionQueueFloat6(Queue<float> *q) {
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

void actionQueueFloat7(Queue<float> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<float> *sub;
    Printers<float> printer;
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

void actionQueueFloat8(Queue<float> *q) {
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    float *items = new float[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputFloat();
    }
    Queue<float> q1(items, len);
    bool check = q->Contains(q1);
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueueFloat9(Queue<float> *q) {
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    float *items = new float[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputFloat();
    }
    Queue<float> q1(items, len);
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueueFloat10(Queue<float> *q) {
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



void actionQueueComplex2(Queue<complex<float>> *q) {
    complex<float> z = inputComplex();
    q->Enqueue(z);
}

void actionQueueComplex3(Queue<complex<float>> *q) {
    complex<float> z;
    Printers<float> printer;
    try {
        z = q->Dequeue();
        cout << "First element of queue: ";
        printer.PrintComplex(z);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}

void actionQueueComplex4(Queue<complex<float>> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}

void actionQueueComplex5(Queue<complex<float>> *q) {
    cout << "Input index: ";
    int index = inputNotNegative();
    complex<float> z;
    Printers<float> printer;
    try {
        z = (*q)[index];
        cout << "Element on " << index << " place: ";
        printer.PrintComplex(z);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionQueueComplex6(Queue<complex<float>> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<float> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueueOfComplex(*q);
    } else {
        complex<float> *items = new complex<float>[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
        }
        Queue<complex<float>> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueueOfComplex(q1);
        Queue<complex<float>> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueueOfComplex(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueueComplex7(Queue<complex<float>> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<complex<float>> *sub;
    Printers<float> printer;
    try {
        sub = q->GetSubQueue(start, end);
        cout << "Sub queue:\n";
        printer.PrintQueueOfComplex(*sub);
        delete sub;
    }
    catch (out_of_range e) {
        cout << e.what();
    }
}

void actionQueueComplex8(Queue<complex<float>> *q) {
    cout << "Input length of new queue: ";
    int len = inputNatural();
    cout << "Input elements:\n";
    complex<float> *items = new complex<float>[len];
    for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
    }
    Queue<complex<float>> q1(items, len);
    bool check = q->Contains(q1);
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueueComplex9(Queue<complex<float>> *q) {
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    complex<float> *items = new complex<float>[len];
    for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
    }
    Queue<complex<float>> q1(items, len);
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueueComplex10(Queue<complex<float>> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<float> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueueOfComplex(*q);
    } else {
        complex<float> *items = new complex<float>[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            items[i] = inputComplex();
        }
        Queue<complex<float>> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueueOfComplex(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueueOfComplex(*q);
        delete [] items;
    }
}



void actionQueueString2(Queue<string> *q) {
    cout << "Input string: ";
    string str;
    cin >> str;
    q->Enqueue(str);
}

void actionQueueString3(Queue<string> *q) {
    string first;
    try {
        first = q->Dequeue();
        cout << "First element of queue: " << first << "\n";
    }
    catch (out_of_range e) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}

void actionQueueString4(Queue<string> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}

void actionQueueString5(Queue<string> *q) {
    cout << "Input index: ";
    int index = inputNotNegative();
    string el;
    try {
        el = (*q)[index];
        cout << "Element on " << index << " place: " << el << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionQueueString6(Queue<string> *q) {
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

void actionQueueString7(Queue<string> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<string> *sub;
    Printers<string> printer;
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

void actionQueueString8(Queue<string> *q) {
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
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueueString9(Queue<string> *q) {
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    string *items = new string[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        cin >> items[i];
    }
    Queue<string> q1(items, len);
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueueString10(Queue<string> *q) {
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



void actionQueueStudents2(Queue<Student> *q) {
    Student s = inputStudent();
    q->Enqueue(s);
}

void actionQueueStudents3(Queue<Student> *q) {
    Student first;
    Printers<int> printer;
    try {
        first = q->Dequeue();
        cout << "First element of queue: ";
        printer.PrintStudent(first);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}

void actionQueueStudents4(Queue<Student> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}

void actionQueueStudents5(Queue<Student> *q) {
    cout << "Input index: ";
    int index = inputNotNegative();
    Student el;
    Printers<int> printer;
    try {
        el = (*q)[index];
        cout << "Element on " << index << " place: ";
        printer.PrintStudent(el);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionQueueStudents6(Queue<Student> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueueOfStudents(*q);
    } else {
        Student *items = new Student[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputStudent();
        }
        Queue<Student> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueueOfStudents(q1);
        Queue<Student> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueueOfStudents(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueueStudents7(Queue<Student> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<Student> *sub;
    Printers<int> printer;
    try {
        sub = q->GetSubQueue(start, end);
        cout << "Sub queue:\n";
        printer.PrintQueueOfStudents(*sub);
        delete sub;
    }
    catch (out_of_range e) {
        cout << e.what();
    }
}

void actionQueueStudents8(Queue<Student> *q) {
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
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueueStudents9(Queue<Student> *q) {
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    Student *items = new Student[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputStudent();
    }
    Queue<Student> q1(items, len);
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueueStudents10(Queue<Student> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueueOfStudents(*q);
    } else {
        Student *items = new Student[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputStudent();
        }
        Queue<Student> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueueOfStudents(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueueOfStudents(*q);
        delete [] items;
    }
}



void actionQueueTeachers2(Queue<Teacher> *q) {
    Teacher t = inputTeacher();
    q->Enqueue(t);
}

void actionQueueTeachers3(Queue<Teacher> *q) {
    Teacher first;
    Printers<int> printer;
    try {
        first = q->Dequeue();
        cout << "First element of queue: ";
        printer.PrintTeacher(first);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << "Impossible to get first element because queue is empty\n";
    }
}

void actionQueueTeachers4(Queue<Teacher> *q) {
    int len = q->GetLength();
    cout << "Length of queue: " << len << "\n";
}

void actionQueueTeachers5(Queue<Teacher> *q) {
    cout << "Input index: ";
    int index = inputNotNegative();
    Teacher el;
    Printers<int> printer;
    try {
        el = (*q)[index];
        cout << "Element on " << index << " place: ";
        printer.PrintTeacher(el);
        cout << "\n";
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionQueueTeachers6(Queue<Teacher> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "Concated queue:\n";
        printer.PrintQueueOfTeachers(*q);
    } else {
        Teacher *items = new Teacher[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputTeacher();
        }
        Queue<Teacher> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueueOfTeachers(q1);
        Queue<Teacher> *q2 = (*q) + q1;
        cout << "Result queue:\n";
        printer.PrintQueueOfTeachers(*q2);
        delete q2;
        delete [] items;
    }
}

void actionQueueTeachers7(Queue<Teacher> *q) {
    cout << "Input start index: ";
    int start = inputNotNegative();
    cout << "Input end index: ";
    int end = inputNotNegative();
    Queue<Teacher> *sub;
    Printers<int> printer;
    try {
        sub = q->GetSubQueue(start, end);
        cout << "Sub queue:\n";
        printer.PrintQueueOfTeachers(*sub);
        delete sub;
    }
    catch (out_of_range e) {
        cout << e.what();
    }
}

void actionQueueTeachers8(Queue<Teacher> *q) {
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
    if (check) cout << "Original queue contains entered queue\n";
    else cout << "Original queue doesn't contain entered queue\n";
    delete [] items;
}

void actionQueueTeachers9(Queue<Teacher> *q) {
    cout << "Input length of new queue:";
    int len = inputNatural();
    cout << "Input elements:\n";
    Teacher *items = new Teacher[len];
    for (int i = 0; i < len; i++) {
        cout << i << " element: ";
        items[i] = inputTeacher();
    }
    Queue<Teacher> q1(items, len);
    int index = q->Find(q1);
    if (index == -1) cout << "Original queue doesn't contain entered queue\n";
    else cout << "The index, where entered queue started in original queue: " << index << "\n";
    delete [] items;
}

void actionQueueTeachers10(Queue<Teacher> *q) {
    cout << "Input length of added queue: ";
    int len = inputNotNegative();
    Printers<int> printer;
    if (len == 0) {
        cout << "New queue:\n";
        printer.PrintQueueOfTeachers(*q);
    } else {
        Teacher *items = new Teacher[len];
        cout << "Input elements:\n";
        for (int i = 0; i < len; i++) {
            cout << i << " element: ";
            items[i] = inputTeacher();
        }
        Queue<Teacher> q1(items, len);
        cout << "Added queue:\n";
        printer.PrintQueueOfTeachers(q1);
        q->Connect(q1);
        cout << "New queue:\n";
        printer.PrintQueueOfTeachers(*q);
        delete [] items;
    }
}
