#include "../SequenceClasses/Sequence.hpp"
#include "../Tuple.hpp"
#include "../Concepts.hpp"

using namespace std;

#ifndef binaryTree_h
#define binaryTree_h

template <StoredTypes T, TotalOrdering C>
class BinaryTree {
private:
    class Node {
    private:
        T data;
        C key;
        Node *left;
        Node *right;

    public:
        Node() {
            left = NULL;
            right = NULL;
        }

        Node(T value, C keyValue) {
            data = value;
            key = keyValue;
            left = NULL;
            right = NULL;
        }

        void Destroy() {
            if (left != NULL) left->Destroy();
            if (right != NULL) right->Destroy();
            delete this;
        }

        T GetData() const noexcept {
            return data;
        }

        C GetKey() const noexcept {
            return key;
        }

        Node *GetLeft() const noexcept {
            return left;
        }

        Node *GetRight() const noexcept {
            return right;
        }

        void SetData(T value) noexcept {
            data = value;
        }

        void SetKey(C value) noexcept {
            key = value;
        }

        void SetLeft(Node *ptr) noexcept {
            left = ptr;
        }

        void SetRight(Node *ptr) noexcept {
            right = ptr;
        }

        void AddNode(T newData, C newKey) {
            if ((newKey == key) || (newData == data)) 
                throw out_of_range("This values are already in use\n");

            if (newKey < key) {
                if (left == NULL) left = new Node(newData, newKey);
                else left->AddNode(newData, newKey);
            } else {
                if (right == NULL) right = new Node(newData, newKey);
                else right->AddNode(newData, newKey);
            }
        }

        Tuple<T, C> FindMinNode(Node *parent, int direction) noexcept {
            Tuple<T, C> tuple;
            if (left == NULL) {
                tuple = Tuple<T, C>(data, key);
                if (direction == 0) parent->left = right;
                if (direction == 1) parent->right = right;
                delete this;
            } else tuple = left->FindMinNode(this, 0);

            return tuple;
        }

        void DeleteNodeByKey(Node **root, Node *parent, int direction, C keyValue) {
            if (keyValue == key) {
                if ((left == NULL) && (right == NULL)) {
                    if (this != *root) {
                        if (direction == 0) parent->left = NULL;
                        if (direction == 1) parent->right = NULL;
                        delete this;
                    } else {
                        delete (*root);
                        *root = NULL;
                    }
                } else if ((left == NULL) && (right != NULL)) {
                    if (this != *root) {
                        if (direction == 0) parent->left = right;
                        if (direction == 1) parent->right = right;
                        delete this;
                    } else {
                        Node *ptrRight = right;
                        **root = *right;
                        delete ptrRight;
                    }
                } else if ((left != NULL) && (right == NULL)) {
                    if (this != *root) {
                        if (direction == 0) parent->left = left;
                        if (direction == 1) parent->right = left;
                        delete this;
                    } else {
                        Node *ptrLeft = left;
                        **root = *left;
                        delete ptrLeft;
                    }
                } else if ((left != NULL) && (right != NULL)) {
                    Tuple<T, C> newValues = right->FindMinNode(this, 1);
                    data = newValues.GetItem1();
                    key = newValues.GetItem2();
                }
            } else if (keyValue < key) {
                if (left != NULL) left->DeleteNodeByKey(root, this, 0, keyValue);
                else 
                    throw out_of_range("There is no specified key in the tree\n");

            } else {
                if (right != NULL) right->DeleteNodeByKey(root, this, 1, keyValue);
                else 
                    throw out_of_range("There is no specified key in the tree\n");
            }
        }

        void TraversalOriginLeftRight(Sequence<Tuple<T, C>> *seq) const noexcept {
            Tuple<T, C> tuple(data, key);
            seq->Append(tuple);
            if (left != NULL) left->TraversalOriginLeftRight(seq);
            if (right != NULL) right->TraversalOriginLeftRight(seq);
        }

        void TraversalOriginRightLeft(Sequence<Tuple<T, C>> *seq) const noexcept {
            Tuple<T, C> tuple(data, key);
            seq->Append(tuple);
            if (right != NULL) right->TraversalOriginRightLeft(seq);
            if (left != NULL) left->TraversalOriginRightLeft(seq);
        }

        void TraversalLeftRightOrigin(Sequence<Tuple<T, C>> *seq) const noexcept {
            if (left != NULL) left->TraversalLeftRightOrigin(seq);
            if (right != NULL) right->TraversalLeftRightOrigin(seq);
            Tuple<T, C> tuple(data, key);
            seq->Append(tuple);
        }

        void TraversalLeftOriginRight(Sequence<Tuple<T, C>> *seq) const noexcept {
            if (left != NULL) left->TraversalLeftOriginRight(seq);
            Tuple<T, C> tuple(data, key);
            seq->Append(tuple);
            if (right != NULL) right->TraversalLeftOriginRight(seq);
        }

