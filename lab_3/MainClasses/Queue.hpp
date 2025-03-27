#include <iostream>
#include <concepts>
#include <complex>
#include <string>
#include "../SequenceClasses/Sequence.hpp"
#include "../StoredClasses/Student.hpp"
#include "../StoredClasses/Teacher.hpp"

#ifndef queue_h
#define queue_h

using namespace std;

template <class T>
concept StoredTypesQueue = same_as<T, int> || same_as<T, float> || same_as<T, complex<float>> || same_as<T, string> || same_as<T, Student> || same_as<T, Teacher>;

template <StoredTypesQueue T>
class Queue {
private:
    Sequence<T> *sequence;
    
public:
    Queue(T *items, int count) {
        try {
            sequence = new ArraySequence<T>(items, count);
        }
        catch (...) {
            throw;
        }
    }

    Queue(Queue<T> &&queue) noexcept : sequence() {
        std::swap(sequence, queue.sequence);
    }

    Queue(const Queue<T> &queue) noexcept {
        sequence = new ArraySequence<T>(*(queue.sequence));
    }

    Queue() noexcept {
        sequence = new ArraySequence<T>;
    }

    ~Queue() {
        delete sequence;
    }

    void Enqueue(T item) noexcept {
        sequence->Append(item);
    }

    T Dequeue() {
        try {
            T item = sequence->GetFirst();
            sequence->Delete(0);
            return item;
        }
        catch (...) {
            throw;
        }
    }

    int GetLength() const noexcept {
        return sequence->GetLength();
    }

    T operator[](int index) const {
        T el;
        try {
            el = (*sequence)[index];
        }
        catch (...) {
            throw;
        }
        return el;
    }

    Queue<T> *Map(T (*function)(T)) const noexcept {
        size_t len = this->GetLength();
        if (len == 0) {
            Queue<T> *mapQueue = new Queue<T>;
            return mapQueue;
        }
        T *items = new T[len];
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            items[i] = function(el);
        }
        Queue<T> *mapQueue = new Queue<T>(items, len);
        delete [] items;
        return mapQueue;
    }

    Queue<T> *Where(bool (*function)(T)) const noexcept {
        size_t len = this->GetLength();
        if (len == 0) {
            Queue<T> *whereQueue = new Queue<T>;
            return whereQueue;
        }
        size_t count = 0;
        for (int i = 0; i < len; i++) {
            T el = (*sequence)[i];
            if (function(el)) count++;
        }
        if (count == 0) {
            Queue<T> *whereQueue = new Queue<T>;
            return whereQueue;
        }
        T *items = new T[count];
        size_t index = 0;
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            if (function(el)) {
                items[index] = el;
                index++;
            }
        }
        Queue<T> *whereQueue = new Queue<T>(items, count);
        delete [] items;
        return whereQueue;
    }

    T Reduce(T (*function)(T, T), T c) const {
        T result;
        try {
            result = sequence->Reduce(function, c);
        }
        catch(...) {
            throw;
        }
        return result;
    }

    Queue<T> *Concat(const Queue<T> &addedQueue) const noexcept {
        size_t thisLen = this->GetLength();
        size_t addedLen = addedQueue.GetLength();
        if ((thisLen + addedLen) == 0) {
            Queue<T> *concatQueue = new Queue<T>;
            return concatQueue;
        }
        T *items = new T[thisLen + addedLen];
        for (int i = 0; i < thisLen; i++) {
            items[i] = (*sequence)[i];
        }
        for (int i = 0; i < addedLen; i++) {
            items[thisLen + i] = addedQueue[i];
        }
        Queue<T> *concatQueue = new Queue<T>(items, thisLen + addedLen);
        delete [] items;
        return concatQueue;
    }

    Queue<T> *operator+(const Queue<T> &addedQueue) const noexcept {
        Queue<T> *result = this->Concat(addedQueue);
        return result;
    }

    Queue<T> *GetSubQueue(int startIndex, int endIndex) const {
        size_t len = this->GetLength();
        if ((startIndex < 0) || (startIndex >= len) || (endIndex < 0) || (endIndex >= len)) throw std::out_of_range("Impossible to get subqueue because index is out of range\n");
        if (startIndex > endIndex) throw std::out_of_range("Impossible to get subqueue because start index is more than end index\n");
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = (*sequence)[i];
        }
        Queue<T> *subQueue = new Queue<T>(items, endIndex - startIndex + 1);
        delete [] items;
        return subQueue;
    }

    bool Contains(const Queue<T> &queue) const noexcept {
        size_t thisLen = this->GetLength();
        size_t len = queue.GetLength();
        int count = 0;
        if ((thisLen == 0) && (len == 0)) return true;
        if ((thisLen == 0) || (thisLen < len) || (len == 0)) return false;
        for (int i = 0; i < thisLen; i++) {
            T el1 = (*this)[i];
            T el2 = queue[0];
            if (el1 == el2) {
                count++;
                for (int j = 1; j < len; j++) {
                    T el10 = (*this)[i + j];
                    T el20 = queue[j];
                    if (el10 == el20) count++;
                    else break;
                }
                if (count == len) return true;
            }
            count = 0;
        }
        return false;
    }

    int Find(const Queue<T> &queue) const noexcept {
        size_t thisLen = this->GetLength();
        size_t len = queue.GetLength();
        int count = 0;
        if ((thisLen == 0) || (thisLen < len) || (len == 0)) return -1;
        for (int i = 0; i < thisLen; i++) {
            T el1 = (*this)[i];
            T el2 = queue[0];
            if (el1 == el2) {
                count++;
                for (int j = 1; j < len; j++) {
                    T el10 = (*this)[i + j];
                    T el20 = queue[j];
                    if (el10 == el20) count++;
                    else break;
                }
                if (count == len) return i;
            }
            count = 0;
        }
        return -1;
    }

    void Connect(const Queue<T> &addedQueue) noexcept {
        size_t addedLen = addedQueue.GetLength();
        if (addedLen != 0) {
            size_t len = this->GetLength();
            T *items = new T[len + addedLen];
            for (int i = 0; i < len; i++) {
                items[i] = (*sequence)[i];
            }
            for (int i = 0; i < addedLen; i++) {
                items[len + i] = addedQueue[i];
            }
            delete sequence;
            sequence = new ArraySequence(items, len + addedLen);
            delete [] items;
        }
    }

    Queue<T> *Separation(bool (*function)(T)) noexcept {
        size_t len = this->GetLength();
        if (len == 0) {
            Queue<T> *newQueue = new Queue<T>;
            return newQueue;
        }
        size_t count = 0;
        for (int i = 0; i < len; i++) {
            T el = (*sequence)[i];
            if (function(el)) count++;
        }
        if (count == 0) {
            Queue<T> *newQueue = new Queue<T>;
            return newQueue;
        }

        T *items1 = new T[count];
        T *items2 = new T[len - count];
        size_t index1 = 0;
        size_t index2 = 0;
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            if (function(el)) {
                items1[index1] = el;
                index1++;
            } else {
                items2[index2] = el;
                index2++;
            }
        }

        Queue<T> *newQueue = new Queue<T>(items1, count);
        delete sequence;
        sequence = new ArraySequence(items2, len = count);
        delete [] items1;
        delete [] items2;

        return newQueue;
    }

    bool operator==(const Queue<T> &queue) const noexcept {
        size_t thisLen = this->GetLength();
        size_t len = queue.GetLength();
        if (thisLen != len) return false;
        for (int i = 0; i < thisLen; i++) {
            T thisEl = (*this)[i];
            T el = queue[i];
            if (!(thisEl == el)) return false;
        }
        return true;
    }

};

#endif