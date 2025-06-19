#include <iostream>
#include <exception>

// シグナルとは、プログラム実行中に外部からの要求を通知する仕組み。例：OSのエラー通知

class A // SIGFPE。Floating point exception
{
    public:
    int x = 2;
    int y = 0;
    int* w = nullptr;

    void Sum() 
    {
        int z = x / y;  // 整数の0除算
        std::cout << *w << std::endl; // SIGSEGV。無効なメモリアクセス (セグメンテーション違反) で発生
    }
};

int main() 
{
    A a;

    // SIGABRT
    // 例外が捕捉されないため std::terminate が呼び出される
    // throw std::exception();

    a.Sum(); // SIGFPE

    return 0;
}