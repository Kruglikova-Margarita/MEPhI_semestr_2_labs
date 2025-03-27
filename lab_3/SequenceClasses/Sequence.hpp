#include <iostream>
#include "DinamicArray.hpp"
#include "LinkedList.hpp"
#include "Option.hpp"

#ifndef sequence_h
#define sequence_h

template <class T>
class Sequence {
public:
    virtual ~Sequence() {};
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual Sequence<T> *GetSubSequence(int startIndex, int endIndex) const = 0;
    virtual size_t GetLength() const noexcept = 0;
    virtual void Append(T item) noexcept = 0;
    virtual void Prepend(T item) noexcept = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual void Delete(int index) = 0;
    virtual void Set(int index, T value) = 0;
    virtual Sequence<T> *Concat(const Sequence<T> *addedSequence) const noexcept = 0;
    virtual T operator[](int index) const = 0;
    virtual Sequence<T> *operator+(const Sequence<T> &addedSequence) const noexcept = 0;
    virtual bool operator==(const Sequence<T> &cmpSequence) const noexcept = 0;
    virtual Sequence<T> *Map(T (*function)(T)) const noexcept = 0;
    virtual Sequence<T> *Where(bool (*function)(T)) const noexcept = 0;
    virtual T Reduce(T (*function)(T, T), T c) const = 0;
};


template <class T>
class ArraySequence : public Sequence<T> {
private:
    DinamicArray<T> *sequence;
public:
    ArraySequence(T *items, int count) {
        try {
            sequence = new DinamicArray<T>(items, count);
        }
        catch (...) {
            throw;
        }
    }

    ArraySequence() noexcept : sequence(new DinamicArray<T>) {}

    ArraySequence(ArraySequence<T> &&dinamicArray) noexcept : sequence() {
        std::swap(sequence, dinamicArray.sequence);
    }

    ArraySequence(const Sequence<T> &copy) noexcept {
        size_t len = copy.GetLength();
        if (len == 0) sequence = new DinamicArray<T>;
        else {
            T *items = new T[len];
            for (int i = 0; i < len; i++) {
                items[i] = copy[i];
            }
            sequence = new DinamicArray<T>(items, len);
            delete [] items;
        }
    }

    ~ArraySequence() {
        delete sequence;
    }

    T GetFirst() const override {
        Option<T> first = sequence->GetFirst();
        try {
            return first.Get();
        }
        catch (...) {
            throw;
        }
    }

    T GetLast() const override {
        Option<T> last = sequence->GetLast();
        try {
            return last.Get();
        }
        catch (...) {
            throw;
        }
    }

    T Get(int index) const override {
        Option<T> item = sequence->Get(index);
        try {
            return item.Get();
        }
        catch (...) {
            throw;
        }
    }

    Sequence<T> *GetSubSequence(int startIndex, int endIndex) const override {
        size_t len = sequence->GetLength();
        if ((startIndex < 0) || (startIndex >= len) || (endIndex < 0) || (endIndex >= len)) throw std::out_of_range("Impossible to get subsequence because index is out of range\n");
        if (startIndex > endIndex) throw std::out_of_range("Impossible to get subsequence because start index is more than end index\n");
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = (sequence->Get(i)).Get();
        }
        Sequence<T> *subSequence = new ArraySequence<T>(items, (endIndex - startIndex + 1));
        delete [] items;