        void TraversalRightLeftOrigin(Sequence<Tuple<T, C>> *seq) const noexcept {
            if (right != NULL) right->TraversalRightLeftOrigin(seq);
            if (left != NULL) left->TraversalRightLeftOrigin(seq);
            Tuple<T, C> tuple(data, key);
            seq->Append(tuple);
        }

        void TraversalRightOriginLeft(Sequence<Tuple<T, C>> *seq) const noexcept {
            if (right != NULL) right->TraversalRightOriginLeft(seq);
            Tuple<T, C> tuple(data, key);
            seq->Append(tuple);
            if (left != NULL) left->TraversalRightOriginLeft(seq);
        }

        void Map(BinaryTree<T, C> *tree, T (*function)(T)) const noexcept {
            T newData = function(data);
            tree->AddNode(newData, key);
            if (left != NULL) left->Map(tree, function);
            if (right != NULL) right->Map(tree, function);
        }

        void Where(BinaryTree<T, C> *tree, bool (*function)(T)) const noexcept {
            if (function(data)) tree->AddNode(data, key);
            if (left != NULL) left->Where(tree, function);
            if (right != NULL) right->Where(tree, function);
        }        

        void SubTreeByKey(BinaryTree<T, C> *tree, bool *flag, C value) const noexcept {
            if ((value == key) || (*flag)) {
                (*flag) = true;
                tree->AddNode(data, key);
                if (left != NULL) left->SubTreeByKey(tree, flag, value);
                if (right != NULL) right->SubTreeByKey(tree, flag, value);
            } else if (value < key) {
                if (left != NULL) left->SubTreeByKey(tree, flag, value);
            } else {
                if (right != NULL) right->SubTreeByKey(tree, flag, value);
            }
        }

        bool ContainsData(T value) const noexcept {
            if (value == data) 
                return true;

            bool leftContains = false;
            bool rightContains = false;
            if (left != NULL) leftContains = left->ContainsData(value);
            if (right != NULL) rightContains = right->ContainsData(value);

            return (leftContains || rightContains);
        }

        bool ContainsKey(C value) const noexcept {
            if (value == key) 
                return true;

            if (value < key) {
                if (left == NULL) 
                    return false;

                return left->ContainsKey(value);
            }
            if (right == NULL) 
                return false;

            return right->ContainsKey(value);
        }

        bool ContainsNode(T dataValue, C keyValue) const noexcept {
            if ((dataValue == data) && (keyValue == key)) 
                return true;

            if (keyValue < key) {
                if (left == NULL) 
                    return false;
                
                return left->ContainsNode(dataValue, keyValue);
            }
            if (right == NULL) 
                return false;
            
            return right->ContainsNode(dataValue, keyValue);
        }

        T FindDataByKey(C value) const {
            if (value == key) 
                return data;

            T res;
            if (value < key) {
                if (left == NULL) 
                    throw out_of_range("There is no specified key in the tree\n");

                try {
                    res = left->FindDataByKey(value);
                }
                catch (...) {
                    throw;
                }
            } else {
                if (right == NULL) 
                    throw out_of_range("There is no specified key in the tree\n");

                try {
                    res = right->FindDataByKey(value);
                }
                catch (...) {
                    throw;
                }
            }

            return res;
        }
    
        C FindKeyByData(T value) const {
            if (!(this->ContainsData(value))) 
                throw out_of_range("There is no specified data in the tree\n");
            
            if (value == data) 
                return key;
            
            C res;
            if (left != NULL) if (left->ContainsData(value)) res = left->FindKeyByData(value);
            if (right != NULL) if (right->ContainsData(value)) res = right->FindKeyByData(value);
            
            return res;
        }

    };

    Node *root;

    void Balance(BinaryTree<T, C> *tree, const Sequence<Tuple<T, C>> *nodes) const noexcept {
        int len = nodes->GetLength();
        if (len != 0) {
            int middle = len / 2;
            Tuple<T, C> middleNode = (*nodes)[middle];
            tree->AddNode(middleNode);
            if (middle - 1 >= 0) {
                Sequence<Tuple<T, C>> *leftNodes = nodes->GetSubSequence(0, middle - 1);
                Balance(tree, leftNodes);
                delete leftNodes;
            }
            if (middle + 1 <= len - 1) {
                Sequence<Tuple<T, C>> *rightNodes = nodes->GetSubSequence(middle + 1, len - 1);
                Balance(tree, rightNodes);
                delete rightNodes;
            }
        }
    }



public:
    BinaryTree() : root() {}

    BinaryTree(T value, C keyValue) {
        root = new Node(value, keyValue);
    }

    ~BinaryTree() {
        if (root != NULL) root->Destroy();
    }

