#include <iostream>
#include "7-10.h"

int StaticMem::count = 10; // クラスの外で実体を定義

void StaticMem::increment() {
    ++count;
}

void StaticMem::print() {
    std::cout << count << std::endl;
}