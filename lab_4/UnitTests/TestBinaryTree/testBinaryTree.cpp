#include <iostream>
#include <string>
#include "../../TreeClasses/BinaryTree.hpp"
#include "../../SequenceClasses/Sequence.hpp"
#include "../../Tuple.hpp"
#include "testBinaryTree.hpp"

using namespace std;

void testBinaryTree() {
    bool check = true;
    cout << "== Tesing BinaryTree class ==\n";

    testBinaryTree_AddNode(&check);
    testBinaryTree_DeleteNode(&check);
    testBinaryTree_GetRoot(&check);
    testBinaryTree_GetLeftSubTree(&check);
    testBinaryTree_GetRightSubTree(&check);
    testBinaryTree_Traversal(&check);
    testBinaryTree_Balance(&check);
    testBinaryTree_Map(&check);
    testBinaryTree_Where(&check);
    testBinaryTree_Reduce(&check);
    testBinaryTree_GetSubTree(&check);
    testBinaryTree_Copy(&check);
    testBinaryTree_Operator1(&check);
    testBinaryTree_ContainsData(&check);
    testBinaryTree_ContainsKey(&check);
    testBinaryTree_ContainsNode(&check);
    testBinaryTree_ContainsSubTree(&check);
    testBinaryTree_Operator2(&check);
    testBinaryTree_Operator3(&check);
    testBinaryTree_FindKeyByData(&check);

    if (check) cout << "All functions of BinaryTree class are correct\n";
    else cout << "Error! Not all functions of BinaryTree class are correct\n";
}

void testBinaryTree_AddNode(bool *check) {
    BinaryTree<int, int> tree;
    tree.AddNode(2, 2);
    Tuple<int, int> data[] = {Tuple<int, int>(1, 2)};
    Sequence<Tuple<int, int>> *seq = new ArraySequence<Tuple<int, int>>(data, 1);
    Sequence<Tuple<int, int>> *nodes = tree.Traversal("LOR");
    bool check1 = ((*seq) == (*nodes));
    delete nodes;
    tree.AddNode(Tuple<int, int>(1, 1));
    seq->Append(Tuple<int, int>(1, 1));
    nodes = tree.Traversal("ROL");
    bool check2 = ((*seq) == (*nodes));
    bool check3 = false;
    try {
        tree.AddNode(2, 3);
    }
    catch (...) {
        check3 = true;
    }

    if (check1 && check2 && check3) cout << "AddNode         : passed\n";
    else {
        cout << "AddNode         : failed\n";
        (*check) = false;
    }
    delete seq;
    delete nodes;
}

