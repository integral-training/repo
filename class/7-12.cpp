#include <iostream>

// 共用体 -> キーワードはunion
// メモリ使用量を最小限に抑えたい場合に便利
// 例えば、異なる型のデータを1つの変数で扱いたい場合に使用されます。
// ただし、異なる型のデータを同じメモリ領域で使い回すため、コードの可読性が低くなることがあります。

// IntFloat という共用体を作成
union IntFloat {
    // 同じメモリ領域に int i と float f が入っている
    int i;
    float f;
};

int main() {
    IntFloat data;

    data.i = 1065353216;  // intとして代入（これは float の 1.0f に相当するビット値）

    std::cout << "整数として: " << data.i << std::endl;
    std::cout << "浮動小数として: " << data.f << std::endl;

    return 0;
}