#include <iostream>

int main() {
    /*
    * ポインタ -> 他の変数を参照する仕組み。大きな値（変数）を直接動かすのはパフォーマンスが悪いので、
    * 値の住所を参照に動かせば便利だね、という感じ。
    * 型* ポインタ名; -> 宣言。変数のアドレスを取得するには、&演算子を使う。
    */
    // unsigned int x = 500000000;
    // unsigned int* ptr = &x;
    // int y = *ptr; // 逆参照（デリファレンス）
    // *ptr = 50; //ポインタからxの値を変える
    // std::cout << y << std::endl;
    // std::cout << "Type of y: " << typeid(y).name() << std::endl; // -> 型確認用
    // std::cout << *ptr << std::endl;
    // std::cout << "Type of ptr: " << typeid(*ptr).name() << std::endl; // -> 型確認用

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
    // int x[5] = {1,2,3,4,5};
    // for (int& value : x) { // 参照を使うことで要素を変更可能
    //     std::cout << (value += 2) << std::endl; // 各要素を+2にする
    // }

    // for (int* ptr : x) {
    //     std::cout << (value += 2) << std::endl;
    // }

    //代入とポインタと参照の違い
    int xx = 100;
    int* p = &xx; // pはポインタ型

    int& r1 = xx; // r1は参照型
    int  r2 = xx; // r2は代入
    std::cout << "1:" << xx << std::endl;
    r1 = r1 + 1;
    std::cout << "2:" << xx << std::endl;
    r2 = r2 + 10;
    std::cout << "3:" << xx << std::endl;

    // 値を表示
    std::cout << "value xx:" << xx << std::endl; // 100
    std::cout << "value r1:" << r1 << std::endl; // 101
    std::cout << "value r2:" << r2 << std::endl; // 100
    std::cout << "value p:" << p << std::endl;   // 100
    std::cout << "value p:" << *p << std::endl;   // 100
    std::cout << "add p:" << &p << std::endl;   // 100

    // value xx:101
    // value r1:101
    // value r2:110
    // value p:0x7fff8a947ca8

    // アドレスを表示
    std::cout << "addr xx:" << &xx << std::endl;
    std::cout << "addr r1:" << &r1 << std::endl;
    std::cout << "addr r2:" << &r2 << std::endl;













    int a = 10;

    int* b = &a;
    int& c = a;
    int aa = a;
    std::cout << b << std::endl; 
    std::cout << c << std::endl;
    std::cout << aa << std::endl;
    std::cout << &a << std::endl;　//　　　　　ベースの住所
    std::cout << &b << std::endl;　//ポインタ本体は違う住所
    std::cout << c << std::endl;　//　　　　参照は同じ住所
    std::cout << &aa << std::endl; //　　　　代入は違う住所

    b += 10;
    std::cout << a << std::endl; 
    c += 10;
    std::cout << a << std::endl; 
    aa += 10;
    std::cout << a << std::endl; 

    return 0;
}