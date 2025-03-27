#include <stdlib.h>
#include <iostream>
#include <string>
#include <complex>
#include <getopt.h>

#include "../MainClasses/Queue.hpp"
#include "../MainClasses/Matrix.hpp"
#include "../MainClasses/Polynomial.hpp"

#include "../StoredClasses/Student.hpp"
#include "../StoredClasses/Teacher.hpp"

#include "../UI/Menu/menu.hpp"
#include "../UI/Input/input.hpp"
#include "../UI/Actions/ActionsAlgorithms/actionsAlgorithms.hpp"

#include "Concepts.hpp"
#include "PrintersConcepts.hpp"
#include "Actions/actionsQueue.hpp"
#include "Actions/actionsMatrix.hpp"
#include "Actions/actionsPolynomial.hpp"

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

    int type;

    switch(flag) {
        case(0):
            cout << "You should choose option: queue/matrix/polynomial/algorithm\n";
            break;
        
        case(1): {
            printMenuOfTypesQueue();
            type = chooseTypeQueue();
            switch(type) {
                case(1): {
                    Queue<int> *queue = new Queue<int>;
                    actionsQueue(queue);
                    delete queue;
                    break;
                }
                case(2): {
                    Queue<float> *queue = new Queue<float>;
                    actionsQueue(queue);
                    delete queue;
                    break;
                }
                case(3): {
                    Queue<complex<float>> *queue = new Queue<complex<float>>;
                    actionsQueue(queue);
                    delete queue;
                    break;
                }
                case(4): {
                    Queue<string> *queue = new Queue<string>;
                    actionsQueue(queue);
                    delete queue;
                    break;
                }
                case(5): {
                    Queue<Student> *queue = new Queue<Student>;
                    actionsQueue(queue);
                    delete queue;
                    break;
                }
                case(6): {
                    Queue<Teacher> *queue = new Queue<Teacher>;
                    actionsQueue(queue);
                    delete queue;
                    break;
                }
            }
            break;
        }

        case(2): {
            printMenuOfTypesMatrix();
            type = chooseTypeMatrix();
            switch(type) {
                case(1): {
                    Matrix<int> *matrix = inputMatrixInt();
                    actionsMatrix(matrix);
                    delete matrix;
                    break;
                }
                case(2): {
                    Matrix<float> *matrix = inputMatrixFloat();
                    actionsMatrix(matrix);
                    delete matrix;
                    break;
                }
                case(3): {
                    Matrix<complex<float>> *matrix = inputMatrixComplex();
                    actionsMatrix(matrix);
                    delete matrix;
                    break;
                }
            }
            break;
        }
        
        case(3): {
            printMenuOfTypesPolynomial();
            type = chooseTypePolynomial();
            switch(type) {
                case(1): {
                    Polynomial<int> *pol = inputPolynomialInt();
                    actionsPolynomial(pol);
                    delete pol;
                    break;
                }
                case(2): {
                    Polynomial<float> *pol = inputPolynomialFloat();
                    actionsPolynomial(pol);
                    delete pol;
                    break;
                }
                case(3): {
                    Polynomial<complex<float>> *pol = inputPolynomialComplex();
                    actionsPolynomial(pol);
                    delete pol;
                    break;
                }
                case(4): {
                    Polynomial<Matrix<float>> *pol = inputPolynomialMatrix();
                    actionsPolynomial(pol);
                    delete pol;
                    break;
                }
            }
            break;
        }

        case(4): {
            printMenuAlgorithms();
            int action = chooseActionAlgorithms();
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
    }

    return 0;
}