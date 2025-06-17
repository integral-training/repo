#include <iostream>

// defaultとdelete

class MyClass {
public:
    MyClass(int x) { int y = x;} // 定義したコンストラクタ。デフォルトコンストラクタは生まれないが...
    MyClass() = default;  // ← これだけで「定義済み」のデフォルトコンストラクタが生まれた
    // 宣言だけすることに意味を持たせたいとき、= default を使う。
    // virtual ~Class() = default;　この書き方でデストラクタがよく使われる

    MyClass(const MyClass&) = delete; // これでコピーコンストラクタの使用を禁止
    MyClass& operator=(const MyClass&) = delete; // これでコピー代入演算子の使用を禁止
};

int main(){
    MyClass a;
    MyClass b;
    b = a; // エラー
    MyClass c = a; // エラー
}