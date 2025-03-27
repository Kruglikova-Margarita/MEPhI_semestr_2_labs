#include "../SequenceClasses/Sequence.hpp"
#include "../Tuple.hpp"
#include "../Concepts.hpp"
#include "../Printers.hpp"

using namespace std;

#ifndef nTree_h
#define nTree_h

template <StoredTypes T, TotalOrdering C>
class NTree {
private:
    class Node {
    private:
        size_t degree;
        Sequence<Tuple<T, C>> *values;
        Sequence<Node *> *children;

    public:
        Node(const Tuple<T, C> &newValue, size_t newDegree) {
            degree = newDegree;
            values = new ArraySequence<Tuple<T, C>>;
            values->Append(newValue);
            children = new ArraySequence<Node *>;
            for (int i = 0; i < degree; i++) {
                children->Append(NULL);
            }
        }

        ~Node() {
            delete values;
            delete children;
        }

        void Destroy() {
            for (int i = 0; i < degree; i++) {
                if ((*children)[i] != NULL) ((*children)[i])->Destroy();
            }
            delete this;
        }

        void ContainsData(T data, bool *contains) const noexcept {
            size_t numValues = values->GetLength();
            for (int i = 0; i < numValues; i++) {
                if (data == ((*values)[i]).GetItem1()) {
                    (*contains) = true;
                    break;
                }
            }
            if (!(*contains)) {
                for (int i = 0; i <= numValues; i++) {
                    if ((*children)[i] != NULL) ((*children)[i])->ContainsData(data, contains);
                }
            }
        }

        void ContainsKey(C key, bool *contains) const noexcept {
            size_t index = 0;
            size_t numValues = values->GetLength();
            for (int i = 0; i < numValues; i++) {
                if (key == ((*values)[i]).GetItem2()) (*contains) = true;
                else if (key > ((*values)[i]).GetItem2()) index++;
                else break;
            }
            if (!(*contains)) {
                if ((*children)[index] != NULL) ((*children)[index])->ContainsKey(key, contains);
            }
        }

        void Insert(const Tuple<T, C> &newValue) {
            T newData = newValue.GetItem1();
            C newKey = newValue.GetItem2();
            size_t indexInsert = 0;
            size_t numValues = values->GetLength();
            for (int i = 0; i < numValues; i++) {
                if (newKey == ((*values)[i]).GetItem2()) 
                    throw out_of_range("This key are already in use\n");
                
                if (newKey > ((*values)[i]).GetItem2()) indexInsert++;
                else break;
            }
            if (numValues < degree - 1) {
                if (indexInsert < numValues) values->InsertAt(newValue, indexInsert);
                else values->Append(newValue);
            }
            else {
                if ((*children)[indexInsert] != NULL) ((*children)[indexInsert])->Insert(newValue);
                else {
                    Node *child = new Node(newValue, degree);
                    children->Set(indexInsert, child);
                }
            }
        }

        void SearchByKey(C key, T *data) const {
            size_t indexSearch = 0;
            bool isValue = false;
            size_t numValues = values->GetLength();
            for (int i = 0; i < numValues; i++) {
                if (key == ((*values)[i]).GetItem2()) isValue = true;
                else if (key > ((*values)[i]).GetItem2()) indexSearch++;
                else break;
            }
            if (isValue) (*data) = ((*values)[indexSearch]).GetItem1();
            else {
                if ((*children)[indexSearch] != NULL) ((*children)[indexSearch])->SearchByKey(key, data);
                else 
                    throw out_of_range("There is no specified key in the tree\n");
            }
        }

        void Traversal(Sequence<Tuple<T, C>> *traversal) const noexcept {
            size_t numValues = values->GetLength();
            for (int i = 0; i < numValues; i++) {
                traversal->Append((*values)[i]);
            }
            for (int i = 0; i < degree; i++) {
                if ((*children)[i] != NULL) ((*children)[i])->Traversal(traversal);
            }
        }

        void Map(NTree<T, C> *tree, T (*function)(T)) const noexcept {
            size_t numValues = values->GetLength();
            for (int i = 0; i < numValues; i++) {
                T newData = function(((*values)[i]).GetItem1());
                tree->Insert(Tuple<T, C>(newData, ((*values)[i]).GetItem2()));
            }
            for (int i = 0; i <= numValues; i++) {
                if ((*children)[i] != NULL) ((*children)[i])->Map(tree, function);
            }
        }

    };

    size_t degree;
    Node *root;


public:
    NTree(size_t deg) : degree(deg), root() {}

    NTree(const Tuple<T, C> &value, size_t deg) : degree(deg) {
        root = new Node(value, degree);
    }

    NTree(T data, C key, size_t deg) : degree(deg) {
        root = new Node(Tuple<T, C>(data, key), degree);
    }

    ~NTree() {
        if (root != NULL) root->Destroy();
    }

    bool ContainsData(T data) const noexcept {
        if (root == NULL) 
            return false;
        
        bool contains = false;
        root->ContainsData(data, &contains);

        return contains;
    }

    bool ContainsKey(C key) const noexcept {
        if (root == NULL) 
            return false;
        
        bool contains = false;
        root->ContainsKey(key, &contains);
        
        return contains;
    }

    void Insert(const Tuple<T, C> &newValue) {
        if (root != NULL) {
            bool containsData = false;
            root->ContainsData(newValue.GetItem1(), &containsData);
            if (containsData) 
                throw out_of_range("This data are already in use\n");
            
            try {
                root->Insert(newValue);
            }
            catch (...) {
                throw;
            }
        } else root = new Node(newValue, degree);
    }

    void Insert(T data, C key) {
        try {
            this->Insert(Tuple<T, C>(data, key));
        }
        catch (...) {
            throw;
        }
    }

    void DeleteByKey(C key) {
        if (root != NULL) root->DeleteByKey(key, NULL, 0, &root);
        else 
            throw out_of_range("There is no specified key in the tree\n");
    }

    T SearchByKey(C key) const {
        T data;
        if (root != NULL) {
            try {
                root->SearchByKey(key, &data);
            }
            catch (...) {
                throw;
            }
        } else 
            throw out_of_range("There is no specified key in the tree\n");

        return data;
    }

    T operator[] (C key) const {
        T data;
        try {
            data = this->SearchByKey(key);
        }
        catch (...) {
            throw;
        }

        return data;
    }

    Sequence<Tuple<T, C>> *Traversal() const noexcept {
        Sequence<Tuple<T, C>> *traversal = new ArraySequence<Tuple<T, C>>;
        if (root != NULL) root->Traversal(traversal);
        
        return traversal;
    }

    NTree<T, C> *Map(T (*function)(T)) const noexcept {
        NTree<T, C> *tree = new NTree<T, C>(degree);
        if (root != NULL) root->Map(tree, function);
        
        return tree;
    }

    T Reduce(T (*function)(T, T), T startValue) const {
        Sequence<Tuple<T, C>> *traversal = this->Traversal();
        size_t len = traversal->GetLength();
        Sequence<T> *data = new ArraySequence<T>;
        for (int i = 0; i < len; i++) {
            data->Append(((*traversal)[i]).GetItem1());
        }
        delete traversal;
        T result;
        try {
            result = data->Reduce(function, startValue);
        }
        catch (...) {
            delete data;
            throw;
        }
        delete data;

        return result;
    }

};

#endif