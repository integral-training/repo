// 動的ライブラリとは、実行に必要な処理を分割した外部ファイルのこと
// ビルド時に依存関係だけ設定し、実行時に結合することで実現する。依存関係の設定を動的リンクという。

// $ g++ -std=c++14 -shared -o libhoge.so 11-2b.o 11-2c.o -> 動的ライブラリ libhoge.so が生まれる。
// $ g++ -std=c++14 11-3.o libhoge.so -> 動的リンク

#include <iostream>

int Add(int a, int b);
int Sub(int a, int b);

int main() {
    std::cout << Add(1, 2) << std::endl;
    std::cout << Sub(3, 4) << std::endl;
    return 0;
}