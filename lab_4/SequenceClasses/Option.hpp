#include <iostream>

#ifndef option_h
#define option_h

template <class T>
class Option {
private:
    inline static Option none;
    inline static bool isNoneSet = false;
    T value;
    bool hasValue;

public:
    static const Option& GetNone() {
        if (!isNoneSet) {
            Option::none = Option();
            Option::isNoneSet = true;
        }
        return Option::none;
    }

    Option() {
        hasValue = false;
    }

    Option(T data) {
        value = data;
        hasValue = true;
    }

    Option(const Option &item) {
        if (item.hasValue) {
            value = item.value;
            hasValue = true;
        } else hasValue = false;
    }

    bool HasValue() const {
        return hasValue;
    }

    T Get() const {
        if (!hasValue) throw std::out_of_range("The value is not set\n"); 
        return value;
    }
};

#endif