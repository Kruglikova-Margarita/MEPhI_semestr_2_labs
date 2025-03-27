#include <iostream>
#include <string>

#include "../../../TreeClasses/NTree.hpp"
#include "../../../SequenceClasses/Sequence.hpp"
#include "../../../Printers.hpp"
#include "../../../Tuple.hpp"
#include "../../Menu/menu.hpp"
#include "../../Input/input.hpp"
#include "actionsNTree.hpp"

void actionsNTree() {
    cout << "Input number of children in one node: ";
    int num = inputNatural();
    NTree<string, float> *tree = new NTree<string, float>(num);
    printMenuNTree();
    int action = chooseActionNTree();
    while (action != -1) {
        switch(action) {
            case(1):
                actionNTree1(tree);
                break;
            
            case(2):
                actionNTree2(tree);
                break;

            case(3):
                actionNTree3(tree);
                break;
            
            case(4):
                actionNTree4(tree);
                break;

            case(5):
                actionNTree5(tree);
                break;

            case(0):
                printMenuNTree();
                break;
        }
        action = chooseActionNTree();
    }
    
}

void actionNTree1(NTree<string, float> *tree) {
    string data;
    cout << "Input data:\n";
    cin >> data;
    cout << "Input key:\n";
    float key = inputFloat();
    try {
        tree->Insert(data, key);
    }
    catch (out_of_range &e) {
        cout << e.what() << "\n";
    }
}

void actionNTree2(NTree<string, float> *tree) {
    string data;
    cout << "Input data:\n";
    cin >> data;
    bool contains = tree->ContainsData(data);
    if (contains) cout << "The tree contains inputed data\n";
    else cout << "The tree does not contain inputed data\n";
}

void actionNTree3(NTree<string, float> *tree) {
    cout << "Input key:\n";
    float key = inputFloat();
    bool contains = tree->ContainsKey(key);
    if (contains) cout << "The tree contains inputed key\n";
    else cout << "The tree does not contain inputed key\n";
}

void actionNTree4(NTree<string, float> *tree) {
    cout << "Input key:\n";
    float key = inputFloat();
    try {
        string data = tree->SearchByKey(key);
        cout << "Data by inputed key is: " << data << "\n";
    }
    catch (out_of_range &e) {
        cout << e.what() << "\n";
    }
}

void actionNTree5(NTree<string, float> *tree) {
    Sequence<Tuple<string, float>> *traversal = tree->Traversal();
    Printers<int> printer;
    cout << "Traversal: firstly - values in node, secondly - values in children\n";
    printer.PrintSequenceOfTuples(*traversal);
    delete traversal;
}