        return subSequence;
    }

    size_t GetLength() const noexcept override {
        return sequence->GetLength();
    }

    void Append(T item) noexcept override {
        sequence->Append(item);
    }    

    void Prepend(T item) noexcept override {
        sequence->Prepend(item);
    }

    void InsertAt(T item, int index) override {
        try {
            sequence->InsertAt(item, index);
        }
        catch (...) {
            throw;
        }
    }

    void Delete(int index) override {
        try {
            sequence->Delete(index);
        }
        catch (...) {
            throw;
        }
    }

    void Set(int index, T value) override {
        try {
            sequence->Set(index, value);
        }
        catch(...) {
            throw;
        }
    }

    Sequence<T> *Concat(const Sequence<T> *addedSequence) const noexcept override {
        size_t thisLen = sequence->GetLength();
        size_t addedLen = addedSequence->GetLength();
        if ((thisLen + addedLen) == 0) {
            Sequence<T> *concatSequence = new ArraySequence<T>;
            return concatSequence;
        }
        T *items = new T[thisLen + addedLen];
        for (int i = 0; i < thisLen; i++) {
            items[i] = (sequence->Get(i)).Get();
        }
        for (int i = 0; i < addedLen; i++) {
            items[i + thisLen] = addedSequence->Get(i);
        }
        Sequence<T> *concatSequence = new ArraySequence<T>(items, thisLen + addedLen);
        delete [] items;

        return concatSequence;
    }

    T operator[](int index) const override {
        try {
            return this->Get(index);
        }
        catch(...) {
            throw;
        }
    }

    Sequence<T> *operator+(const Sequence<T> &addedSequence) const noexcept override {
        Sequence<T> *newSequence = this->Concat(&addedSequence);
        return newSequence;
    }

    bool operator==(const Sequence<T> &cmpSequence) const noexcept override {
        size_t len1 = this->GetLength();
        size_t len2 = cmpSequence.GetLength();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++) {
            T item1 = (*this)[i];
            T item2 = cmpSequence[i];
            if (!(item1 == item2)) return false;
        }
        return true;
    }

    Sequence<T> *Map(T (*function)(T)) const noexcept override {
        size_t len = this->GetLength();
        if (len == 0) {
            Sequence<T> *mapSequence = new ArraySequence<T>;
            return mapSequence;
        }
        T *items = new T[len];
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            items[i] = function(el);
        }
        Sequence<T> *mapSequence = new ArraySequence<T>(items, len);
        delete [] items;
        return mapSequence;
    }

    Sequence<T> *Where(bool (*function)(T)) const noexcept override {
        size_t len = this->GetLength();
        if (len == 0) {
            Sequence<T> *whereSequence = new ArraySequence<T>;
            return whereSequence;
        }
        size_t count = 0;
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            if (function(el)) count++;
        }
        if (count == 0) {
            Sequence<T> *whereSequence = new ArraySequence<T>;
            return whereSequence;
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
        Sequence<T> *whereSequence = new ArraySequence<T>(items, count);
        delete [] items;
        return whereSequence;
    }

    T Reduce(T (*function)(T, T), T c) const override {
        size_t len = this->GetLength();
        if (len == 0) throw std::out_of_range("Impossible to reduce\n");
        T result = c;
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            result = function(el, result);
        }
        return result;
    }
};


template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> *sequence;

