#include <iostream>
#include <climits>
#include <utility>
#include "second.cpp"
//#include <stdio>
//
#define Na 5
#define Nb 3
#define Nk 4

int main() {
    int a[Na] = {10, 20, -3, 60, 1};
    long long int b[Nb] = {10000000000000, 2414141414141412421, 323};
    double k[Nk] = {4.3, 2.1, 8.9, 8.8};

    std::cout << "Maximum: " << tasks::GetMax(a, Na) << std::endl;
    std::cout << "Maximum: " << tasks::GetMax(b, Nb) << std::endl;
    std::cout << "Maximum: " << tasks::GetMax(k, Nk) << std::endl;

    std::cout << "-----------------------------------------\n";

    //Array
    int intleng = 15;
    int doubleng = 8;
    tasks::Array<int> intArray(intleng);
    tasks::Array<double> doubleArray(doubleng);

    for (int i = 0; i < intArray.getLength(); i++) {
        intArray[i] = rand() % 100;
    }

    for (int i = 0; i < doubleArray.getLength(); i++) {
        doubleArray[i] = rand() % 100 + 0.57;
    }

    std::cout << "First Array(Int): \n";
    for (int i = intArray.getLength()-1; i >= 0; i--) {
        std::cout << intArray[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Second Array(Double): \n";
    for (int i = doubleArray.getLength()-1; i >= 0; i--) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        intArray[21] = 345;
    }
    catch (tasks::ArrayException &exception) {
        std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
    }

    return 0;
}
