#include <iostream>

// 途中

// テンプレートとは、型やコンパイル時に定まる値をパラメータ化する機能
// 型に依存せず処理を共通化できる
// etc...配列などコンパイル時に決まる値もパラメータ化できる

template <typename T>
T Sum(T a, T b) {
    // int double どちらも指定された型で動かせる
    return a + b;
}

// 後者の引数がintならint型クラスSubに、引数がdoubleならdouble型クラスSubになる
template <typename T, typename U>
U BackSum(T a, U b) {
    return a + b;
}

// パラメータ化した引数の型から推論するには
// auto 関数(A a, B b) -> decltype(a + b) を使う。
template <typename T, typename U>
auto AutoSum(T a, U b) -> decltype(a + b) {
    return a + b;
}

int main(){
    std::cout << Sum<int>(1, 2) << std::endl;         // 3
    std::cout << Sum<double>(12, 3.4) << std::endl;  // 15.4
    // 関数呼び出し時に < ... > で T の型を指定する。

    std::cout << Sum(1, 2) << std::endl;         // 3
    std::cout << Sum(1.2, 3.4) << std::endl;  // 4.6
    // 実引数から型パラメータ T を推論できる場合には型指定を省略できる。
    // std::cout << Sum(12, 3.4) << std::endl;  // 推論が出来ずエラー

    std::cout << BackSum(12, 3.4) << std::endl;
    // 複数のテンプレート引数持ちに値を渡すとエラーにならない

    std::cout << AutoSum(12.5, 34.5) << std::endl; // decltypeに
    std::cout << AutoSum(33.4, 56) << std::endl; // decltypeに

    return 0;
}