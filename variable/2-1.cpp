#include <iostream>

int main() {
    //c++の変数宣言
    //型　変数　＝　値;
    int x = 10;

    //const, constexpr -> 定数
    const int a = 5; // 実行時に定数化
    // a = 10; // 再代入でエラー
    constexpr int b = 5; // コンパイル時に定数化
    // b = 15; // 再代入でエラー
    // //const, constexprの違いは？

    //auto -> 型推論
    auto y = 'i';

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << "Type of x: " << typeid(x).name() << std::endl; // -> 型推論確認用
    std::cout << "Type of y: " << typeid(y).name() << std::endl; // -> 型推論確認用
    return 0;
}