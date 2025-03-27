#include <iostream>
#include <string>
#include "../../TreeClasses/NTree.hpp"
#include "../../SequenceClasses/Sequence.hpp"
#include "../../Tuple.hpp"
#include "testNTree.hpp"
#include "../../Printers.hpp"

using namespace std;

void testNTree() {
    bool check = true;
    cout << "== Tesing NTree class ==\n";

    testNTree_ContainsData(&check);
    testNTree_ContainsKey(&check);
    testNTree_Insert(&check);
    //testNTree_DeleteByKey(&check);
    testNTree_Operator(&check);
    testNTree_Traversal(&check);
    testNTree_Map(&check);
    testNTree_Reduce(&check);

    if (check) cout << "All functions of NTree class are correct\n";
    else cout << "Error! Not all functions of NTree class are correct\n";
}

void testNTree_ContainsData(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 10);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);

    bool check1 = tree.ContainsData("i");
    bool check2 = tree.ContainsData("l");
    bool check3 = tree.ContainsData("g");
    bool check4 = tree.ContainsData("w");

    if (check1 && check2 && check3 && !check4) cout << "ContainsData : passed\n";
    else {
        cout << "ContainsData : failed\n";
        (*check) = false;
    }
}

void testNTree_ContainsKey(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 10);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);

    bool check1 = tree.ContainsKey(18);
    bool check2 = tree.ContainsKey(73);
    bool check3 = tree.ContainsKey(26);
    bool check4 = tree.ContainsKey(22);

    if (check1 && check2 && check3 && !check4) cout << "ContainsKey  : passed\n";
    else {
        cout << "ContainsKey  : failed\n";
        (*check) = false;
    }
}

void testNTree_Insert(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 10);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);

    Sequence<Tuple<string, int>> *traversal = tree.Traversal();

    Tuple<string, int> data[] = {Tuple<string, int>("b", 10), Tuple<string, int>("d", 30), Tuple<string, int>("c", 50), Tuple<string, int>("a", 70), Tuple<string, int>("i", 5), Tuple<string, int>("k", 11), Tuple<string, int>("f", 17), Tuple<string, int>("j", 21), Tuple<string, int>("h", 26), Tuple<string, int>("m", 18), Tuple<string, int>("l", 20), Tuple<string, int>("g", 73), Tuple<string, int>("e", 80)};
    Sequence<Tuple<string, int>> *checkTraversal = new ArraySequence<Tuple<string, int>>(data, 13);

    bool check1 = false;
    try {
        tree.Insert("h", 1);
    }
    catch (...) {
        check1 = true;
    }

    bool check2 = false;
    try {
        tree.Insert("q", 20);
    }
    catch (...) {
        check2 = true;
    }

    if ((*traversal == *checkTraversal) && check1 && check2) cout << "Insert       : passed\n";
    else {
        cout << "Insert       : failed\n";
        (*check) = false;
    }

    delete traversal;
    delete checkTraversal;
}

void testNTree_Operator(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 9);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);
    tree.Insert("o", 10);

    string el1 = tree[5];
    string el2 = tree[20];
    string el3 = tree[73];

    bool check1 = false;
    try {
        string el4 = tree[13];
    }
    catch (...) {
        check1 = true;
    }

    if ((el1 == "i") && (el2 == "l") && (el3 == "g") && check1) cout << "Operator []  : passed\n";
    else {
        cout << "Operator []  : failed\n";
        (*check) = false;
    }
}

void testNTree_Traversal(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 9);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);
    tree.Insert("o", 10);

    NTree<string, int> emptyTree(5);

    Sequence<Tuple<string, int>> *traversal1 = tree.Traversal();
    Tuple<string, int> data1[] = {Tuple<string, int>("b", 9), Tuple<string, int>("d", 30), Tuple<string, int>("c", 50), Tuple<string, int>("a", 70), Tuple<string, int>("i", 5), Tuple<string, int>("k", 11), Tuple<string, int>("f", 17), Tuple<string, int>("j", 21), Tuple<string, int>("h", 26), Tuple<string, int>("o", 10), Tuple<string, int>("m", 18), Tuple<string, int>("l", 20), Tuple<string, int>("g", 73), Tuple<string, int>("e", 80)};
    Sequence<Tuple<string, int>> *checkTraversal1 = new ArraySequence<Tuple<string, int>>(data1, 14);

    Sequence<Tuple<string, int>> *traversal2 = emptyTree.Traversal();
    Sequence<Tuple<string, int>> *checkTraversal2 = new ArraySequence<Tuple<string, int>>;

    if ((*traversal1 == *checkTraversal1) && (*traversal2 == *checkTraversal2)) cout << "Traversal    : passed\n";
    else {
        cout << "Traversal    : failed\n";
        (*check) = false;
    }

    delete traversal1;
    delete checkTraversal1;
    delete traversal2;
    delete checkTraversal2;
}

string mapNTree(string str) {
    return str + str;
}

void testNTree_Map(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 10);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);

    NTree<string, int> emptyTree(5);

    NTree<string, int> *mapTree = tree.Map(mapNTree);
    Sequence<Tuple<string, int>> *traversal = mapTree->Traversal();

    NTree<string, int> *mapEmptyTree = emptyTree.Map(mapNTree);
    Sequence<Tuple<string, int>> *emptyTreeTraversal = mapEmptyTree->Traversal();

    Tuple<string, int> data[] = {Tuple<string, int>("bb", 10), Tuple<string, int>("dd", 30), Tuple<string, int>("cc", 50), Tuple<string, int>("aa", 70), Tuple<string, int>("ii", 5), Tuple<string, int>("kk", 11), Tuple<string, int>("ff", 17), Tuple<string, int>("jj", 21), Tuple<string, int>("hh", 26), Tuple<string, int>("mm", 18), Tuple<string, int>("ll", 20), Tuple<string, int>("gg", 73), Tuple<string, int>("ee", 80)};
    Sequence<Tuple<string, int>> *checkTraversal = new ArraySequence<Tuple<string, int>>(data, 13);

    Sequence<Tuple<string, int>> *checkemptyTreeTraversal = new ArraySequence<Tuple<string, int>>;

    if ((*traversal == *checkTraversal) && (*emptyTreeTraversal == *checkemptyTreeTraversal)) cout << "Map          : passed\n";
    else {
        cout << "Map          : failed\n";
        (*check) = false;
    }

    delete mapTree;
    delete traversal;
    delete mapEmptyTree;
    delete emptyTreeTraversal;
    delete checkTraversal;
    delete checkemptyTreeTraversal;
}

string reduceNTree(string str1, string str2) {
    return str1 + str2;
}

void testNTree_Reduce(bool *check) {
    NTree<string, int> tree("a", 70, 5);
    tree.Insert("b", 10);
    tree.Insert("c", 50);
    tree.Insert("d", 30);
    tree.Insert("e", 80);
    tree.Insert("f", 17);
    tree.Insert("g", 73);
    tree.Insert("h", 26);
    tree.Insert("i", 5);
    tree.Insert("j", 21);
    tree.Insert("k", 11);
    tree.Insert("l", 20);
    tree.Insert("m", 18);

    NTree<string, int> emptyTree(5);

    string reduce = tree.Reduce(reduceNTree, "z");

    bool check1 = false;
    try {
        reduce = emptyTree.Reduce(reduceNTree, "z");
    }
    catch (...) {
        check1 = true;
    }

    if ((reduce == "eglmhjfkiacdbz") && check1) cout << "Reduce       : passed\n";
    else {
        cout << "Reduce       : failed\n";
        (*check) = false;
    }
}

