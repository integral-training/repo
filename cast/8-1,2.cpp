#include <iostream>

// 極力C＋＋のキャスト演算子を使うこと
int main(){
    // 明示的型変換
    double dx = 3.14;
    int x = static_cast<int>(dx);  // 3
    std::cout << x << std::endl;
}

// ダウンキャストのdynamic_cast
// 定数外しのconst_cast
// 値はそのまま型情報の変換を行うreinterpret_cast