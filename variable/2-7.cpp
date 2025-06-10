#include <iostream>

int main() {
    // ゼロ除算はエラー
    // int div = 100 / 0; // 実行時エラー
    // int mod = 100 % 0; // 実行時エラー

    // 演算の対象となるいずれかの値が double ( float )の場合、
    // 他方の値も double ( float ) として変換された上で演算が行われます。
    int ix = 100;
    int iy = 50;
    double dx = 100.0;
    double dy = 50.0;
    
    auto a = ix / iy;  // int = int / int
    auto b = ix / dy;  // double = double(intから変換) / double
    auto c = dx / iy;  // double = double / double(intから変換)
    auto d = dx / dy;  // double = double / double

    std::cout << a << std::endl;
    std::cout << "Type of a: " << typeid(a).name() << std::endl; // -> 型確認用
    std::cout << b << std::endl;
    std::cout << "Type of b: " << typeid(b).name() << std::endl; // -> 型確認用
    std::cout << c << std::endl;
    std::cout << "Type of c: " << typeid(c).name() << std::endl; // -> 型確認用
    std::cout << d << std::endl;
    std::cout << "Type of d: " << typeid(d).name() << std::endl; // -> 型確認用

    //ビットの計算
    //~x      // 否定
    // // x << y  // 左シフト
    // // x >> b  // 右シフト
    // // x & y   // 論理積
    // // x | y   // 論理和
    // // x ^ y   // 排他的論理和

    // std::bitset を使うことで、ビット列(2進数)での表記が確認できます。
    // #include <bitset>
    // #include <iostream>
    
    // auto bits_a = std::bitset<8>("00001111");  // 15を8ビットで表す: 00001111
    // std::cout << ~bits_a << std::endl;         // 否定: 11110000
    // std::cout << (bits_a << 2) << std::endl;   // 左に2シフト: 00111100
    // std::cout << (bits_a >> 2) << std::endl;   // 右に2シフト: 00000011
    
    // auto bits_b = std::bitset<8>("00111100");     // 60を8ビットで表す: 00111100
    // std::cout << (bits_a & bits_b) << std::endl;  // 論理積: 00001100
    // std::cout << (bits_a | bits_b) << std::endl;  // 論理和: 00111111
    // std::cout << (bits_a ^ bits_b) << std::endl;  // 排他的論理和: 00110011

    // int b = 10 + 20 * 4;
    // b /= 5; 

    // std::cout << b << std::endl;
    // std::cout << "Type of b: " << typeid(b).name() << std::endl; // -> 型推論確認用
    return 0;
}