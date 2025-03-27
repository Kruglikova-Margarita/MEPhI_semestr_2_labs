#include <iostream>
#include "../../MainClasses/Queue.hpp"
#include "testsQueue.hpp"

using namespace std;

void testsQueue() {
    bool check = true;
    cout << "== Tesing functions of the Queue class ==\n";

    testEnqueue(&check);
    testDequeue(&check);
    testGetLength(&check);
    testOperator1Queue(&check);
    testMap(&check);
    testWhere(&check);
    testReduce(&check);
    testOperator2Queue(&check);
    testGetSubQueue(&check);
    testContains(&check);
    testFind(&check);
    testConnect(&check);
    testSeparation(&check);
    testOperator3Queue(&check);

    if (check) cout << "All functions of the Queue class are correct\n";
    else cout << "Error! Not all functions of the Queue class are correct\n";
}

void testEnqueue(bool *check) {
    int *ar = new int[2];
    ar[0] = 1;
    ar[1] = 2;
    Queue<int> q0;
    Queue<int> q1(ar, 1);
    Queue<int> q2(ar, 2);
    q0.Enqueue(1);
    bool check1 = (q0 == q1);
    q1.Enqueue(2);
    bool check2 = (q1 == q2);
    if (check1 && check2) cout << "Enqueue     : passed\n";
    else {
        cout << "Enqueue     : failed\n";
        (*check) = false;
    }
    
    delete [] ar;
}

