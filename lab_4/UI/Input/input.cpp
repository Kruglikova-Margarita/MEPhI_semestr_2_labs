#include <iostream>
#include "../../TreeClasses/BinaryTree.hpp"

int chooseActionBinaryTree() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

int chooseActionNTree() {
    int a = -10;
    int check = 0;
    std::cout << "\nChoose action: ";
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 0) && (a != -1)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 0) && (a != -1)) {
            scanf("%*[^\n]");
            std::cout << "Invalid action! Try again: ";
        }
    }

    return a;
}

float inputFloat() {
    float n = 0;
    int check = 0;
    while (check != 1) {
        check = scanf("%f", &n);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

int inputNatural() {
    int n = 0;
    int check = 0;
    while ((check != 1) || (n <= 0)) {
        check = scanf("%d", &n);
        if (check == EOF) {
            throw std::out_of_range("EOF\n");
        }
        if ((check != 1) || (n <= 0)) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

BinaryTree<string, float> *inputBinaryTree() {
    cout << "Input number of elements in the tree: ";
    int num = inputNatural();
    BinaryTree<string, float> *tree = new BinaryTree<string, float>;
    string data;
    float key;
    for (int i = 1; i <= num; i++) {
        cout << "Input " << i << " element:\n";
        cout << "Input data:\n";
        cin >> data;
        cout << "Input key: ";
        key = inputFloat();
        tree->AddNode(data, key);
    }

    return tree;
}
