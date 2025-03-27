#include <stdlib.h>
#include <iostream>
#include <string>
#include <complex>
#include <getopt.h>

#include "../MainClasses/Queue.hpp"
#include "../MainClasses/Matrix.hpp"
#include "../MainClasses/Polynomial.hpp"
#include "../Printers.hpp"
#include "../StoredClasses/Student.hpp"

#include "Menu/menu.hpp"
#include "Input/input.hpp"
#include "Actions/ActionsAlgorithms/actionsAlgorithms.hpp"
#include "Actions/ActionsQueue/actionsQueue.hpp"
#include "Actions/ActionsMatrix/actionsMatrix.hpp"
#include "Actions/ActionsPolynomial/actionsPolynomial.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int flag = 0;
    const char *shortOptions = "";
    const struct option longOptions[] = {
        {"queue", no_argument, &flag, 1},
        {"matrix", no_argument, &flag, 2},
        {"polynomial", no_argument, &flag, 3},
        {"algorithm", no_argument, &flag, 4},
        {NULL, 0, NULL, 0}
    };
    while (getopt_long(argc, argv, shortOptions, longOptions, NULL) != -1);

    Printers<int> printerInt;
    Printers<float> printerFloat;
    Printers<string> printerString;

    int action;
    int type;

    switch (flag) {
        case(0):
            cout << "You should choose option\n";
            break;

        case(1): {
            printMenuOfTypesQueue();
            type = chooseTypeQueue();
            printMenuQueue();
            switch(type) {
                case(1): {
                    Queue<int> *queue1 = new Queue<int>;
                    action = chooseActionQueue();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuQueue();
                                break;
                            case(1):
                                printerInt.PrintQueue(*queue1);
                                break;
                            case(2):
                                actionQueueInt2(queue1);
                                break;
                            case(3):
                                actionQueueInt3(queue1);
                                break;
                            case(4):
                                actionQueueInt4(queue1);
                                break;
                            case(5):
                                actionQueueInt5(queue1);
                                break;
                            case(6):
                                actionQueueInt6(queue1);
                                break;
                            case(7):
                                actionQueueInt7(queue1);
                                break;
                            case(8):
                                actionQueueInt8(queue1);
                                break;
                            case(9):
                                actionQueueInt9(queue1);
                                break;
                            case(10):
                                actionQueueInt10(queue1);
                                break;
                        }
                        action = chooseActionQueue();
                    }
                    delete queue1;
                    break;
                }
                case(2): {
                    Queue<float> *queue2 = new Queue<float>;
                    action = chooseActionQueue();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuQueue();
                                break;
                            case(1):
                                printerFloat.PrintQueue(*queue2);
                                break;
                            case(2):
                                actionQueueFloat2(queue2);
                                break;
                            case(3):
                                actionQueueFloat3(queue2);
                                break;
                            case(4):
                                actionQueueFloat4(queue2);
                                break;
                            case(5):
                                actionQueueFloat5(queue2);
                                break;
                            case(6):
                                actionQueueFloat6(queue2);
                                break;
                            case(7):
                                actionQueueFloat7(queue2);
                                break;
                            case(8):
                                actionQueueFloat8(queue2);
                                break;
                            case(9):
                                actionQueueFloat9(queue2);
                                break;
                            case(10):
                                actionQueueFloat10(queue2);
                                break;
                        }
                        action = chooseActionQueue();
                    }
                    delete queue2;
                    break;
                }
                case(3): {
                    Queue<complex<float>> *queue3 = new Queue<complex<float>>;
                    action = chooseActionQueue();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuQueue();
                                break;
                            case(1):
                                printerFloat.PrintQueueOfComplex(*queue3);
                                break;
                            case(2):
                                actionQueueComplex2(queue3);
                                break;
                            case(3):
                                actionQueueComplex3(queue3);
                                break;
                            case(4):
                                actionQueueComplex4(queue3);
                                break;
                            case(5):
                                actionQueueComplex5(queue3);
                                break;
                            case(6):
                                actionQueueComplex6(queue3);
                                break;
                            case(7):
                                actionQueueComplex7(queue3);
                                break;
                            case(8):
                                actionQueueComplex8(queue3);
                                break;
                            case(9):
                                actionQueueComplex9(queue3);
                                break;
                            case(10):
                                actionQueueComplex10(queue3);
                                break;
                        }
                        action = chooseActionQueue();
                    }
                    delete queue3;
                    break;
                }
                case(4): {
                    Queue<string> *queue4 = new Queue<string>;
                    action = chooseActionQueue();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuQueue();
                                break;
                            case(1):
                                printerString.PrintQueue(*queue4);
                                break;
                            case(2):
                                actionQueueString2(queue4);
                                break;
                            case(3):
                                actionQueueString3(queue4);
                                break;
                            case(4):
                                actionQueueString4(queue4);
                                break;
                            case(5):
                                actionQueueString5(queue4);
                                break;
                            case(6):
                                actionQueueString6(queue4);
                                break;
                            case(7):
                                actionQueueString7(queue4);
                                break;
                            case(8):
                                actionQueueString8(queue4);
                                break;
                            case(9):
                                actionQueueString9(queue4);
                                break;
                            case(10):
                                actionQueueString10(queue4);
                                break;
                        }
                        action = chooseActionQueue();
                    }
                    delete queue4;
                    break;
                }
                case(5): {
                    Queue<Student> *queue5 = new Queue<Student>;
                    action = chooseActionQueue();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuQueue();
                                break;
                            case(1):
                                printerInt.PrintQueueOfStudents(*queue5);
                                break;
                            case(2):
                                actionQueueStudents2(queue5);
                                break;
                            case(3):
                                actionQueueStudents3(queue5);
                                break;
                            case(4):
                                actionQueueStudents4(queue5);
                                break;
                            case(5):
                                actionQueueStudents5(queue5);
                                break;
                            case(6):
                                actionQueueStudents6(queue5);
                                break;
                            case(7):
                                actionQueueStudents7(queue5);
                                break;
                            case(8):
                                actionQueueStudents8(queue5);
                                break;
                            case(9):
                                actionQueueStudents9(queue5);
                                break;
                            case(10):
                                actionQueueStudents10(queue5);
                                break;
                        }
                        action = chooseActionQueue();
                    }
                    delete queue5;
                    break;
                }
                case(6): {
                    Queue<Teacher> *queue6 = new Queue<Teacher>;
                    action = chooseActionQueue();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuQueue();
                                break;
                            case(1):
                                printerInt.PrintQueueOfTeachers(*queue6);
                                break;
                            case(2):
                                actionQueueTeachers2(queue6);
                                break;
                            case(3):
                                actionQueueTeachers3(queue6);
                                break;
                            case(4):
                                actionQueueTeachers4(queue6);
                                break;
                            case(5):
                                actionQueueTeachers5(queue6);
                                break;
                            case(6):
                                actionQueueTeachers6(queue6);
                                break;
                            case(7):
                                actionQueueTeachers7(queue6);
                                break;
                            case(8):
                                actionQueueTeachers8(queue6);
                                break;
                            case(9):
                                actionQueueTeachers9(queue6);
                                break;
                            case(10):
                                actionQueueTeachers10(queue6);
                                break;
                        }
                        action = chooseActionQueue();
                    }
                    delete queue6;
                    break;
                }
            }
            break;
        }

        case(2): {
            printMenuOfTypesMatrix();
            type = chooseTypeMatrix();
            printMenuMatrix();
            cout << "\n";
            switch(type) {
                case(1): {
                    cout << "Creating matrix:\n";
                    Matrix<int> *matrix1 = inputMatrixInt();
                    action = chooseActionMatrix();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuMatrix();
                                break;
                            case(1):
                                printerInt.PrintMatrix(*matrix1);
                                break;
                            case(2):
                                actionMatrixInt2(matrix1);
                                break;
                            case(3):
                                actionMatrixInt3(matrix1);
                                break;
                            case(4):
                                actionMatrixInt4(matrix1);
                                break;
                            case(5):
                                actionMatrixInt5(matrix1);
                                break;
                            case(6):
                                actionMatrixInt6(matrix1);
                                break;
                            case(7):
                                actionMatrixInt7(matrix1);
                                break;
                            case(8):
                                actionMatrixInt8(matrix1);
                                break;
                            case(9):
                                actionMatrixInt9(matrix1);
                                break;
                            case(10):
                                actionMatrixInt10(matrix1);
                                break;
                            case(11):
                                actionMatrixInt11(matrix1);
                                break;
                            case(12):
                                actionMatrixInt12(matrix1);
                                break;
                            case(13):
                                actionMatrixInt13(matrix1);
                                break;
                            case(14):
                                actionMatrixInt14(matrix1);
                                break;
                            case(15):
                                actionMatrixInt15(matrix1);
                                break;
                            case(16):
                                actionMatrixInt16(matrix1);
                                break;
                            case(17):
                                actionMatrixInt17(matrix1);
                                break;
                        }
                        action = chooseActionMatrix();
                    }
                    delete matrix1;
                    break;
                }
                case(2): {
                    cout << "Creating matrix:\n";
                    Matrix<float> *matrix2 = inputMatrixFloat();
                    action = chooseActionMatrix();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuMatrix();
                                break;
                            case(1):
                                printerFloat.PrintMatrix(*matrix2);
                                break;
                            case(2):
                                actionMatrixFloat2(matrix2);
                                break;
                            case(3):
                                actionMatrixFloat3(matrix2);
                                break;
                            case(4):
                                actionMatrixFloat4(matrix2);
                                break;
                            case(5):
                                actionMatrixFloat5(matrix2);
                                break;
                            case(6):
                                actionMatrixFloat6(matrix2);
                                break;
                            case(7):
                                actionMatrixFloat7(matrix2);
                                break;
                            case(8):
                                actionMatrixFloat8(matrix2);
                                break;
                            case(9):
                                actionMatrixFloat9(matrix2);
                                break;
                            case(10):
                                actionMatrixFloat10(matrix2);
                                break;
                            case(11):
                                actionMatrixFloat11(matrix2);
                                break;
                            case(12):
                                actionMatrixFloat12(matrix2);
                                break;
                            case(13):
                                actionMatrixFloat13(matrix2);
                                break;
                            case(14):
                                actionMatrixFloat14(matrix2);
                                break;
                            case(15):
                                actionMatrixFloat15(matrix2);
                                break;
                            case(16):
                                actionMatrixFloat16(matrix2);
                                break;
                            case(17):
                                actionMatrixFloat17(matrix2);
                                break;
                        }
                        action = chooseActionMatrix();
                    }
                    delete matrix2;
                    break;
                }
                case(3): {
                    cout << "Creating matrix:\n";
                    Matrix<complex<float>> *matrix3 = inputMatrixComplex();
                    action = chooseActionMatrix();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuMatrix();
                                break;
                            case(1):
                                printerFloat.PrintMatrixOfComplex(*matrix3);
                                break;
                            case(2):
                                actionMatrixComplex2(matrix3);
                                break;
                            case(3):
                                actionMatrixComplex3(matrix3);
                                break;
                            case(4):
                                actionMatrixComplex4(matrix3);
                                break;
                            case(5):
                                actionMatrixComplex5(matrix3);
                                break;
                            case(6):
                                actionMatrixComplex6(matrix3);
                                break;
                            case(7):
                                actionMatrixComplex7(matrix3);
                                break;
                            case(8):
                                actionMatrixComplex8(matrix3);
                                break;
                            case(9):
                                actionMatrixComplex9(matrix3);
                                break;
                            case(10):
                                actionMatrixComplex10(matrix3);
                                break;
                            case(11):
                                actionMatrixComplex11(matrix3);
                                break;
                            case(12):
                                actionMatrixComplex12(matrix3);
                                break;
                            case(13):
                                actionMatrixComplex13(matrix3);
                                break;
                            case(14):
                                actionMatrixComplex14(matrix3);
                                break;
                            case(15):
                                actionMatrixComplex15(matrix3);
                                break;
                            case(16):
                                actionMatrixComplex16(matrix3);
                                break;
                            case(17):
                                actionMatrixComplex17(matrix3);
                                break;
                        }
                        action = chooseActionMatrix();
                    }
                    delete matrix3;
                    break;
                }
            }
            break;
        }

        case(3): {
            printMenuOfTypesPolynomial();
            type = chooseTypePolynomial();
            printMenuPolynomial();
            cout << "\n";
            switch(type) {
                case(1): {
                    cout << "Creating polynomial:\n";
                    Polynomial<int> *pol1 = inputPolynomialInt();
                    action = chooseActionPolynomial();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuPolynomial();
                                break;
                            case(1):
                                printerInt.PrintPolynomial(*pol1);
                                break;
                            case(2):
                                actionPolinomialInt2(pol1);
                                break;
                            case(3):
                                actionPolinomialInt3(pol1);
                                break;
                            case(4):
                                actionPolinomialInt4(pol1);
                                break;
                            case(5):
                                actionPolinomialInt5(pol1);
                                break;
                            case(6):
                                actionPolinomialInt6(pol1);
                                break;
                            case(7):
                                actionPolinomialInt7(pol1);
                                break;
                            case(8):
                                actionPolinomialInt8(pol1);
                                break;
                            case(9):
                                actionPolinomialInt9(pol1);
                                break;
                        }
                        action = chooseActionPolynomial();
                    }
                    delete pol1;
                    break;
                }
                case(2): {
                    cout << "Creating polynomial:\n";
                    Polynomial<float> *pol2 = inputPolynomialFloat();
                    action = chooseActionPolynomial();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuPolynomial();
                                break;
                            case(1):
                                printerFloat.PrintPolynomial(*pol2);
                                break;
                            case(2):
                                actionPolinomialFloat2(pol2);
                                break;
                            case(3):
                                actionPolinomialFloat3(pol2);
                                break;
                            case(4):
                                actionPolinomialFloat4(pol2);
                                break;
                            case(5):
                                actionPolinomialFloat5(pol2);
                                break;
                            case(6):
                                actionPolinomialFloat6(pol2);
                                break;
                            case(7):
                                actionPolinomialFloat7(pol2);
                                break;
                            case(8):
                                actionPolinomialFloat8(pol2);
                                break;
                            case(9):
                                actionPolinomialFloat9(pol2);
                                break;
                        }
                        action = chooseActionPolynomial();
                    }
                    delete pol2;
                    break;
                }
                case(3): {
                    cout << "Creating polynomial:\n";
                    Polynomial<complex<float>> *pol3 = inputPolynomialComplex();
                    action = chooseActionPolynomial();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuPolynomial();
                                break;
                            case(1):
                                printerFloat.PrintPolynomialOfComplex(*pol3);
                                break;
                            case(2):
                                actionPolinomialComplex2(pol3);
                                break;
                            case(3):
                                actionPolinomialComplex3(pol3);
                                break;
                            case(4):
                                actionPolinomialComplex4(pol3);
                                break;
                            case(5):
                                actionPolinomialComplex5(pol3);
                                break;
                            case(6):
                                actionPolinomialComplex6(pol3);
                                break;
                            case(7):
                                actionPolinomialComplex7(pol3);
                                break;
                            case(8):
                                actionPolinomialComplex8(pol3);
                                break;
                            case(9):
                                actionPolinomialComplex9(pol3);
                                break;
                        }
                        action = chooseActionPolynomial();
                    }
                    delete pol3;
                    break;
                }
                case(4): {
                    cout << "Creating polynomial:\n";
                    Polynomial<Matrix<float>> *pol4 = inputPolynomialMatrix();
                    action = chooseActionPolynomial();
                    while (action != -1) {
                        switch(action) {
                            case(0):
                                printMenuPolynomial();
                                break;
                            case(1):
                                printerFloat.PrintPolynomialOfMatrix(*pol4);
                                break;
                            case(2):
                                actionPolinomialMatrix2(pol4);
                                break;
                            case(3):
                                actionPolinomialMatrix3(pol4);
                                break;
                            case(4):
                                actionPolinomialMatrix4(pol4);
                                break;
                            case(5):
                                actionPolinomialMatrix5(pol4);
                                break;
                            case(6):
                                actionPolinomialMatrix6(pol4);
                                break;
                            case(7):
                                actionPolinomialMatrix7(pol4);
                                break;
                            case(8):
                                actionPolinomialMatrix8(pol4);
                                break;
                            case(9):
                                actionPolinomialMatrix9(pol4);
                                break;
                        }
                        action = chooseActionPolynomial();
                    }
                    delete pol4;
                    break;
                }
            }
            break;
        }

        case(4):
            printMenuAlgorithms();
            action = chooseActionAlgorithms();
            while (action != -1) {
                switch (action) {
                    case(0):
                        printMenuAlgorithms();
                        break;
                    case(1):
                        actionAlgorithms1();
                        break;
                    case(2):
                        actionAlgorithms2();
                        break;
                    case(3):
                        actionAlgorithms3();
                        break;
                    case(4):
                        actionAlgorithms4();
                        break;
                }
                action = chooseActionAlgorithms();
            }
            break;
    }

    return 0;
}