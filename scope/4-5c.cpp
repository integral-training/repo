#include <iostream>
#include "4-5b.cpp"

inline void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

inline void HelloNewWorld() {
    std::cout << "Hello new World!" << std::endl;
}

void Something1() {
    HelloWorld();
}

void Something2() {
    HelloNewWorld();
}