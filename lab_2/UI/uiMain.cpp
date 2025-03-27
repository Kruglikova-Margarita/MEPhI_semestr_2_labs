#include <iostream>
#include "../SequenceClasses/Sequence.h"
#include "menu/menu.h"
#include "input/input.h"

float f12(float a) {
    return (2 * a);
}

bool f13(float a) {
    if (a > 0) return true;
    return false;
}

float f14(float a, float b) {
    return (a + b);
}

int main() {
    Sequence<float> *sequence = NULL;
    std::cout << "== Creating new sequence ==\n";
    try {
        sequence = inputSequence();
    }
    catch (std::out_of_range &e) {
        std::cout << e.what();
        return 1;
    }
    printMenu();
    int action;
    try {
        action = chooseAction();
    }
    catch (...) {
        std::cout << "EOF\n";
        delete sequence;
        return 1;
    }
    int element;
    int index1;
    int index2;
    int len;
    float c;
    float reduce;
    Sequence<float> *sequence1;
    Sequence<float> *sequence2;

    while (action != -1) {
        switch(action) {
            case(1):
                std::cout << "\nThe sequence:\n";
                sequence->Print();
                break;

            case(2):
                std::cout << "The first element of the sequence: ";
                try {
                    element = sequence->GetFirst();
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << element << "\n";
                break;

            case(3):
                std::cout << "The last element of the sequence: ";
                try {
                    element = sequence->GetLast();
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << element << "\n";
                break;

            case(4):
                std::cout << "Input index of element: ";
                try {
                    index1 = inputInt();
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                try {
                    element = (*sequence)[index1];
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << element << "\n";
                break;

            case(5):
                std::cout << "Input start index: ";
                try {
                    index1 = inputInt();
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                std::cout << "Input end index: ";
                try {
                    index2 = inputInt();
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                try {
                    sequence1 = sequence->GetSubSequence(index1, index2);
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << "The subsequence:\n";
                sequence1->Print();
                delete sequence1;
                break;

            case(6):
                len = sequence->GetLength();
                std::cout << "The length of the sequence: " << len << "\n";
                break;

            case(7):
                std::cout << "Input an element: ";
                try {
                    element = inputFloat();
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                sequence->Append(element);
                std::cout << "The element has been appended\n";
                break;

            case(8):
                std::cout << "Input an element: ";
                try {
                    element = inputFloat();
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                sequence->Prepend(element);
                std::cout << "The element has been prepended\n";
                break;

            case(9):
                std::cout << "Input index: ";
                try {
                    index1 = inputInt();
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                std::cout << "Input an element: ";
                try {
                    element = inputFloat();
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                try {
                    sequence->InsertAt(element, index1);
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << "The element has been inserted\n";
                break;

            case(10):
                std::cout << "Input index of element: ";
                try {
                    index1 = inputInt();
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                try {
                    sequence->Delete(index1);
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << "The element has been deleted\n";
                break;

            case(11):
                std::cout << "Create sequence that will be concated with existing sequence:\n";
                sequence1 = inputSequence();
                sequence2 = (*sequence) + (*sequence1);
                std::cout << "Concated sequence:\n";
                sequence2->Print();
                delete sequence1;
                delete sequence2;
                break;

            case(12):
                sequence1 = sequence->Map(f12);
                sequence1->Print();
                delete sequence1;
                break;

            case(13):
                sequence1 = sequence->Where(f13);
                sequence1->Print();
                delete sequence1;
                break;

            case(14):
                std::cout << "Input start value: ";
                try {
                    c = inputFloat();
                }
                catch(std::out_of_range &e) {
                    std::cout << e.what();
                    delete sequence;
                    return 1;
                }
                try {
                    reduce = sequence->Reduce(f14, c);
                }
                catch (std::out_of_range &e) {
                    std::cout << e.what();
                    break;
                }
                std::cout << "Result of reduce: " << reduce << "\n";
                break;

            case(0):
                printMenu();
                break;
        }

        try {
            action = chooseAction();
        }
        catch (...) {
            std::cout << "EOF\n";
            delete sequence;
            return 1;
        }
    }

    delete sequence;

    return 0;
}