void testBinaryTree_DeleteNode(bool *check) {
    BinaryTree<string, int> tree1("a", 1);
    tree1.AddNode("b", 2);

    BinaryTree<string, int> checkTree1("a", 1);
    tree1.DeleteNodeByData("b");


    BinaryTree<string, int> tree2("a", 1);
    BinaryTree<string, int> checkTree2;
    tree2.DeleteNodeByData("a");


    BinaryTree<string, int> tree3("a", 1);
    tree3.AddNode("b", 0);
    tree3.AddNode("c", 2);
    tree3.AddNode("d", 5);
    tree3.AddNode("e", 3);
    tree3.AddNode("f", 6);

    BinaryTree<string, int> checkTree3("a", 1);
    checkTree3.AddNode("b", 0);
    checkTree3.AddNode("d", 5);
    checkTree3.AddNode("e", 3);
    checkTree3.AddNode("f", 6);
    tree3.DeleteNodeByData("c");


    BinaryTree<string, int> tree4("a", 1);
    tree4.AddNode("d", 5);
    tree4.AddNode("e", 3);
    tree4.AddNode("f", 6);

    BinaryTree<string, int> checkTree4("d", 5);
    checkTree4.AddNode("e", 3);
    checkTree4.AddNode("f", 6);
    tree4.DeleteNodeByData("a");


    BinaryTree<string, int> tree5("a", 7);
    tree5.AddNode("b", 8);
    tree5.AddNode("c", 3);
    tree5.AddNode("d", 2);
    tree5.AddNode("f", 1);

    BinaryTree<string, int> checkTree5("a", 7);
    checkTree5.AddNode("b", 8);
    checkTree5.AddNode("d", 2);
    checkTree5.AddNode("f", 1);
    tree5.DeleteNodeByData("c");


    BinaryTree<string, int> tree6("a", 7);
    tree6.AddNode("d", 5);
    tree6.AddNode("e", 3);
    tree6.AddNode("f", 6);

    BinaryTree<string, int> checkTree6("d", 5);
    checkTree6.AddNode("e", 3);
    checkTree6.AddNode("f", 6);
    tree6.DeleteNodeByData("a");


    BinaryTree<string, int> tree7("a", 6);
    tree7.AddNode("b", 3);
    tree7.AddNode("c", 8);
    tree7.AddNode("d", 4);
    tree7.AddNode("e", 5);
    tree7.AddNode("f", 1);
    tree7.AddNode("g", 7);
    tree7.AddNode("h", 0);
    tree7.AddNode("i", 2);

    BinaryTree<string, int> checkTree7("a", 6);
    checkTree7.AddNode("d", 4);
    checkTree7.AddNode("e", 5);
    checkTree7.AddNode("f", 1);
    checkTree7.AddNode("h", 0);
    checkTree7.AddNode("i", 2);
    checkTree7.AddNode("c", 8);
    checkTree7.AddNode("g", 7);
    tree7.DeleteNodeByData("b");


    BinaryTree<string, int> tree8("a", 6);
    tree8.AddNode("b", 3);
    tree8.AddNode("c", 8);
    tree8.AddNode("d", 4);
    tree8.AddNode("e", 5);
    tree8.AddNode("f", 1);
    tree8.AddNode("g", 7);

    BinaryTree<string, int> checkTree8("g", 7);
    checkTree8.AddNode("b", 3);
    checkTree8.AddNode("d", 4);
    checkTree8.AddNode("e", 5);
    checkTree8.AddNode("c", 8);
    checkTree8.AddNode("f", 1);
    tree8.DeleteNodeByData("a");

    bool check1 = false;
    try {
        tree8.DeleteNodeByData("q");
    }
    catch (...) {
        check1 = true;
    }


    if ((tree1 == checkTree1) && (tree2 == checkTree2) && (tree3 == checkTree3) && (tree4 == checkTree4) && (tree5 == checkTree5) && (tree6 == checkTree6) && (tree7 == checkTree7) && (tree8 == checkTree8) && check1) cout << "DeleteNode      : passed\n";
    else {
        cout << "DeleteNode      : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_GetRoot(bool *check) {
    BinaryTree<string, int> tree1("a", 6);
    tree1.AddNode("b", 3);
    tree1.AddNode("c", 8);
    tree1.AddNode("d", 4);
    tree1.AddNode("e", 5);

    BinaryTree<string, int> emptyTree;

    Tuple<string, int> *root;
    Tuple<string, int> *getRoot;
    bool check1 = true;
    try {
        getRoot = tree1.GetRoot();
    }
    catch (...) {
        check1 = false;
    }

    bool check2 = false;
    try {
        root = emptyTree.GetRoot();
    }
    catch(...) {
        check2 = true;
    }

    root = new Tuple<string, int>("a", 6);

    if (check1 && ((*root) == (*getRoot)) && check2) cout << "GetRoot         : passed\n";
    else {
        cout << "GetRoot         : failed\n";
        (*check) = false;
    }
    delete root;
    delete getRoot;
}

void testBinaryTree_GetLeftSubTree(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> checkTree("b", 3);
    checkTree.AddNode("f", 1);
    checkTree.AddNode("d", 4);
    checkTree.AddNode("h", 0);
    checkTree.AddNode("i", 2);
    checkTree.AddNode("e", 5);

    BinaryTree<string, int> *leftSubTree1 = tree.GetLeftSubTree();

    BinaryTree<string, int> emptyTree;
    bool check1 = false;
    try {
        BinaryTree<string, int> *leftSubTree = emptyTree.GetLeftSubTree();
    }
    catch (...) {
        check1 = true;
    }

    emptyTree.AddNode("a", 1);
    BinaryTree<string, int> *leftSubTree2 = emptyTree.GetLeftSubTree();
    emptyTree.DeleteNodeByKey(1);

    if ((checkTree == (*leftSubTree1)) && check1 && (emptyTree == (*leftSubTree2))) cout << "GetLeftSubTree  : passed\n";
    else {
        cout << "GetLeftSubTree  : failed\n";
        (*check) = false;
    }
    delete leftSubTree1;
    delete leftSubTree2;

}

void testBinaryTree_GetRightSubTree(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("q", 9);
    tree.AddNode("w", 10);

    BinaryTree<string, int> checkTree("c", 8);
    checkTree.AddNode("g", 7);
    checkTree.AddNode("q", 9);
    checkTree.AddNode("w", 10);

    BinaryTree<string, int> *rightSubTree1 = tree.GetRightSubTree();

    BinaryTree<string, int> emptyTree;
    bool check1 = false;
    try {
        BinaryTree<string, int> *rightSubTree = emptyTree.GetLeftSubTree();
    }
    catch (...) {
        check1 = true;
    }

    emptyTree.AddNode("a", 1);
    BinaryTree<string, int> *rightSubTree2 = emptyTree.GetLeftSubTree();
    emptyTree.DeleteNodeByKey(1);

    if ((checkTree == (*rightSubTree1)) && check1 && (emptyTree == (*rightSubTree2))) cout << "GetLeftSubTree  : passed\n";
    else {
        cout << "GetLeftSubTree  : failed\n";
        (*check) = false;
    }
    delete rightSubTree1;
    delete rightSubTree2;

}

void testBinaryTree_Traversal(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);
    Sequence<Tuple<string, int>> *traversalROL = tree.Traversal("ROL");
    Sequence<Tuple<string, int>> *traversalRLO = tree.Traversal("RLO");
    Sequence<Tuple<string, int>> *traversalLOR = tree.Traversal("LOR");
    Sequence<Tuple<string, int>> *traversalLRO = tree.Traversal("LRO");
    Sequence<Tuple<string, int>> *traversalORL = tree.Traversal("ORL");
    Sequence<Tuple<string, int>> *traversalOLR = tree.Traversal("OLR");
    Sequence<Tuple<string, int>> *traversalInvalid = tree.Traversal("");

    Tuple<string, int> dataROL[] = {Tuple<string, int>("c", 8), Tuple<string, int>("g", 7), Tuple<string, int>("a", 6), Tuple<string, int>("e", 5), Tuple<string, int>("d", 4), Tuple<string, int>("b", 3), Tuple<string, int>("i", 2), Tuple<string, int>("f", 1), Tuple<string, int>("h", 0)};
    Sequence<Tuple<string, int>> *seqROL = new ArraySequence<Tuple<string, int>>(dataROL, 9);

    Tuple<string, int> dataRLO[] = {Tuple<string, int>("g", 7), Tuple<string, int>("c", 8), Tuple<string, int>("e", 5), Tuple<string, int>("d", 4), Tuple<string, int>("i", 2), Tuple<string, int>("h", 0), Tuple<string, int>("f", 1), Tuple<string, int>("b", 3), Tuple<string, int>("a", 6)};
    Sequence<Tuple<string, int>> *seqRLO = new ArraySequence<Tuple<string, int>>(dataRLO, 9);

    Tuple<string, int> dataLOR[] = {Tuple<string, int>("h", 0), Tuple<string, int>("f", 1), Tuple<string, int>("i", 2), Tuple<string, int>("b", 3), Tuple<string, int>("d", 4), Tuple<string, int>("e", 5), Tuple<string, int>("a", 6), Tuple<string, int>("g", 7), Tuple<string, int>("c", 8)};
    Sequence<Tuple<string, int>> *seqLOR = new ArraySequence<Tuple<string, int>>(dataLOR, 9);

    Tuple<string, int> dataLRO[] = {Tuple<string, int>("h", 0), Tuple<string, int>("i", 2), Tuple<string, int>("f", 1), Tuple<string, int>("e", 5), Tuple<string, int>("d", 4), Tuple<string, int>("b", 3), Tuple<string, int>("g", 7), Tuple<string, int>("c", 8), Tuple<string, int>("a", 6)};
    Sequence<Tuple<string, int>> *seqLRO = new ArraySequence<Tuple<string, int>>(dataLRO, 9);

    Tuple<string, int> dataORL[] = {Tuple<string, int>("a", 6), Tuple<string, int>("c", 8), Tuple<string, int>("g", 7), Tuple<string, int>("b", 3), Tuple<string, int>("d", 4), Tuple<string, int>("e", 5), Tuple<string, int>("f", 1), Tuple<string, int>("i", 2), Tuple<string, int>("h", 0)};
    Sequence<Tuple<string, int>> *seqORL = new ArraySequence<Tuple<string, int>>(dataORL, 9);

    Tuple<string, int> dataOLR[] = {Tuple<string, int>("a", 6), Tuple<string, int>("b", 3), Tuple<string, int>("f", 1), Tuple<string, int>("h", 0), Tuple<string, int>("i", 2), Tuple<string, int>("d", 4), Tuple<string, int>("e", 5), Tuple<string, int>("c", 8), Tuple<string, int>("g", 7)};
    Sequence<Tuple<string, int>> *seqOLR = new ArraySequence<Tuple<string, int>>(dataOLR, 9);

    Sequence<Tuple<string, int>> *seqInvalid = new ArraySequence<Tuple<string, int>>;

    if (((*traversalROL) == (*seqROL)) && ((*traversalRLO) == (*seqRLO)) && ((*traversalLOR) == (*seqLOR)) && ((*traversalLRO) == (*seqLRO)) && ((*traversalORL) == (*seqORL)) && ((*traversalOLR) == (*seqOLR)) && ((*traversalInvalid) == (*seqInvalid))) cout << "Traversal       : passed\n";
    else {
        cout << "Traversal       : failed\n";
        (*check) = false;
    }

    delete traversalROL;
    delete traversalRLO;
    delete traversalLOR;
    delete traversalLRO;
    delete traversalORL;
    delete traversalOLR;
    delete traversalInvalid;
    delete seqROL;
    delete seqRLO;
    delete seqLOR;
    delete seqLRO;
    delete seqORL;
    delete seqOLR;
    delete seqInvalid;
}

