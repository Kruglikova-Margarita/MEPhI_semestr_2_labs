#include <iostream>
#include <math.h>
#include "../SequenceClasses/Sequence.hpp"
#include "Matrix.hpp"

#ifndef polynomial_h
#define polynomial_h

using namespace std;

template <class T>
concept StoredTypesPolynomial = same_as<T, int> || same_as<T, float> || same_as<T, complex<float>> || same_as<T, Matrix<float>>;

template <StoredTypesPolynomial T>
class Polynomial {
private:
    Sequence<T> *coefficients;

public:
    Polynomial(T *items, int count) {
        try {
            coefficients = new ArraySequence<T>(items, count);
        }
        catch (...) {
            throw;
        }
    }

    Polynomial(Polynomial<T> &&pol) noexcept : coefficients() {
        std::swap(coefficients, pol.coefficients);
    }

    Polynomial(const Polynomial<T> &pol) {
        coefficients = new ArraySequence<T>(*(pol.coefficients));
    }

    Polynomial() noexcept {
        coefficients = new ArraySequence<T>;
    }

    ~Polynomial() {
        delete coefficients;
    }

    size_t GetDegree() const noexcept {
        size_t len = coefficients->GetLength();
        return len - 1;
    }

    T GetCoefficient(int index) const {
        T k;
        try {
            k = coefficients->Get(index);
        }
        catch(...) {
            throw;
        }
        return k;
    }

    T GetValue(T x) const {
        size_t deg = this->GetDegree();
        if (deg == -1) throw std::out_of_range("Impossible to find value of empty polynomial\n");
        T result = this->GetCoefficient(0);
        for (int i = 1; i <= deg; i++) {
            T n = this->GetCoefficient(i);
            T mult = x;
            for (int j = 1; j < i; j++) {
                try {
                    mult = mult * x;
                }
                catch (...) {
                    throw;
                }
            }
            try {
                mult = n * mult;
                result = result + mult;
            }
            catch (...) {
                throw;
            }
        }
        return result;
    }

    T operator()(T x) const {
        T result;
        try {
            result = this->GetValue(x);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    Polynomial<T> *Sum(const Polynomial<T> &pol) const {
        size_t thisDeg = this->GetDegree();
        size_t deg = pol.GetDegree();
        if ((thisDeg == -1) || (deg == -1)) throw std::out_of_range("Impossible to sum empty polynomial\n"); 
        T *items;
        size_t newDeg;
        if (thisDeg > deg) {
            items = new T[thisDeg + 1];
            newDeg = thisDeg;
            for (int i = 0; i <= deg; i++) {
                try {
                    items[i] = pol.GetCoefficient(i) + (*coefficients)[i];
                }
                catch(...) {
                    throw;
                }
            }
            for (int i = deg + 1; i <= thisDeg; i++) {
                try {
                    items[i] = (*coefficients)[i];
                }
                catch (...) {
                    throw;
                }
            }
        } else {
            items = new T[deg + 1];
            newDeg = deg;
            for (int i = 0; i <= thisDeg; i++) {
                try {
                    items[i] = pol.GetCoefficient(i) + (*coefficients)[i];
                }
                catch (...) {
                    throw;
                }
            }
            for (int i = thisDeg + 1; i <= deg; i++) {
                items[i] = pol.GetCoefficient(i);
            }
        }
        Polynomial<T> *result = new Polynomial<T>(items, newDeg + 1);
        delete [] items;
        return result;
    }

    Polynomial<T> *operator+(const Polynomial<T> &pol) const {
        Polynomial<T> *result;
        try {
            result = this->Sum(pol);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    Polynomial<T> *Mult(const Polynomial<T> &pol) const {
        size_t thisDeg = this->GetDegree();
        size_t deg = pol.GetDegree();
        if ((thisDeg == -1) || (deg == -1)) throw std::out_of_range("Impossible to multiply empty polynomial\n");
        size_t newDeg = thisDeg + deg;
        T *items = new T[newDeg + 1];
        float neg = -1.0;
        T zero;
        try {
            zero = pol.GetCoefficient(0) * neg + pol.GetCoefficient(0);
        }
        catch (...) {
            throw;
        }
        for (int i = 0; i <= newDeg; i++) {
            items[i] = zero;
        }
        for (int i = 0; i <= thisDeg; i++) {
            for (int j = 0; j <= deg; j++) {
                try {
                    items[i + j] = items[i + j] + (this->GetCoefficient(i)) * (pol.GetCoefficient(j));
                }
                catch (...) {
                    throw;
                }
            }
        }
        Polynomial<T> *result = new Polynomial<T>(items, newDeg + 1);
        delete [] items;
        return result;
    }

    Polynomial<T> *operator*(const Polynomial<T> &pol) const {
        Polynomial<T> *result;
        try {
            result = this->Mult(pol);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    Polynomial<T> *MultOnScalar(T k) const {
        size_t deg = this->GetDegree();
        if (deg == -1) throw std::out_of_range("Impossible to multiply empty polynomial\n");
        T *items = new T[deg + 1];
        for (int i = 0; i <= deg; i++) {
            T ki = this->GetCoefficient(i);
            try {
                items[i] = k * ki;
            }
            catch (...) {
                throw;
            }
        }
        Polynomial<T> *result = new Polynomial<T>(items, deg + 1);
        delete [] items;
        return result;
    }

    Polynomial<T> *operator*(T k) const {
        Polynomial<T> *result;
        try {
            result = this->MultOnScalar(k);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    T Composition(const Polynomial<T> &pol, T x) const {
        T value;
        T result;
        try {
            value = pol.GetValue(x);
        } catch (...) {
            throw;
        }

        try {
            result = this->GetValue(value);
        }
        catch (...) {
            throw;
        }
        return result;
    }

    Polynomial<T> *Composition(const Polynomial<T> &pol) const {
        size_t thisDeg = this->GetDegree();
        size_t deg = pol.GetDegree();
        if ((thisDeg == -1) || (deg == -1)) throw std::out_of_range("Impossible to find composition of empty polynomials\n");
        T a0 = this->GetCoefficient(0);
        Polynomial<T> *p1 = new Polynomial<T>(&a0, 1);
        Polynomial<T> *sum = new Polynomial<T>(*p1);
        Polynomial<T> *add;
        Polynomial<T> *p2;
        Polynomial<T> *p3;
        for (int i = 1; i <= thisDeg; i++) {
            p2 = new Polynomial<T>(pol);
            p3 = new Polynomial<T>(pol);
            for (int j = 1; j < i; j++) {
                delete p3;
                try {
                    p3 = (*p2) * pol;
                }
                catch (...) {
                    throw;
                }
                delete p2;
                p2 = new Polynomial<T>(*p3);
            }
            T a = this->GetCoefficient(i);
            try {
                add = (*p3) * a;
            }
            catch (...) {
                throw;
            }
            delete sum;
            try {
                sum = (*p1) + (*add);
            }
            catch (...) {
                throw;
            }
            delete p1;
            p1 = new Polynomial<T>(*sum);
            delete add;
            delete p2;
            delete p3;
        }
        delete p1;
        return sum;

    }

    bool operator==(const Polynomial<T> &pol) const noexcept {
        return ((*coefficients) == (*(pol.coefficients)));
    }

};

#endif