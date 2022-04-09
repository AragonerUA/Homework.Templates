#include <iostream>
#include <climits>
#include <utility>
#include "second.cpp"
//#include <stdio>
//
#define first_size 5
#define second_size 3
#define third_size 4

int main() {
    int a[first_size] = {10, 20, -3, 60, 1};
    long long int b[second_size] = {10000000000000, 2414141414141412421, 323};
    double k[third_size] = {4.3, 2.1, 8.9, 8.8};

    std::cout << "Maximum: " << tasks::GetMax(a, first_size) << std::endl;
    std::cout << "Maximum: " << tasks::GetMax(b, second_size) << std::endl;
    std::cout << "Maximum: " << tasks::GetMax(k, third_size) << std::endl;

    std::cout << "-----------------------------------------\n";

    //Array
    int intleng = 15;
    int doubleng = 8;
    tasks::Array<int> intArray(intleng);
    tasks::Array<double> doubleArray(doubleng);

    for (int i = 0; i < intArray.takeLen(); i++) {
        intArray[i] = rand() % 100;
    }

    for (int i = 0; i < doubleArray.takeLen(); i++) {
        doubleArray[i] = rand() % 100 + 0.57;
    }

    std::cout << "First Array(Int): \n";
    for (int i = intArray.takeLen()-1; i >= 0; i--) {
        std::cout << intArray[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Second Array(Double): \n";
    for (int i = doubleArray.takeLen()-1; i >= 0; i--) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        intArray[21] = 345;
    }
    catch (tasks::ArrayException &exception) {
        std::cerr << "An array exception occurred (" << exception.takeErr() << ")\n";
    }

    return 0;
}
