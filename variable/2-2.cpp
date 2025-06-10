#include <iostream>

int main() {
    //bool型　->　真偽値
    bool x = true;
    //bool y = false;

    if( x == false){
        std::cout << "false" << std::endl;
    }else{
        std::cout << "true" << std::endl;
    }



    //char型 -> ''で一文字を扱う。小さな文字や値を扱うのに適している
    //char x = 'w';

    //整数型　char 8b < short 16b < int 32b < long 64b
    //浮動小数点型　float 32b < double 64b 

    //unsigned 型 変数 ; -> 正の値の大きい値が表現できる。
    //signed 型 変数 ; -> 正負の値の大きい値が表現できる。デフォルト
    //int x = 4000000000; //-294967296が出力
    //signed int y = 4000000000; //-294967296が出力
    //unsigned int z = 4000000000; //4000000000が出力

    //char, signed char, unsigned char はそれぞれ別物と考えること
    // char x = 'q';          //Type of x: c
    // signed char y = 'q';   //Type of y: a
    // unsigned char z = 'q'; //Type of z: h

    //std::int(bitサイズ)_t　-> サイズ指定付き整数型。 複数のコンパイラに対応させて移植性を向上させたいなら。
    //サイズ指定付き整数型を使用する場合は #include <cstdint> と記述する必要がある。
    //int -> signed , unit ->  unsigned
    // #include <cstdint>
    std::int16_t xx = 5; //typeid　⇒　Type of x: s
    std::int32_t yy = 15; //typeid　⇒　Type of x: i
    std::int64_t zz = 50; //typeid　⇒　Type of x: i
    std::cout << "Type of xx: " << typeid(xx).name() << std::endl; // -> 型確認用
    std::cout << "Type of yy: " << typeid(yy).name() << std::endl; // -> 型確認用
    std::cout << "Type of zz: " << typeid(zz).name() << std::endl; // -> 型確認用

    //enum 列挙型名{定数...}　-> 名前を付けた定数の集合を扱う。値を指定しなければ、１ずつ順に割り振られる。
    //定数をまとめて管理するから可読性が向上するとか。
    enum Collar {
        Red,  // 0
        Blue,  // 1
        Yellow,  // 2
        White = 3,  
        Black,  // 4
    };
    // Collar collar = Black;
    // int x = Yellow;  
    // Collar collar = 5;  // コンパイルエラー

    //enum class 列挙型名{定数...} -> enumとほぼ同じ。違う点は代入の仕方。
    //enum class を扱うには 型名::列挙子名 とします。
    // Day day = Day::Fri;  // OK
    // Day day = Fri;       // コンパイルエラー
    //int x = static_cast<int>(Day::Fri); -> 明示的型変換で数値型に代入可能

    //enum -> 定数の名前は被り問題あり　, enum class -> 定数の名前は被り問題なし


    // std::cout << x << std::endl;
    // std::cout << collar << std::endl;
    // // std::cout << y << std::endl;
    // std::cout << "Type of x: " << typeid(x).name() << std::endl; // -> 型確認用
    // std::cout << "Type of y: " << typeid(y).name() << std::endl; // -> 型確認用

    // std::cout << z << std::endl;
    // std::cout << "Type of z: " << typeid(z).name() << std::endl; // -> 型確認用
    return 0;
}