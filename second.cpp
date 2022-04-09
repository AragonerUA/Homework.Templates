#include <iostream>
#include <climits>
#include <utility>
//#include <stdio>

namespace tasks {
template<class Type>
Type GetMax(Type* a, int size){
    Type maximum = a[0];
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


template<int length, class T>
class Array {
private:
    T *data;
public:
    Array() {
        data = new T[length];
    }

    void fill_arr() {
        for (int i = 0; i < length; i++) {
            data[i] = T(rand() % 100 + 0.63);
        }
    }

    void print() {
        std::cout << "Array: " << std::endl;
        for (int i = length-1; i >= 0; i--) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    ~Array() {
        delete[] data;
    }

    void Erase() {
        delete[] data;
        data = nullptr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length) {
            throw ArrayException("Invalid Index");
        }
        assert(index >= 0 && index < length);
        return data[index];
    }

    int takeLen() {
        return length;
    };

};

}
