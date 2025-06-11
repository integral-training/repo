#include <iostream>
#include "4-5b.cpp"

inline void HelloWorld();

int main(){
    HelloWorld();
    Something1();
    Something2();
    
    
    return 0;
}

inline void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}