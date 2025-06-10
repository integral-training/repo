#include <iostream>

int main() {
    //リテラルとは、プログラム中で直接記述される固定値のこと。変数や定数に代入される値そのもの。

    // 数字の先頭に文字を加えることで整数の基数を変える。
    // int x = 26;  // 10進整数リテラル
    int x = 032;  // 先頭に0を付けると8進整数リテラル
    // int x = 0x1a; // 先頭に0xを付けると16進整数リテラル
    // int x = 0x1A; // 16進整数リテラル内の文字は小文字でも大文字でも区別されないので0x1aと同じ

    // 数字の末尾に文字を加えて型を表現できる。
    int y =26u;    // unsigned型の26
    // int x =26l;    // long型の26
    int z =26ul;   // unsigned long型の26
    // int x =0x1Aul; // unsigned long型の0x1A

    std::cout << x << std::endl;
    std::cout << "Type of x: " << typeid(x).name() << std::endl; // -> 型確認用
    std::cout << y << std::endl;
    std::cout << "Type of y: " << typeid(y).name() << std::endl; // -> 型確認用
    std::cout << z << std::endl;
    std::cout << "Type of z: " << typeid(z).name() << std::endl; // -> 型確認用
    return 0;
}