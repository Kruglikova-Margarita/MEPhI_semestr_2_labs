#include <iostream>
#include "../../SequenceClasses/Sequence.h"
#include "testArraySequence.h"

void testArraySequence() {
    int error = 0;
    std::cout << "== Testing functions of the ArraySequence class ==\n";

    testArrayGetFirst(&error);
    testArrayGetLast(&error);
    testArrayGet(&error);
    testArrayGetSubSequence(&error);
    testArrayGetLength(&error);
    testArrayAppend(&error);
    testArrayPrepend(&error);
    testArrayInsertAt(&error);
    testArrayDelete(&error);
    testArrayConcat(&error);
    testArrayOperator1(&error);
    testArrayOperator2(&error);
    testArrayOperator3(&error);
    testArrayMap(&error);
    testArrayWhere(&error);
    testArrayReduce(&error);

    if (error == 0) std::cout << "All functions of the ArraySequence class were successfully passed\n";
    else std::cout << "Error! Not all functions of the ArraySequence class were successfully passed\n";
}

void testArrayGetFirst(int *error) {
    int *ar = new int[2];
    ar[0] = 1;
    ar[1] = 2;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 2);
    int first1 = s1->GetFirst();
    Sequence<int> *s2 = new ArraySequence<int>;

    bool correct = false;
    try {
        int first2 = s2->GetFirst();
    }
    catch (...) {
        correct = true;
    }

    if ((first1 == 1) && (correct == true)) std::cout << "GetFirst       : passed\n";
    else {
        std::cout << "GetFirst       : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
}

void testArrayGetLast(int *error) {
    int *ar = new int[2];
    ar[0] = 1;
    ar[1] = 2;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 2);
    int last1 = s1->GetLast();
    Sequence<int> *s2 = new ArraySequence<int>;

    bool correct = false;
    try {
        int last2 = s2->GetFirst();
    }
    catch (...) {
        correct = true;
    }

    if ((last1 == 2) && (correct == true)) std::cout << "GetLast        : passed\n";
    else {
        std::cout << "GetLast        : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
}