void testBinaryTree_Balance(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> checkTree("d", 4);
    checkTree.AddNode("i", 2);
    checkTree.AddNode("g", 7);
    checkTree.AddNode("f", 1);
    checkTree.AddNode("b", 3);
    checkTree.AddNode("a", 6);
    checkTree.AddNode("c", 8);
    checkTree.AddNode("h", 0);
    checkTree.AddNode("e", 5);

    BinaryTree<string, int> *balancedTree = tree.Balance();

    BinaryTree<string, int> emptyTree;
    BinaryTree<string, int> *balancedEmptyTree = emptyTree.Balance();

    if ((checkTree == (*balancedTree)) && (emptyTree == (*balancedEmptyTree))) cout << "Balance         : passed\n";
    else {
        cout << "Balance         : failed\n";
        (*check) = false;
    }

    delete balancedTree;
    delete balancedEmptyTree;
}

int mapBinaryTree(int a) {
    return 2 * a;
}

void testBinaryTree_Map(bool *check) {
    BinaryTree<int, int> tree(6, 6);
    tree.AddNode(3, 3);
    tree.AddNode(8, 8);
    tree.AddNode(4, 4);
    tree.AddNode(5, 5);
    tree.AddNode(1, 1);
    tree.AddNode(7, 7);
    tree.AddNode(0, 0);
    tree.AddNode(2, 2);

    BinaryTree<int, int> checkTree(12, 6);
    checkTree.AddNode(6, 3);
    checkTree.AddNode(16, 8);
    checkTree.AddNode(8, 4);
    checkTree.AddNode(10, 5);
    checkTree.AddNode(2, 1);
    checkTree.AddNode(14, 7);
    checkTree.AddNode(0, 0);
    checkTree.AddNode(4, 2);

    BinaryTree<int, int> *mapTree = tree.Map(mapBinaryTree);

    BinaryTree<int, int> emptyTree;
    BinaryTree<int, int> *mapEmptyTree = emptyTree.Map(mapBinaryTree);

    if ((checkTree == (*mapTree)) && (emptyTree == (*mapEmptyTree))) cout << "Map             : passed\n";
    else {
        cout << "Map             : failed\n";
        (*check) = false;
    }

    delete mapTree;
    delete mapEmptyTree;
}