    void AddNode(T data, C key) {
        if (root == NULL) root = new Node(data, key);
        else root->AddNode(data, key);
    }

    void AddNode(const Tuple<T, C> &tuple) {
        T data = tuple.GetItem1();
        C key = tuple.GetItem2();
        this->AddNode(data, key);
    }

    void DeleteNodeByKey(C value) {
        if (root != NULL) {
            try {
                root->DeleteNodeByKey(&root, root, 0, value);
            }
            catch (...) {
                throw;
            }
        } else 
            throw out_of_range("The tree is empty, impossible to delete key\n");
    }

    void DeleteNodeByData(T value) {
        C key;
        try {
            key = this->FindKeyByData(value);
        }
        catch (...) {
            throw;
        }
        this->DeleteNodeByKey(key);
    }

    Tuple<T, C> *GetRoot() const {
        if (root == NULL) 
            throw out_of_range("The root is null pointer\n");

        T data = root->GetData();
        C key = root->GetKey();
        Tuple<T, C> *tuple = new Tuple<T, C>(data, key);

        return tuple;
    }

    BinaryTree<T, C> *GetLeftSubTree() const {
        if (root == NULL) 
            throw out_of_range("The tree is empty\n");

        Node *left = root->GetLeft();
        BinaryTree<T, C> *leftSubTree = new BinaryTree<T, C>;
        if (left == NULL) 
            return leftSubTree;

        C leftKey = left->GetKey();
        bool flag = false;
        left->SubTreeByKey(leftSubTree, &flag, leftKey);
        
        return leftSubTree;
    }

    BinaryTree<T, C> *GetRightSubTree() const {
        if (root == NULL) 
            throw out_of_range("The tree is empty\n");

        Node *right = root->GetRight();
        BinaryTree<T, C> *rightSubTree = new BinaryTree<T, C>;
        if (right == NULL) 
            return rightSubTree;
        
        C rightKey = right->GetKey();
        bool flag = false;
        right->SubTreeByKey(rightSubTree, &flag, rightKey);
        
        return rightSubTree;
    }

    Sequence<Tuple<T, C>> *Traversal(string way) const noexcept {
        Sequence<Tuple<T, C>> *traversal = new ArraySequence<Tuple<T, C>>;
        if (root != NULL) {
            if (way == "ROL") root->TraversalRightOriginLeft(traversal);
            else if (way == "RLO") root->TraversalRightLeftOrigin(traversal);
            else if (way == "LOR") root->TraversalLeftOriginRight(traversal);
            else if (way == "LRO") root->TraversalLeftRightOrigin(traversal);
            else if (way == "ORL") root->TraversalOriginRightLeft(traversal);
            else if (way == "OLR") root->TraversalOriginLeftRight(traversal);
        }

        return traversal;
    }

    BinaryTree<T, C> *Balance() const noexcept {
        BinaryTree<T, C> *tree = new BinaryTree<T, C>;
        Sequence<Tuple<T, C>> *nodes = this->Traversal("LOR");
        Balance(tree, nodes);
        delete nodes;

        return tree;
    }

    BinaryTree<T, C> *Map(T (*function)(T)) const noexcept {
        BinaryTree<T, C> *tree = new BinaryTree<T, C>;
        if (root != NULL) root->Map(tree, function);
        
        return tree;
    }

    BinaryTree<T, C> *Where(bool (*function)(T)) const noexcept {
        BinaryTree<T, C> *tree = new BinaryTree<T, C>;
        if (root != NULL) root->Where(tree, function);

        return tree;
    }

    T Reduce(T (*function)(T, T), T startValue, string way) const {
        Sequence<Tuple<T, C>> *nodes = this->Traversal(way);
        Sequence<T> *data = new ArraySequence<T>;
        int len = nodes->GetLength();
        for (int i = 0; i < len; i++) {
            Tuple<T, C> el = (*nodes)[i];
            data->Append(el.GetItem1());
        }
        T result;
        try {
            result = data->Reduce(function, startValue);
        }
        catch (...) {
            delete nodes;
            delete data;
            throw out_of_range("Impossible to reduce empty tree\n");
        }
        delete nodes;
        delete data;

        return result;
    }

    BinaryTree<T, C> *GetSubTreeByKey(C key) const {
        BinaryTree<T, C> *tree = new BinaryTree<T, C>;
        if (!(this->ContainsKey(key))) 
            throw out_of_range("There is no specified key in the tree\n");
        
        bool flag = false;
        root->SubTreeByKey(tree, &flag, key);
        
        return tree;
    }

    BinaryTree<T, C> *GetSubTreeByData(T data) const {
        if (!(this->ContainsData(data))) 
            throw out_of_range("There is no specified data in the tree\n");
        
        C key = this->FindKeyByData(data);
        BinaryTree<T, C> *tree = this->GetSubTreeByKey(key);
        
        return tree;
    }

