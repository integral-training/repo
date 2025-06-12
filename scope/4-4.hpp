#include <iostream>
#include "4-4.h"

namespace {
    int xx = 20;
    int yy = 20;
}

void Print() {
    xx += yy;
    std::cout << xx << std::endl;  // ここから xx は参照可能
}