#include <iostream>
#include <string>

#include "../../../TreeClasses/BinaryTree.hpp"
#include "../../../SequenceClasses/Sequence.hpp"
#include "../../../Printers.hpp"
#include "../../../Tuple.hpp"
#include "../../Menu/menu.hpp"
#include "../../Input/input.hpp"
#include "actionsBinaryTree.hpp"

void actionsBinaryTree() {
    printMenuBinaryTree();
    int action = chooseActionBinaryTree();
    BinaryTree<string, float> *tree = new BinaryTree<string, float>;
    while (action != -1) {
        switch(action) {
            case(1):
                actionBinaryTree1(tree);
                break;

            case(2):
                actionBinaryTree2(tree);
                break;

            case(3):
                actionBinaryTree3(tree);
                break;

            case(4):
                actionBinaryTree4(tree);
                break;

            case(5):
                actionBinaryTree5(tree);
                break;

            case(6):
                actionBinaryTree6(tree);
                break;

            case(7):
                actionBinaryTree7(tree);
                break;

            case(8):
                actionBinaryTree8(tree);
                break;

            case(0):
                printMenuBinaryTree();
                break;
        }
        action = chooseActionBinaryTree();
    }
    delete tree;
}

void actionBinaryTree1(BinaryTree<string, float> *tree) {
    string data;
    cout << "Input data:\n";
    cin >> data;
    cout << "Input key:\n";
    float key = inputFloat();
    try {
        tree->AddNode(data, key);
    }
    catch (out_of_range &e) {
        cout << e.what() << "\n";
    }
}

void actionBinaryTree2(BinaryTree<string, float> *tree) {
    cout << "Input key of deleted node: ";
    float key = inputFloat();
    try {
        tree->DeleteNodeByKey(key);
    }
    catch (out_of_range e) {
        cout << e.what() << "\n";
    }
}

void actionBinaryTree3(BinaryTree<string, float> *tree) {
    cout << "Possible ways:\n";
    cout << "ROL - right-root-left\n";
    cout << "RLO - right-left-root\n";
    cout << "LOR - left-root-right\n";
    cout << "LRO - left-right-root\n";
    cout << "ORL - root-right-left\n";
    cout << "OLR - root-left-right\n";
    cout << "Choose way:\n";
    string way;
    cin >> way;
    if ((way != "ROL") && (way != "RLO") && (way != "LOR") && (way != "LRO") && (way != "ORL") && (way != "OLR")) cout << "Invalid way - impossible to get traversal\n";
    else {
        Sequence<Tuple<string, float>> *traversal = tree->Traversal(way);
        Printers<int> printer;
        cout << "Traversal:\n";
        printer.PrintSequenceOfTuples(*traversal);
        delete traversal;
    }
}

void actionBinaryTree4(BinaryTree<string, float> *tree) {
    BinaryTree<string, float> *balancedTree = tree->Balance();
    Sequence<Tuple<string, float>> *traversal = balancedTree->Traversal("OLR");
    Printers<int> printer;
    cout << "Balanced tree, root-left-right traversal:\n";
    printer.PrintSequenceOfTuples(*traversal);
    delete traversal;
    delete balancedTree;
}

void actionBinaryTree5(BinaryTree<string, float> *tree) {
    cout << "Input key of root of sub tree:\n";
    float key = inputFloat();
    try {
        BinaryTree<string, float> *subTree = tree->GetSubTreeByKey(key);
        Sequence<Tuple<string, float>> *traversal = subTree->Traversal("OLR");
        Printers<int> printer;
        cout << "Sub tree, root-left-right traversal:\n";
        printer.PrintSequenceOfTuples(*traversal);
        delete subTree;
        delete traversal;
    }
    catch (out_of_range &e) {
        cout << e.what() << "\n";
    }
}

void actionBinaryTree6(BinaryTree<string, float> *tree) {
    cout << "Input added tree:\n";
    BinaryTree<string, float> *addedTree = inputBinaryTree();
    BinaryTree<string, float> *mergeTree = (*tree) + (*addedTree);
    Sequence<Tuple<string, float>> *traversal = mergeTree->Traversal("OLR");
    Printers<int> printer;
    cout << "Merged tree, root-left-right traversal:\n";
    printer.PrintSequenceOfTuples(*traversal);
    delete addedTree;
    delete mergeTree;
    delete traversal;
}

void actionBinaryTree7(BinaryTree<string, float> *tree) {
    cout << "Input sub tree:\n";
    BinaryTree<string, float> *subTree = inputBinaryTree();
    bool contains = tree->ContainsSubTree(*subTree);
    if (contains) cout << "The tree contains inputed sub tree\n";
    else cout << "The tree does not contain inputed tree\n";
    delete subTree;
}

void actionBinaryTree8(BinaryTree<string, float> *tree) {
    cout << "Input key:\n";
    float key = inputFloat();
    try {
        string data = tree->FindDataByKey(key);
        cout << "Data by inputed key is: " << data << "\n";
    }
    catch (out_of_range &e) {
        cout << e.what() << "\n";
    }
}