bool whereBinaryTree(int a) {
    if (a % 2 == 0) return true;
    return false;
}

void testBinaryTree_Where(bool *check) {
    BinaryTree<int, int> tree(6, 6);
    tree.AddNode(3, 3);
    tree.AddNode(8, 8);
    tree.AddNode(4, 4);
    tree.AddNode(5, 5);
    tree.AddNode(1, 1);
    tree.AddNode(7, 7);
    tree.AddNode(0, 0);
    tree.AddNode(2, 2);

    BinaryTree<int, int> checkTree(6, 6);
    checkTree.AddNode(0, 0);
    checkTree.AddNode(2, 2);
    checkTree.AddNode(4, 4);
    checkTree.AddNode(8, 8);

    BinaryTree<int, int> *whereTree = tree.Where(whereBinaryTree);

    BinaryTree<int, int> emptyTree;
    BinaryTree<int, int> *whereEmptyTree = emptyTree.Where(whereBinaryTree);

    if ((checkTree == (*whereTree)) && (emptyTree == (*whereEmptyTree))) cout << "Where           : passed\n";
    else {
        cout << "Where           : failed\n";
        (*check) = false;
    }

    delete whereTree;
    delete whereEmptyTree;
}

int reduceBinaryTree(int a, int b) {
    return a + b;
}

