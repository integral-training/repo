#include <iostream>

// extern "C" を使うのは、C++の名前修飾（name mangling）を防ぎ、dlsym() で正しく関数名を解決するためです。
extern "C" void hello() 
{
    std::cout << "Hello from shared library!" << std::endl;
}