public:
    LinkedListSequence(const T *items, int count) {
        try {
            sequence = new LinkedList<T>(items, count);
        }
        catch (...) {
            throw;
        }
    }

    LinkedListSequence() noexcept : sequence(new LinkedList<T>) {}

    LinkedListSequence(LinkedListSequence<T> &&list) noexcept : sequence() {
        std::swap(sequence, list.sequence);
    }

    LinkedListSequence(const Sequence<T> &copy) noexcept {
        size_t len = copy.GetLength();
        if (len == 0) sequence = new LinkedList<T>;
        else {
            T *items = new T[len];
            for (int i = 0; i < len; i++) {
                items[i] = copy[i];
            }
            sequence = new LinkedList<T>(items, len);
            delete [] items;
        }
    }

    ~LinkedListSequence() {
        delete sequence;
    }

    T GetFirst() const override {
        try {
            return sequence->GetFirst();
        }
        catch (...) {
            throw;
        }
    }

    T GetLast() const override {
        try {
            return sequence->GetLast();
        }
        catch (...) {
            throw;
        }
    }

    T Get(int index) const override {
        try {
            return sequence->Get(index);
        }
        catch (...) {
            throw;
        }
    }

    Sequence<T> *GetSubSequence(int startIndex, int endIndex) const override {
        size_t len = sequence->GetLength();
        if ((startIndex < 0) || (startIndex >= len) || (endIndex < 0) || (endIndex >= len)) throw std::out_of_range("Impossible to get subsequence because index is out of range\n");
        if (startIndex > endIndex) throw std::out_of_range("Impossible to get subsequence because start index is more than end index\n");
        T *items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            items[i - startIndex] = sequence->Get(i);
        }
        Sequence<T> *subSequence = new LinkedListSequence<T>(items, (endIndex - startIndex + 1));
        delete [] items;

        return subSequence;
    }

    size_t GetLength() const noexcept override {
        return sequence->GetLength();
    }

    void Append(T item) noexcept override {
        sequence->Append(item);
    }

    void Prepend(T item) noexcept override {
        sequence->Prepend(item);
    }

    void InsertAt(T item, int index) override {
        try {
            sequence->InsertAt(item, index);
        }
        catch (...) {
            throw;
        }
    }

    void Delete(int index) override {
        try {
            sequence->Delete(index);
        }
        catch (...) {
            throw;
        }
    }

    void Set(int index, T value) override {
        try {
            sequence->Set(index, value);
        }
        catch(...) {
            throw;
        }
    }

    Sequence<T> *Concat(const Sequence<T> *addedSequence) const noexcept override {
        size_t thisLen = sequence->GetLength();
        size_t addedLen = addedSequence->GetLength();
        if ((thisLen + addedLen) == 0) {
            Sequence<T> *concatSequence = new LinkedListSequence<T>;
            return concatSequence;
        }
        T *items = new T[thisLen + addedLen];
        for (int i = 0; i < thisLen; i++) {
            items[i] = sequence->Get(i);
        }
        for (int i = 0; i < addedLen; i++) {
            items[i + thisLen] = addedSequence->Get(i);
        }
        Sequence<T> *concatSequence = new LinkedListSequence<T>(items, thisLen + addedLen);
        delete [] items;

        return concatSequence;
    }

    T operator[](int index) const override {
        try {
            return this->Get(index);
        }
        catch (...) {
            throw;
        }
    }

    Sequence<T> *operator+(const Sequence<T> &addedSequence) const noexcept override {
        Sequence<T> *newSequence = this->Concat(&addedSequence);
        return newSequence;
    }

    bool operator==(const Sequence<T> &cmpSequence) const noexcept override {
        size_t len1 = this->GetLength();
        size_t len2 = cmpSequence.GetLength();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++) {
            T item1 = (*this)[i];
            T item2 = cmpSequence[i];
            if (item1 != item2) return false;
        }
        return true;
    }

    Sequence<T> *Map(T (*function)(T)) const noexcept override {
        size_t len = this->GetLength();
        if (len == 0) {
            Sequence<T> *mapSequence = new LinkedListSequence<T>;
            return mapSequence;
        }
        T *items = new T[len];
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            items[i] = function(el);
        }
        Sequence<T> *mapSequence = new LinkedListSequence<T>(items, len);
        delete [] items;
        return mapSequence;
    }

    Sequence<T> *Where(bool (*function)(T)) const noexcept override {
        size_t len = this->GetLength();
        if (len == 0) {
            Sequence<T> *whereSequence = new LinkedListSequence<T>;
            return whereSequence;
        }
        size_t count = 0;
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            if (function(el)) count++;
        }
        if (count == 0) {
            Sequence<T> *whereSequence = new ArraySequence<T>;
            return whereSequence;
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
        Sequence<T> *whereSequence = new LinkedListSequence<T>(items, count);
        delete [] items;
        return whereSequence;
    }

    T Reduce(T (*function)(T, T), T c) const override {
        size_t len = this->GetLength();
        if (len == 0) throw std::out_of_range("Impossible to reduce\n");
        T result = c;
        for (int i = 0; i < len; i++) {
            T el = (*this)[i];
            result = function(el, result);
        }
        return result;
    }
};

#endif