    BinaryTree<T, C> *GetSubTreeByNode(const Tuple<T, C> &node) const {
        if (!(this->ContainsNode(node))) 
            throw out_of_range("There is no specified node in the tree\n");
        
        BinaryTree<T, C> *tree = this->GetSubTreeByKey(node.GetItem2());
        
        return tree;
    }

    BinaryTree<T, C> *Copy() const noexcept {
        BinaryTree<T, C> *copy = new BinaryTree<T, C>;
        Sequence<Tuple<T, C>> *nodes = this->Traversal("OLR");
        int len = nodes->GetLength();
        for (int i = 0; i < len; i++) {
            copy->AddNode((*nodes)[i]);
        }
        delete nodes;

        return copy;
    }

    BinaryTree<T, C> *Merge(const BinaryTree<T, C> &tree) const noexcept {
        BinaryTree<T, C> *merge = this->Copy();
        Sequence<Tuple<T, C>> *nodes = this->Traversal("OLR");
        Sequence<T> *data = new ArraySequence<T>;
        Sequence<C> *keys = new ArraySequence<C>;
        int thisLen = nodes->GetLength();
        Tuple<T, C> el;
        for (int i = 0; i < thisLen; i++) {
            el = (*nodes)[i];
            data->Append(el.GetItem1());
            keys->Append(el.GetItem2());
        }
        Sequence<Tuple<T, C>> *newNodes = tree.Traversal("OLR");
        int len = newNodes->GetLength();
        for (int i = 0; i < len; i++) {
            el = (*newNodes)[i];
            if ((!(data->Contains(el.GetItem1()))) && (!(keys->Contains(el.GetItem2())))) merge->AddNode(el);
        }
        delete nodes;
        delete data;
        delete keys;
        delete newNodes;

        return merge;
    }

    BinaryTree<T, C> *operator+(const BinaryTree<T, C> &tree) const noexcept {
        return this->Merge(tree);
    }

    bool ContainsData(T value) const noexcept {
        if (root == NULL) 
            return false;

        return root->ContainsData(value);
    }

    bool ContainsKey(C value) const noexcept {
        if (root == NULL) 
            return false;
        
        return root->ContainsKey(value);
    }

    bool ContainsNode(const Tuple<T, C> &node) const noexcept {
        if (root == NULL) 
            return false;
        
        return root->ContainsNode(node.GetItem1(), node.GetItem2());
    }

    bool ContainsSubTree(const BinaryTree<T, C> &subTree) const noexcept {
        if (root == NULL) 
            return false;
        
        Tuple<T, C> *rootSubTree;
        try {
            rootSubTree = subTree.GetRoot();
        }
        catch (...) {
            return false;
        }

        BinaryTree<T, C> *tree;
        try {
            tree = this->GetSubTreeByNode(*rootSubTree);
        }
        catch (...) {
            return false;
        }

        bool result = false;
        BinaryTree<T, C> *rootTree = new BinaryTree<T, C>(rootSubTree->GetItem1(), rootSubTree->GetItem2());
        BinaryTree<T, C> *leftSubTree = tree->GetLeftSubTree();
        BinaryTree<T, C> *leftSubTree1 = (*rootTree) + (*leftSubTree);
        BinaryTree<T, C> *rightSubTree = tree->GetRightSubTree();
        BinaryTree<T, C> *rightSubTree1 = (*rootTree) + (*rightSubTree);
        if ((subTree == (*tree)) || (subTree == (*leftSubTree1)) || (subTree == (*rightSubTree1))) result = true;
        delete rootSubTree;
        delete tree;
        delete rootTree;
        delete leftSubTree;
        delete leftSubTree1;
        delete rightSubTree;
        delete rightSubTree1;

        return result;
    }

    bool operator==(const BinaryTree<T, C> &tree) const noexcept {
        Sequence<Tuple<T, C>> *nodes1 = this->Traversal("OLR");
        Sequence<Tuple<T, C>> *nodes2 = tree.Traversal("OLR");
        bool cmp = false;
        if ((*nodes1) == (*nodes2)) cmp = true;
        delete nodes1;
        delete nodes2;

        return cmp;
    }

    T FindDataByKey(C key) const {
        if (root == NULL) 
            throw out_of_range("The tree is empty\n");
        
        T data;
        try {
            data = root->FindDataByKey(key);
        }
        catch (...) {
            throw;
        }

        return data;
    }

    T operator[](C key) const {
        T data;
        try {
            data = this->FindDataByKey(key);
        }
        catch (...) {
            throw;
        }

        return data;
    }

    C FindKeyByData(T data) const {
        if (root == NULL) 
            throw out_of_range("The tree is empty\n");
        
        C key;
        try {
            key = root->FindKeyByData(data);
        }
        catch (...) {
            throw;
        }
        
        return key;
    }

};

#endif