#include <iostream>

int main() {
    //c++の変数宣言
    //型　変数　＝　値;

    //const, constexpr -> 定数
    //const int x = 5; -> 再代入でエラー
    //constexpr int x = 5; -> 再代入でエラー
    //const, constexprの違いは？

    //auto -> 型推論
    auto x = 'i';

    std::cout << x << std::endl;
    std::cout << "Type of x: " << typeid(x).name() << std::endl; // -> 型推論確認用
    return 0;
}