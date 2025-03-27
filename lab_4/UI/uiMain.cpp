#include <stdlib.h>
#include <iostream>
#include <string>
#include <complex>
#include <getopt.h>

#include "../TreeClasses/BinaryTree.hpp"
#include "../TreeClasses/NTree.hpp"

#include "../SequenceClasses/Sequence.hpp"
#include "../Printers.hpp"
#include "../Tuple.hpp"

#include "Menu/menu.hpp"
#include "Actions/ActionsBinaryTree/actionsBinaryTree.hpp"
#include "Actions/ActionsNTree/actionsNTree.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int flag = 0;
    const char *shortOptions = "";
    const struct option longOptions[] = {
        {"binary tree", no_argument, &flag, 1},
        {"n-ary tree", no_argument, &flag, 2},
        {NULL, 0, NULL, 0}
    };
    while (getopt_long(argc, argv, shortOptions, longOptions, NULL) != -1);

    switch(flag) {
        case(0):
            cout << "You should choose option\n";
            break;

        case(1): {
            actionsBinaryTree();
            break;
        }

        case(2): {
            actionsNTree();
            break;
        }
    }


    return 0;
}