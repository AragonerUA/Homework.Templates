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
    std::string m_error;
public:
    explicit ArrayException(std::string error)
            : m_error(std::move(error))
    {}

    const char* getError() {
        return m_error.c_str();
    }
};


template<class T>
class Array {
private:
    int m_length;
    T *m_data;
public:
    Array() {
        m_length = 0;
        m_data = nullptr;
    }

    explicit Array(int length) {
        m_data = new T[length];
        m_length = length;
    }

    ~Array() {
        delete[] m_data;
    }

    void Erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= m_length) {
            throw ArrayException("Invalid Index");
        }
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength();

};

template <class T>
int Array<T>::getLength() {
    return m_length;
}
}
