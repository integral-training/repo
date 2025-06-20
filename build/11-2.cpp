// 静的ライブラリとは、複数のオブジェクトファイルをまとめたファイルのこと
// 静的リンクは、静的ファイルをリンクすること

// ライブラリとは、#include で展開するようなもの？

// $ ar rc libhoge.a 11-2b.o 11-2c.o -> libhoge.a 静的ライブラリができた
// ar -> アーカイブ操作のコマンド。rc -> アーカイブを作成してファイルを追加するという指定
// $ ar t libhoge.a で、アーカイブの内容-> 11-2b.o　11-2c.o を確認できる
// $ g++ -std=c++11 11-2.o libhoge.a で静的ライブラリをリンクさせる


#include <iostream>

int Add(int a, int b);
int Sub(int a, int b);

int main() {
    std::cout << Add(1, 2) << std::endl;
    std::cout << Sub(3, 4) << std::endl;
    return 0;
}