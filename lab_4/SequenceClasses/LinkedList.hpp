#include <iostream>

#ifndef linkedList_h
#define linkedList_h

template <class T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node *next;
    };
    size_t len;
    Node *head;
    Node *tail;
public:
    LinkedList(const T *items, int count) {
        if (count < 0) throw std::out_of_range("Invalid length of sequence\n");
        len = count;
        if (len == 0) {
            head = NULL;
            tail = NULL;
        } else {
            head = new Node;
            head->data = items[0];
            head->next = NULL;
            tail = head;
            Node *ptr = head;
            for (int i = 1; i < count; i++) {
                Node *ptrNext = new Node;
                ptrNext->data = items[i];
                ptrNext->next = NULL;
                ptr->next = ptrNext;
                ptr = ptrNext;
                tail = ptrNext;
            }
        }
    }

    LinkedList() noexcept : len(0), head(), tail() {}

    LinkedList(LinkedList<T> &&list) noexcept {
        len = list.len;
        if (len == 0) {
            head = NULL;
            tail = NULL;
        } else {
            head = new Node;
            head->data = list.head->data;
            head->next = NULL;
            tail = head;
            Node *ptr = head;
            Node *ptrList = list.head->next;
            for (int i = 1; i < len; i++) {
                Node *ptrNext = new Node;
                ptrNext->data = ptrList->data;
                ptrNext->next = NULL;
                ptr->next = ptrNext;
                tail = ptrNext;
                ptr = ptrNext;
                ptrList = ptrList->next;
            }
        }
    }

    ~LinkedList() {
        if (len != 0) {
            Node *ptr = head;
            Node *ptrNext = ptr->next;
            while (ptr != NULL) {
                delete ptr;
                ptr = ptrNext;
                if (ptr != NULL) ptrNext = ptr->next;
            }
        }
    }

    T GetFirst() const {
        if (len == 0) throw std::out_of_range("The sequence is empty\n");
        return head->data;
    }

    T GetLast() const {
        if (len == 0) throw std::out_of_range("The sequence is empty\n");
        return tail->data;
    }
    
    T Get(int index) const {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        Node *ptr = head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    }

    LinkedList<T> *GetSubList(int startIndex, int endIndex) const {
        if ((startIndex < 0) || (startIndex >= len) || (endIndex < 0) || (endIndex >= len)) throw std::out_of_range("Index out of range\n");
        if (startIndex > endIndex) throw std::out_of_range("Start index is more than end index\n");
        T *items = new T[endIndex - startIndex + 1];
        Node *ptr = head;
        int index = 0;
        while(index <= endIndex) {
            if (index >= startIndex) items[index - startIndex] = ptr->data;
            ptr = ptr->next;
            index++;
        }
        LinkedList<T> *list = new LinkedList<T>(items, endIndex - startIndex + 1);
        delete [] items;
        return list;
    }

    size_t GetLength() const noexcept {
        return len;
    }

    void Append(T item) noexcept {
        Node *newNode = new Node;
        newNode->data = item;
        newNode->next = NULL;
        if (len == 0) head = newNode;
        else tail->next = newNode;
        tail = newNode;
        len++;
    }

    void Prepend(T item) noexcept {
        Node *newNode = new Node;
        newNode->data = item;
        if (len == 0) {
            newNode->next = NULL;
            tail = newNode;
        } else newNode->next = head;
        head = newNode;
        len++;
    }

    void InsertAt(T item, int index) {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        Node *newNode = new Node;
        newNode->data = item;
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            int count = 0;
            Node *ptr = head;
            while(count < index - 1) {
                ptr = ptr->next;
                count++;
            }
            Node *ptrNext = ptr->next;
            newNode->next = ptrNext;
            ptr->next = newNode;
        }
        len++;
    }

    void Delete(int index) {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        if (len == 1) delete head;
        else if (index == 0) {
            Node *ptr = head;
            head = head->next;
            delete ptr;
        } else if (index == len - 1) {
            Node *ptr = head;
            while (ptr->next != tail) {
                ptr = ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next = NULL;
        } else {
            Node *ptr = head;
            for (int i = 0; i < index - 1; i++) {
                ptr = ptr->next;
            }
            Node *ptrDel = ptr->next;
            ptr->next = ptrDel->next;
            delete ptrDel;
        }
        len--;
    }

    void Set(int index, T value) {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        Node *ptr = head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        ptr->data = value;
    }

    LinkedList<T> *Concat(const LinkedList<T> *list) {
        if (list == NULL) throw std::out_of_range("Using null pointer\n");
        if ((len == 0) && (list->GetLength() == 0)) {
            LinkedList<T> *concatList = new LinkedList;
            return concatList;
        }
        if (len == 0) {
            LinkedList<T> *concatList = new LinkedList<T>(*list);
            return concatList;
        }
        if (list->GetLength() == 0) {
            LinkedList<T> *concatList = new LinkedList<T>(*this);
            return concatList;
        }
        LinkedList<T> *concatList = new LinkedList<T>(&(head->data), 1);
        Node *ptr = head->next;
        for (int i = 1; i < len; i++) {
            concatList->Append(ptr->data);
            ptr = ptr->next;
        }
        ptr = list->head;
        for (int i = 0; i < list->len; i++) {
            concatList->Append(ptr->data);
            ptr = ptr->next;
        }
        return concatList;
    }
};

#endif