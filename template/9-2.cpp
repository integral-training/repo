#include <iostream>

// クラステンプレート
// オブジェクト生成は、コンストラクタ<int> 変数(値); のように<>で型を指定する。省略不可。
// 関数同様に複数のテンプレート引数を設定可
// クラステンプレートでメンバ関数の戻り値の型を推論するには decltype 内で std::declval を使用します。
// 例：関数() -> decltype(std::declval< T >() * std::declval< U >())


template <typename T>
class Sumclass {
    public:
    T a;
    T b;

    Sumclass(T a, T b) : a(a), b(b) {}

    T Sum() {
        return a + b;
    }
};

int main(){
    Sumclass<int> sumclass(1, 2);
    std::cout << sumclass.Sum() << std::endl;
    return 0;
}