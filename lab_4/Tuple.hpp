#ifndef tuple_h
#define tuple_h

template <class T1, class T2>
class Tuple {
private:
    T1 item1;
    T2 item2;

public:
    Tuple() {}

    Tuple(T1 value1, T2 value2) {
        item1 = value1;
        item2 = value2;
    }

    T1 GetItem1() const noexcept {
        return item1;
    }

    T2 GetItem2() const noexcept {
        return item2;
    }

    bool operator==(const Tuple<T1, T2> &tuple) {
        if ((item1 == tuple.GetItem1()) && (item2 == tuple.GetItem2())) return true;
        return false;
    }
};

#endif