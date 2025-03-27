#include <iostream>
#include "Option.hpp"

#ifndef dinamicArray_h
#define dinamicArray_h

template <class T>
class DinamicArray {
private:
    size_t len;
    Option<T> *array;
public:
    DinamicArray(const T *items, int count) {
        if (count < 0) throw std::out_of_range("Invalid length of sequence\n");
        len = count;
        if (len == 0) array = NULL;
        else {
            array = new Option<T>[count];
            for (int i = 0; i < count; i++) {
                array[i] = Option<T>(items[i]);
            }
        }
    }

    DinamicArray() noexcept : len(0), array() {}

    DinamicArray(int newLen) {
        if (newLen < 0) throw std::out_of_range("Invalid length of sequence\n");
        len = newLen;
        if (len == 0) array = NULL;
        else {
            array = new Option<T>[len];
            for (int i = 0; i < len; i++) {
                array[i] = Option<T>::GetNone();
            }
        }
    }

    DinamicArray(DinamicArray <T> &&dinamicArray) noexcept : array() {
        std::swap(array, dinamicArray.array);
        std::swap(len, dinamicArray.len);
    }

    ~DinamicArray() {
        if (len != 0) delete [] array;
    }

    Option<T> GetFirst() const {
        if (len == 0) throw std::out_of_range("The sequence is empty\n");
        return array[0];
    }

    Option<T> GetLast() const {
        if (len == 0) throw std::out_of_range("The sequence is empty\n");
        return array[len - 1];
    }

    Option<T> Get(int index) const {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        return array[index];
    }

    size_t GetLength() const noexcept {
        return len;
    }

    void Append(T item) noexcept {
        if (len == 0) {
            array = new Option<T>[1];
            array[0] = Option<T>(item);
        }
        else {
            Option<T> *copyArray = new Option<T>[len];
            for (int i = 0; i < len; i++) {
                copyArray[i] = Option<T>(array[i]);
            }
            delete [] array;
            array = new Option<T>[len + 1];
            for (int i = 0; i < len; i++) {
                array[i] = copyArray[i];
            }
            array[len] = Option<T>(item);
            delete [] copyArray;
        }
        len++;
    }

    void Prepend(T item) noexcept {
        if (len == 0) {
            array = new Option<T>[1];
            array[0] = Option<T>(item);
        }
        else {
            Option<T> *copyArray = new Option<T>[len];
            for (int i = 0; i < len; i++) {
                copyArray[i] = Option(array[i]);
            }
            delete [] array;
            array = new Option<T>[len + 1];
            array[0] = Option(item);
            for (int i = 1; i <= len; i++) {
                array[i] = copyArray[i - 1];
            }
            delete [] copyArray;
        }
        len++;
    }

    void InsertAt(T item, int index) {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        Option<T> *copyArray = new Option<T>[len];
        for (int i = 0; i < len; i++) {
            copyArray[i] = Option<T>(array[i]);
        }
        delete [] array;
        len++;
        array = new Option<T>[len];
        for (int i = 0; i < index; i++) {
            array[i] = Option<T>(copyArray[i]);
        }
        array[index] = Option<T>(item);
        for (int i = index + 1; i < len; i++) {
            array[i] = Option<T>(copyArray[i - 1]);
        }
        delete [] copyArray;
    }

    void Delete(int index) {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        if (len == 1) {
            delete [] array;
            len--;
        } else {
            Option<T> *copyArray = new Option<T>[len];
            for (int i = 0; i < len; i++) {
                copyArray[i] = Option<T>(array[i]);
            }
            delete [] array;
            len--;
            array = new Option<T>[len];
            for (int i = 0; i < index; i++) {
                array[i] = Option<T>(copyArray[i]);
            }
            for (int i = index; i < len; i++) {
                array[i] = Option<T>(copyArray[i + 1]);
            }
            delete [] copyArray;
        }
    }

    void Set(int index, T value) {
        if ((index < 0) || (index >= len)) throw std::out_of_range("Index is out of range\n");
        array[index] = Option<T>(value);
    }

    void Resize(size_t newLen) {
        if (newLen < 0) throw std::out_of_range("Invalid length of sequence\n");
        if (newLen != len) {
            if (newLen == 0) {
                len = 0;
                delete [] array;
                array = NULL;
            } else {
                Option<T> *copyArray = new Option<T>[len];
                for (int i = 0; i < len; i++) {
                    copyArray[i] = Option<T>(array[i]);
                }
                delete [] array;
                array = new Option<T>[newLen];
                for (int i = 0; i < std::min(len, newLen); i++) {
                    array[i] = Option<T>(copyArray[i]);
                }
                for (int i = std::min(len, newLen); i < newLen; i++) {
                    array[i] = Option<T>::GetNone();
                }
                len = newLen;
                delete [] copyArray;
            }
        }
    }
};

#endif