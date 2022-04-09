#include <iostream>
#include <climits>
#include <utility>
//#include <stdio>

namespace tasks {
template<class Type>
Type GetMax(Type* a, int size){
    Type maximum = LLONG_MIN;
    for (int i = 0; i < size; i++) {
        if (a[i] > maximum) {
            maximum = a[i];
        }
    }
    return maximum;
}


class ArrayException {
private:
    std::string exception_error;
public:
    explicit ArrayException(std::string error)
            : exception_error(std::move(error))
    {}

    const char* takeErr() {
        return exception_error.c_str();
    }
};


template<class T>
class Array {
private:
    int length;
    T *data;
public:
    Array() {
        length = 0;
        data = nullptr;
    }

    explicit Array(int lengths) {
        data = new T[length];
        length = lengths;
    }

    ~Array() {
        delete[] data;
    }

    void Erase() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length) {
            throw ArrayException("Invalid Index");
        }
        assert(index >= 0 && index < length);
        return data[index];
    }

    int takeLen();

};

template <class T>
int Array<T>::takeLen() {
    return length;
}
}
