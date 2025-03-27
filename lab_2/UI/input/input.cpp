#include <iostream>
#include "../../SequenceClasses/Sequence.h"
#include "input.h"

Sequence<float> *inputSequence() {
    int sequenceType;
    try {
        sequenceType = inputType();
    }
    catch (...) {
        throw;
        return NULL;
    }
    std::cout << "Input length of the sequence: ";
    int len;
    try {
        len = inputNatural();
    }
    catch (...) {
        throw;
        return NULL;
    }
    float *data = new float[len];
    std::cout << "Input sequence:\n";
    for (int i = 0; i < len; i++) {
        std::cout << "Sequence[" << i << "] = ";
        try {
            data[i] = inputFloat();
        }
        catch (...) {
            throw;
            return NULL;
        }
    }
    Sequence<float> *newSequence;
    switch(sequenceType) {
        case 1:
            newSequence = new ArraySequence<float>(data, len);
            break;
        case 2:
            newSequence = new LinkedListSequence<float>(data, len);
            break;
    }
    delete [] data;

    return newSequence;
}

int inputType() {
    std::cout << "Possible ways to represent the sequence:\n"
    << "1 - ArraySequence\n"
    << "2 - LinkedListSequence\n";
    int type = 0;
    int check = 0;
    while (!((check == 1) && ((type == 1) || (type == 2)))) {
        printf("Choose a way: ");
        check = scanf("%d", &type);
        if (check == EOF) {
            throw std::out_of_range("Error: EOF\n");
        }
        if (!((check == 1) && ((type == 1) || (type == 2)))) {
            scanf("%*[^\n]");
            printf("Invalid type! Try again\n");
        }
    }


    return type;
}

int inputNatural() {
    int n = 0;
    int check = 0;
    while ((check != 1) || (n <= 0)) {
        check = scanf("%d", &n);
        if (check == EOF) {
            throw std::out_of_range("Error: EOF\n");
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
            throw std::out_of_range("Error: EOF\n");
        }
        if (check != 1) {
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
            throw std::out_of_range("Error: EOF\n");
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

int chooseAction() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 11) && (a != 12) && (a != 13) && (a != 14) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("Error: EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 11) && (a != 12) && (a != 13) && (a != 14) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}
