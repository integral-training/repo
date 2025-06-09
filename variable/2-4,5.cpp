#include <iostream>

int main() {
    /*
    * ポインタ -> 他の変数を参照する仕組み。大きな値（変数）を直接動かすのはパフォーマンスが悪いので、
    * 値の住所を参照に動かせば便利だね、という感じ。
    * 型* ポインタ名; -> 宣言。変数のアドレスを取得するには、&演算子を使う。
    */
    //  unsigned int x = 500000000;
    // unsigned int* ptr = &x;
    // int y = *ptr; // 逆参照（デリファレンス）
    // *ptr = 50; //ポインタからxの値を変える

    //nullptr -> どの変数も参照していないポインタのこと。
    // int* p = nullptr;

    //constポインタ
    //* の前に const を付けると、ポインタを指す値が変更不可になる。
    // int x = 123;
    // const int* p = &x;
    // *p = 456; // エラー

    //* の後に const を付けると、ポインタ自身が変更不可になる。
    // int x = 123;
    // int* const p = &x;
    // p = 456; // エラー

    // //参照 -> ちょっと違うかもしれないポインタ
    // int x = 100;
    // // int* p = &x; // pはポインタ型
    // int& r = x; // rは参照型
    // // *p = 200;
    // // r = 200;
    // //ポインタと参照の違いはなんじゃろな

    //参照とポインタの違い模索中のコード
    int x[5] = {1,2,3,4,5};
    for (int& value : x) { // 参照を使うことで要素を変更可能
        std::cout << (value += 2) << std::endl; // 各要素を+2にする
    }

    for (int* ptr : x) {
        std::cout << (value += 2) << std::endl;
    }

    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    // std::cout << r << std::endl;
    // std::cout << ptr << std::endl;
    // std::cout << "Type of x: " << typeid(x).name() << std::endl; // -> 型確認用
    // std::cout << "Type of ptr: " << typeid(ptr).name() << std::endl; // -> 型確認用
    return 0;
}