void testBinaryTree_Reduce(bool *check) {
    BinaryTree<int, int> tree(6, 6);
    tree.AddNode(3, 3);
    tree.AddNode(8, 8);
    tree.AddNode(4, 4);
    tree.AddNode(5, 5);
    tree.AddNode(1, 1);
    tree.AddNode(7, 7);
    tree.AddNode(0, 0);
    tree.AddNode(2, 2);

    int reduce;
    bool check0 = true;
    try {
        reduce = tree.Reduce(reduceBinaryTree, 10, "LOR");
    }
    catch (...) {
        check0 = false;
    }

    BinaryTree<int, int> emptyTree;

    int r;
    bool check1 = false;
    try {
        r = emptyTree.Reduce(reduceBinaryTree, 10, "LOR");
    }
    catch (...) {
        check1 = true;
    }

    if ((reduce == 46) && check1) cout << "Reduce          : passed\n";
    else {
        cout << "Reduce          : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_GetSubTree(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> checkTree("b", 3);
    checkTree.AddNode("f", 1);
    checkTree.AddNode("d", 4);
    checkTree.AddNode("h", 0);
    checkTree.AddNode("i", 2);
    checkTree.AddNode("e", 5);

    BinaryTree<string, int> *subTree1 = tree.GetSubTreeByData("b");
    BinaryTree<string, int> *subTree2 = tree.GetSubTreeByNode(Tuple<string, int>("b", 3));

    bool check1 = false;
    try {
        BinaryTree<string, int> *subTreeInvalid = tree.GetSubTreeByData("q");
    }
    catch (...) {
        check1 = true;
    }

    bool check2 = false;
    try {
        BinaryTree<string, int> *subTreeInvalid = tree.GetSubTreeByNode(Tuple<string, int>("t", 3));
    }
    catch (...) {
        check2 = true;
    }

    if ((checkTree == (*subTree1)) && (checkTree == (*subTree2)) && check1 && check2) cout << "GetSubTree      : passed\n";
    else {
        cout << "GetSubTree      : failed\n";
        (*check) = false;
    }

    delete subTree1;
    delete subTree2;
}

void testBinaryTree_Copy(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> emptyTree;

    BinaryTree<string, int> *copyTree = tree.Copy();
    BinaryTree<string, int> *copyEmptyTree = emptyTree.Copy();

    if ((tree == (*copyTree)) && (emptyTree == (*copyEmptyTree))) cout << "Copy            : passed\n";
    else {
        cout << "Copy            : failed\n";
        (*check) = false;
    }

    delete copyTree;
    delete copyEmptyTree;
}

void testBinaryTree_Operator1(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> addedTree("a", 10);
    addedTree.AddNode("q", -1);
    addedTree.AddNode("s", 11);
    addedTree.AddNode("z", 0);
    addedTree.AddNode("i", 2);

    BinaryTree<string, int> checkTree("a", 6);
    checkTree.AddNode("b", 3);
    checkTree.AddNode("c", 8);
    checkTree.AddNode("d", 4);
    checkTree.AddNode("e", 5);
    checkTree.AddNode("f", 1);
    checkTree.AddNode("g", 7);
    checkTree.AddNode("h", 0);
    checkTree.AddNode("i", 2);
    checkTree.AddNode("q", -1);
    checkTree.AddNode("s", 11);

    BinaryTree<string, int> *mergeTree = tree + addedTree;
    if (checkTree == (*mergeTree)) cout << "Operator +      : passed\n";
    else {
        cout << "Operator +      : failed\n";
        (*check) = false;
    }

    delete mergeTree;
}

void testBinaryTree_ContainsData(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> emptyTree;

    if ((tree.ContainsData("e")) && !(tree.ContainsData("q")) && !(emptyTree.ContainsData("a"))) cout << "ContainsData    : passed\n";
    else {
        cout << "ContainsData    : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_ContainsKey(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> emptyTree;

    if ((tree.ContainsKey(1)) && !(tree.ContainsKey(-1)) && !(emptyTree.ContainsKey(0))) cout << "ContainsKey     : passed\n";
    else {
        cout << "ContainsKey     : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_ContainsNode(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> emptyTree;

    if ((tree.ContainsNode(Tuple<string, int>("i", 2))) && !(tree.ContainsNode(Tuple<string, int>("b", -1))) && !(tree.ContainsNode(Tuple<string, int>("b", 4))) && !(emptyTree.ContainsNode(Tuple<string, int>("b", -1)))) cout << "ContainsNode    : passed\n";
    else {
        cout << "ContainsNode    : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_ContainsSubTree(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> subTree1("b", 3);
    subTree1.AddNode("d", 4);
    subTree1.AddNode("e", 5);

    BinaryTree<string, int> subTree2("d", 4);
    subTree2.AddNode("b", 3);
    subTree2.AddNode("e", 5);

    BinaryTree<string, int> subTree3("b", 3);
    subTree3.AddNode("f", 1);
    subTree3.AddNode("h", 0);
    subTree3.AddNode("i", 2);

    BinaryTree<string, int> subTree4("b", 3);
    subTree4.AddNode("f", 1);
    subTree4.AddNode("h", 0);
    subTree4.AddNode("i", 2);
    subTree4.AddNode("d", 4);
    subTree4.AddNode("e", 5);

    BinaryTree<string, int> emptyTree;

    if ((tree.ContainsSubTree(subTree1)) && !(tree.ContainsSubTree(subTree2)) && (tree.ContainsSubTree(subTree3)) && (tree.ContainsSubTree(subTree4)) && !(emptyTree.ContainsSubTree(tree)) && !(tree.ContainsSubTree(emptyTree))) cout << "ContainsSubTree : passed\n";
    else {
        cout << "ContainsSubTree : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_Operator2(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> cmpTree("a", 6);
    cmpTree.AddNode("b", 3);
    cmpTree.AddNode("c", 8);
    cmpTree.AddNode("d", 4);
    cmpTree.AddNode("e", 5);
    cmpTree.AddNode("g", 7);
    cmpTree.AddNode("h", 0);
    cmpTree.AddNode("f", 1);
    cmpTree.AddNode("i", 2);

    if ((tree == tree) && !(tree == cmpTree)) cout << "Operator ==     : passed\n";
    else {
        cout << "Operator ==     : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_Operator3(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> emptyTree;

    string data = tree[1];

    bool check1 = false;
    try {
        data = tree[-1];
    }
    catch (...) {
        check1 = true;
    }

    bool check2 = false;
    try {
        data = emptyTree[0];
    }
    catch (...) {
        check2 = true;
    }

    if ((data == "f") && check1 && check2) cout << "Operator []     : passed\n";
    else {
        cout << "Operator []     : failed\n";
        (*check) = false;
    }
}

void testBinaryTree_FindKeyByData(bool *check) {
    BinaryTree<string, int> tree("a", 6);
    tree.AddNode("b", 3);
    tree.AddNode("c", 8);
    tree.AddNode("d", 4);
    tree.AddNode("e", 5);
    tree.AddNode("f", 1);
    tree.AddNode("g", 7);
    tree.AddNode("h", 0);
    tree.AddNode("i", 2);

    BinaryTree<string, int> emptyTree;

    int key = tree.FindKeyByData("g");

    bool check1 = false;
    try {
        key = tree.FindKeyByData("abc");
    }
    catch (...) {
        check1 = true;
    }

    bool check2 = false;
    try {
        key = emptyTree.FindKeyByData("a");
    }
    catch (...) {
        check2 = true;
    }

    if ((key == 7) && check1 && check2) cout << "FindKeyByData   : passed\n";
    else {
        cout << "FindKeyByData   : failed\n";
        (*check) = false;
    }
}

