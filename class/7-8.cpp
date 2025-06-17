#include <iostream>

// コピー代入演算子
// 引数はコピー元となるオブジェクトの const 左辺値参照
// 戻り値はコピー先オブジェクト (自オブジェクト) の左辺値参照
class Copy {
public:
    Copy() {
        std::cout << "デフォルトコンストラクタ呼び出し" << std::endl;
    }

    // コピーコンストラクタ
    Copy(const Copy& c) {
        std::cout << "コピーコンストラクタ呼び出し" << std::endl;
    }

    // コピー代入演算子
    Copy& operator=(const Copy& c) {
        std::cout << "コピー代入演算子呼び出し" << std::endl;
        return *this;
    }
};


// ムーブ代入演算子
// 引数はムーブ元となるオブジェクトの"右"辺値参照
// 戻り値はムーブ先オブジェクト (自オブジェクト) の"左"辺値参照
class Move {
public:
    Move() {
        std::cout << "デフォルトコンストラクタ" << std::endl;
    }

    Move(Move&& other) noexcept {
        std::cout << "ムーブコンストラクタ" << std::endl;
    }

    Move& operator=(Move&& other) noexcept {
        std::cout << "ムーブ代入演算子" << std::endl;
        return *this;
    }
};


int main() {
    Copy c1;  // デフォルトコンストラクタでオブジェクト作成1

    // Copy c2 = c1; // コピー初期化はコピーコンストラクタで

    Copy c2;  // デフォルトコンストラクタでオブジェクト作成2
    c2 = c1;      // コピー代入演算子でコピー代入。operator= を呼び出している。
    Copy c3 = c1;  // コピーコンストラクタによる初期化


    Move m1; // デフォルトコンストラクタでオブジェクト作成1

    // Movable m2 = std::move(m1); // ムーブ初期化はムーブコンストラクタで

    Move m2; // デフォルトコンストラクタでオブジェクト作成2
    m2 = std::move(m1);  // ムーブ代入演算子呼び出し
    Move m3 = std::move(m2);  // ムーブコンストラクタが呼ばれる

    return 0;
}