void testDequeue(bool *check) {
    int *ar = new int[2];
    ar[0] = 1;
    ar[1] = 2;
    Queue<int> q1;
    bool check1 = false;
    try {
        q1.Dequeue();
    }
    catch (...) {
        check1 = true;
    }
    Queue<int> q2(ar, 2);
    int d = q2.Dequeue();
    Queue<int> q3(ar + 1, 1);
    bool check2 = (q2 == q3);
    if (check1 && check2 && (d == 1)) cout << "Dequeue     : passed\n";
    else {
        cout << "Dequeue     : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testGetLength(bool *check) {
    int *ar = new int[2];
    ar[0] = 1;
    ar[1] = 2;
    Queue<int> q0;
    Queue<int> q1(ar, 2);
    int len0 = q0.GetLength();
    int len1 = q1.GetLength();
    if ((len0 == 0) && (len1 == 2)) cout << "GetLength   : passed\n";
    else {
        cout << "GetLength   : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testOperator1Queue(bool *check) {
    int *ar = new int[3];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    Queue<int> q(ar, 3);
    int el1 = q[1];
    bool check1 = false;
    bool check2 = false;
    try {
        int el = q[-1];
    }
    catch(...) {
        check1 = true;
    }

    try {
        int el = q[5];
    }
    catch(...) {
        check2 = true;
    }

    if ((el1 == 2) && check1 && check2) cout << "Operator [] : passed\n";
    else {
        cout << "Operator [] : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

int f1(int a) {
    return 2 * a;
}

void testMap(bool *check) {
    int *ar1 = new int[3];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    int *ar2 = new int[3];
    ar2[0] = 2;
    ar2[1] = 4;
    ar2[2] = 6;
    Queue<int> q0;
    Queue<int> q1(ar1, 3);
    Queue<int> *q2 = q1.Map(f1);
    Queue<int> q3(ar2, 3);
    Queue<int> *q4 = q0.Map(f1);
    if (((*q2) == q3) && (q0 == (*q4))) cout << "Map         : passed\n";
    else {
        cout << "Map         : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete q2;
    delete q4;
}

bool f2(int a) {
    if (a % 2 == 0) return true;
    return false;
}

void testWhere(bool *check) {
    int *ar1 = new int[4];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    int *ar2 = new int[2];
    ar2[0] = 2;
    ar2[1] = 4;
    Queue<int> q0;
    Queue<int> *q1 = q0.Where(f2);
    Queue<int> q2(ar1, 4);
    Queue<int> *q3 = q2.Where(f2);
    Queue<int> q4(ar2, 2);
    if ((q0 == (*q1)) && ((*q3) == q4)) cout << "Where       : passed\n";
    else {
        cout << "Where       : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete q1;
    delete q3;
}

int f3(int a, int b) {
    return a + b;
}

void testReduce(bool *check) {
    int *ar1 = new int[3];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    Queue<int> q0;
    bool check1 = false;
    try {
        int r = q0.Reduce(f3, 5);
    }
    catch (...) {
        check1 = true;
    }
    Queue<int> q1(ar1, 3);
    int r = q1.Reduce(f3, 5);
    if (check1 && (r == 11)) cout << "Reduce      : passed\n";
    else {
        cout << "Reduce      : failed\n";
        (*check) = false;
    }
    delete [] ar1;
}

void testOperator2Queue(bool *check) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Queue<int> q0;
    Queue<int> *q1 = q0 + q0;
    Queue<int> q2(ar, 3);
    Queue<int> q3(ar + 3, 2);
    Queue<int> *q4 = q2 + q3;
    Queue<int> q5(ar, 5);
    if ((q0 == (*q1)) && ((*q4) == q5)) cout << "Operator +  : passed\n";
    else {
        cout << "Operator +  : failed\n";
        (*check) = false;
    }
    delete [] ar;
    delete q1;
    delete q4;
}

void testGetSubQueue(bool *check) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Queue<int> q1(ar, 5);
    bool check1 = false;
    try {
        Queue<int> *q2 = q1.GetSubQueue(-1, 2);
    }
    catch (...) {
        check1 = true;
    }
    bool check2 = false;
    try {
        Queue<int> *q2 = q1.GetSubQueue(1, 10);
    }
    catch(...) {
        check2 = true;
    }
    Queue<int> *q2 = q1.GetSubQueue(1, 3);
    Queue<int> q3(ar + 1, 3);
    if (check1 && check2 && ((*q2) == q3)) cout << "GetSubQueue : passed\n";
    else {
        cout << "GetSubQueue : failed\n";
        (*check) = false;
    }
    delete [] ar;
    delete q2;
}

void testContains(bool *check) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Queue<int> q0;
    bool check1 = q0.Contains(q0);
    Queue<int> q1(ar, 5);
    bool check2 = q1.Contains(q1);
    Queue<int> q2(ar + 1, 2);
    bool check3 = q1.Contains(q2);
    bool check4 = q0.Contains(q1);
    if (check1 && check2 && check3 && !check4) cout << "Contains    : passed\n";
    else {
        cout << "Contains    : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testFind(bool *check) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Queue<int> q0;
    Queue<int> q1(ar, 3);
    Queue<int> q2(ar + 1, 2);
    Queue<int> q3(ar + 3, 2);
    int check1 = q0.Find(q1);
    int check2 = q1.Find(q0);
    int check3 = q1.Find(q2);
    int check4 = q1.Find(q3);
    int check5 = q2.Find(q1);
    if ((check1 == -1) && (check2 == -1) && (check3 == 1) && (check4 == -1) && (check5 == -1)) cout << "Find        : passed\n";
    else {
        cout << "Find        : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testConnect(bool *check) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Queue<int> q0;
    Queue<int> q1(ar, 3);
    Queue<int> q11(ar, 3);
    Queue<int> q2(ar + 3, 2);
    Queue<int> q3(ar, 5);
    q1.Connect(q0);
    bool check1 = (q1 == q11);
    q0.Connect(q1);
    bool check2 = (q0 == q1);
    q1.Connect(q2);
    bool check3 = (q1 == q3);
    if (check1 && check2 && check3) cout << "Connect     : passed\n";
    else {
        cout << "Connect     : failed\n";
        (*check) = false;
    }
    delete [] ar;
}

void testSeparation(bool *check) {
    int *ar1 = new int[4];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    int *ar2 = new int[2];
    ar2[0] = 2;
    ar2[1] = 4;
    int *ar3 = new int[2];
    ar3[0] = 1;
    ar3[1] = 3;
    Queue<int> q0;
    Queue<int> *q1 = q0.Separation(f2);
    Queue<int> q2(ar1, 4);
    Queue<int> q3(ar2, 2);
    Queue<int> q4(ar3, 2);
    Queue<int> *q5 = q2.Separation(f2);
    if ((q0 == (*q1)) && ((q2 == q4) && ((*q5) == q3))) cout << "Separation  : passed\n";
    else {
        cout << "Separation  : failed\n";
        (*check) = false;
    }
    delete [] ar1;
    delete [] ar2;
    delete [] ar3;
    delete q1;
    delete q5;
}

void testOperator3Queue(bool *check) {
    int *ar = new int[3];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    Queue<int> q1(ar, 2);
    Queue<int> q2(ar, 3);
    bool check1 = (q1 == q1);
    bool check2 = (q1 == q2);
    q1.Enqueue(5);
    bool check3 = (q1 == q2);
    if (check1 && !check2 && !check3) cout << "Operator == : passed\n";
    else {
        cout << "Operator == : failed\n";
        (*check) = false;
    }
    delete [] ar;
}