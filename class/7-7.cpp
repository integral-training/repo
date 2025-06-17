#include <iostream>

// 演算子オーバーロード
// クラスに対する演算子を定義することで演算子が使用可能になります。 演算子は関数またはメンバ関数として定義します。
// a + b ➜  a.operator+(b) こんなイメージ
// - + はあまり使わないらしい。定義がないと審議できない。演算子で計算するときに演算子をオーバーロードして関数で計算する。( == ) を operator==() と同義。
// ++ も関数みたいな。operator++(){} とほぼ同義。
// インクリメントの前置きは単項演算子で、後起きは二項演算子で使う
class Integer {
 public:
    explicit Integer(int value) : value_(value) {}
    // C++におけるexplicitは、コンストラクタや型変換演算子に適用されるキーワードで、暗黙的な型変換を防ぐために使用

    // 内部の整数値を取得するアクセサ
    int Value() const {
        return value_;
    }

    // メンバ関数で単項演算子する場合 -> 計算×
    Integer operator-() const {
        Integer tmp(-Value());  // 演算対象は自オブジェクトを使用する
        return tmp;
    }

    // メンバ関数で二項演算子する場合 -> 計算
    // 加算演算子の左辺のメンバ関数に対して、右辺が引数として渡される
    Integer operator+(const Integer& rhs) const {
        Integer tmp(Value() + rhs.Value());  // 左辺は自オブジェクトを使用する
        return tmp;
    }

 private:
    int value_;
};

// // 負号演算子の対象が引数として渡される
// // const Integer& v は読み取り専用Integerオブジェの参照
// Integer operator-(const Integer& v) {
//     // Integerオブジェの整数値を取得し、-で負の値にして新たにIntegerオブジェ生成
//     Integer tmp(-v.Value());
//     return tmp; // それを返す
// }

// // 加算演算子の左辺が第1引数、右辺が第2引数として渡される
// Integer operator+(const Integer& lhs, const Integer& rhs) {
//     Integer tmp(lhs.Value() + rhs.Value());
//     return tmp;
// }

int main(){
    Integer a(2); // aはInteger()で作られる
    Integer b = -a; // -aでoperator関数が呼ばれ、-２が生成されbに代入

    std::cout << a.Value() << std::endl;  // 2
    std::cout << b.Value() << std::endl;  // -2


    Integer d(3);
    Integer e = a + d; // 2 + 3

    std::cout << d.Value() << std::endl;  // 3
    std::cout << e.Value() << std::endl;  // 5
    return 0;
}