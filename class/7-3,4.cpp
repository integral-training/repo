#include <iostream>

class O{
    // 純粋仮想関数
    // 純粋仮想関数があるクラスのオブジェクトは作ることができません。
    // C++にインターフェース作成の記法がないので、純粋仮想関数がその代わり
    virtual int Pilot() = 0;
};

// 継承元のAが基底クラス
class A : public O{
    public:
    int num1 = 0;
    int num2 = 0;

    int Sum(){
        return num1 * num2;
    }

    // 仮想関数 -> 派生クラスで挙動を変更できるメンバ関数
    virtual void Print() {
        std::cout << "うおおおおおおおおおおおおおおおおおおお" << std::endl;
    }

    int Pilot() override {
        return num1 * num2;
    }

    // デフォルトのアクセス指定はprivateになる
    int prinum = 17;
};

// クラスのpublic？　クラス内のpublic？
// 継承先のBが派生クラス
class B : public A{
    public:
    void Set(int x, int y){
        num1 = x;
        num2 = y;
    }

    // オーバーライド
    // 条件を満たしていれば override と記述せずともオーバーライドできるが、可読性が上がるので
    void Print() override {
        std::cout << num2 << std::endl;
    }

    int Pilot() override {
        return num1 * num2;
    }

};

int main(){
    B b;
    b.Set(10, 20);
    std::cout << b.Sum() << std::endl;

    A& a = b; // アップキャスト
    std::cout << "アップキャストしても " << a.Sum() << std::endl;
    // ダウンキャストはしない方が望ましい

    return 0;
}


class Base {};

class Sub1 : public Base {};  // public指定の継承
class Sub2 : protected Base {};  // protected指定の継承
class Sub3 : private Base {};  // private指定の継承
class Sub4 : Base {};  // privateの継承 (デフォルト)