void testArrayGet(int *error) {
    int *ar = new int[4];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    Sequence<int> *s = new ArraySequence<int>(ar, 4);
    int el1 = s->Get(2);

    bool correct1 = false;
    try {
        int el2 = s->Get(-1);
    }
    catch (...) {
        correct1 = true;
    }

    bool correct2 = false;
    try {
        int el3 = s->Get(5);
    }
    catch (...) {
        correct2 = true;
    }

    if ((el1 == 3) && (correct1 == true) && (correct2 == true)) std::cout << "Get            : passed\n";
    else {
        std::cout << "Get            : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s;
}

void testArrayGetSubSequence(int *error) {
    int *ar = new int[7];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    ar[6] = 7;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 7);
    Sequence<int> *s2 = new ArraySequence<int>(ar + 2, 3);
    Sequence<int> *subS1 = s1->GetSubSequence(2, 4);

    bool correct1 = false;
    try {
        Sequence<int> *subS2 = s1->GetSubSequence(-1, 3);
    }
    catch (...) {
        correct1 = true;
    }

    bool correct2 = false;
    try {
        Sequence<int> *subS3 = s1->GetSubSequence(2, 10);
    }
    catch (...) {
        correct2 = true;
    }

    bool correct3 = false;
    try {
        Sequence<int> *subS4 = s1->GetSubSequence(5, 1);
    }
    catch (...) {
        correct3 = true;
    }

    if (((*s2) == (*subS1)) && correct1 && correct2 && correct3) std:: cout << "GetSubSequence : passed\n";
    else {
        std::cout << "GetSubSequence : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete subS1;
}

void testArrayGetLength(int *error) {
    int *ar = new int[7];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    ar[6] = 7;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 7);
    size_t len1 = s1->GetLength();
    Sequence<int> *s2 = new ArraySequence<int>;
    size_t len2 = s2->GetLength();

    if ((len1 == 7) && (len2 == 0)) std::cout << "GetLength      : passed\n";
    else {
        std::cout << "GetLength      : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
}

void testArrayAppend(int *error) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 5);
    Sequence<int> *s2 = new ArraySequence<int>(ar, 4);
    s2->Append(5);

    Sequence<int> *s3 = new ArraySequence<int>(ar, 1);
    Sequence<int> *s4 = new ArraySequence<int>;
    s4->Append(1);

    if (((*s1) == (*s2)) && ((*s3) == (*s4))) std::cout << "Append         : passed\n";
    else {
        std::cout << "Append         : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void testArrayPrepend(int *error) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 5);
    Sequence<int> *s2 = new ArraySequence<int>(ar + 1, 4);
    s2->Prepend(1);

    Sequence<int> *s3 = new ArraySequence<int>(ar, 1);
    Sequence<int> *s4 = new ArraySequence<int>;
    s4->Prepend(1);

    if (((*s1) == (*s2)) && ((*s3) == (*s4))) std::cout << "Prepend        : passed\n";
    else {
        std::cout << "Prepend        : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void testArrayInsertAt(int *error) {
    int *ar1 = new int[4];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 4;
    ar1[3] = 5;

    int *ar2 = new int[5];
    ar2[0] = 1;
    ar2[1] = 2;
    ar2[2] = 3;
    ar2[3] = 4;
    ar2[4] = 5;

    Sequence<int> *s1 = new ArraySequence<int>(ar1, 4);
    Sequence<int> *s2 = new ArraySequence<int>(ar2, 5);
    s1->InsertAt(3, 2);

    bool correct1 = false;
    try {
        s1->InsertAt(1, -1);
    }
    catch (...) {
        correct1 = true;
    }

    bool correct2 = false;
    try {
        s1->InsertAt(1, 10);
    }
    catch (...) {
        correct2 = true;
    }

    if (((*s1) == (*s2)) && correct1 && correct2) std::cout << "InsertAt       : passed\n";
    else {
        std::cout << "InsertAt       : failed\n";
        (*error) = 1;
    }

    delete [] ar1;
    delete [] ar2;
    delete s1;
    delete s2;
}

void testArrayDelete(int *error) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 3);
    Sequence<int> *s2 = new ArraySequence<int>(ar + 1, 2);
    Sequence<int> *s3 = new ArraySequence<int>(ar + 1, 1);
    Sequence<int> *s4 = new ArraySequence<int>;
    bool correct1 = false;
    try {
        s1->Delete(-2);
    }
    catch (...) {
        correct1 = true;
    }
    bool correct2 = false;
    try {
        s1->Delete(10);
    }
    catch (...) {
        correct2 = true;
    }
    int correct3 = 0;
    s1->Delete(0);
    if ((*s1) == (*s2)) correct3++;
    s1->Delete(1);
    if ((*s1) == (*s3)) correct3++;
    s1->Delete(0);
    if ((*s1) == (*s4)) correct3++;

    if (correct1 && correct2 && (correct3 == 3)) std::cout << "Delete         : passed\n";
    else {
        std::cout << "Delete         : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void testArrayConcat(int *error) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 2);
    Sequence<int> *s2 = new ArraySequence<int>(ar + 2, 3);
    Sequence<int> *s3 = new ArraySequence<int>(ar, 5);
    Sequence<int> *s4 = s1->Concat(s2);
    Sequence<int> *s5 = new ArraySequence<int>;
    Sequence<int> *s6 = s1->Concat(s5);
    Sequence<int> *s7 = s5->Concat(s1);

    if (((*s3) == (*s4)) && ((*s1) == (*s6)) && ((*s1) == (*s7))) std::cout << "Concat         : passed\n";
    else {
        std::cout << "Concat         : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
}

void testArrayOperator1(int *error) {
    int *ar = new int[4];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    Sequence<int> *s = new ArraySequence<int>(ar, 4);
    int el1 = (*s)[2];

    bool correct1 = false;
    try {
        int el2 = (*s)[-1];
    }
    catch (...) {
        correct1 = true;
    }

    bool correct2 = false;
    try {
        int el3 = (*s)[5];
    }
    catch (...) {
        correct2 = true;
    }

    if ((el1 == 3) && (correct1 == true) && (correct2 == true)) std::cout << "Operator []    : passed\n";
    else {
        std::cout << "Operator []    : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s;
}

void testArrayOperator2(int *error) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 2);
    Sequence<int> *s2 = new ArraySequence<int>(ar + 2, 3);
    Sequence<int> *s3 = new ArraySequence<int>(ar, 5);
    Sequence<int> *s4 = (*s1) + (*s2);
    Sequence<int> *s5 = new ArraySequence<int>;
    Sequence<int> *s6 = (*s1) + (*s5);
    Sequence<int> *s7 = (*s5) + (*s1);

    if (((*s3) == (*s4)) && ((*s1) == (*s6)) && ((*s1) == (*s7))) std::cout << "Operator +     : passed\n";
    else {
        std::cout << "Operator +     : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
}

void testArrayOperator3(int *error) {
    int *ar = new int[4];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 4);
    Sequence<int> *s2 = new ArraySequence<int>;
    Sequence<int> *s3 = new ArraySequence<int>(ar, 3);
    s3->Append(10);

    if ((!((*s1) == (*s2))) && (!((*s1) == (*s3))) && ((*s1) == (*s1))) std::cout << "Operator ==    : passed\n";
    else {
        std::cout << "Operator ==    : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
    delete s3;
}

int fMap1(int el) {
    return (2 * el);
}

void testArrayMap(int *error) {
    int *ar1 = new int[4];
    ar1[0] = 1;
    ar1[1] = 2;
    ar1[2] = 3;
    ar1[3] = 4;
    int *ar2 = new int[4];
    ar2[0] = 2;
    ar2[1] = 4;
    ar2[2] = 6;
    ar2[3] = 8;
    Sequence<int> *s1 = new ArraySequence<int>(ar1, 4);
    Sequence<int> *s2 = new ArraySequence<int>(ar2, 4);
    Sequence<int> *s3 = s1->Map(fMap1);
    Sequence<int> *s4 = new ArraySequence<int>;
    Sequence<int> *s5 = s4->Map(fMap1);

    if (((*s2) == (*s3)) && ((*s4) == (*s5))) std::cout << "Map            : passed\n";
    else {
        std::cout << "Map            : failed\n";
        (*error) = 1;
    }

    delete [] ar1;
    delete [] ar2;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
}

bool fWhere1(int el) {
    if (el % 2 == 0) return true;
    return false;
}

void testArrayWhere(int *error) {
    int *ar1 = new int[8];
    ar1[0] = 4;
    ar1[1] = 2;
    ar1[2] = 9;
    ar1[3] = 13;
    ar1[4] = 42;
    ar1[5] = -4;
    ar1[6] = 5;
    ar1[7] = 1;
    int *ar2 = new int[4];
    ar2[0] = 4;
    ar2[1] = 2;
    ar2[2] = 42;
    ar2[3] = -4;
    Sequence<int> *s1 = new ArraySequence<int>(ar1, 8);
    Sequence<int> *s2 = new ArraySequence<int>(ar2, 4);
    Sequence<int> *s3 = s1->Where(fWhere1);
    Sequence<int> *s4 = new ArraySequence<int>;
    Sequence<int> *s5 = s4->Where(fWhere1);

    if (((*s2) == (*s3)) && ((*s4) == (*s5))) std::cout << "Where          : passed\n";
    else {
        std::cout << "Where          : failed\n";
        (*error) = 1;
    }

    delete [] ar1;
    delete [] ar2;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
}

int fReduce1(int a, int b) {
    return (a + b);
}

void testArrayReduce(int *error) {
    int *ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    Sequence<int> *s1 = new ArraySequence<int>(ar, 5);
    int r1 = s1->Reduce(fReduce1, 10);
    Sequence<int> *s2 = new ArraySequence<int>;
    bool correct = false;
    try {
        int r2 = s2->Reduce(fReduce1, 10);
    }
    catch (...) {
        correct = true;
    }

    if ((r1 == 25) && correct) std::cout << "Reduce         : passed\n";
    else {
        std::cout << "Reduce         : failed\n";
        (*error) = 1;
    }

    delete [] ar;
    delete s1;
    delete s2;
}