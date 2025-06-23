// ダウンキャストは使わないようにコードを書くことが望ましい。

class Base {
    public:
        virtual ~Base(){}
};

class Sub1 : public Base {
 public:
    int x_;
};
class Sub2 : public Base {}

int main(){ 
    class Sub1 : public Base {};

    Sub1* sub1 = dynamic_cast<Sub1*>(new Base());  // ダウンキャスト(dynamic_cast)

    Base* base = new Sub1();  // Sub1 からのアップキャスト
    Sub1* sub1 = static_cast<Sub1*>(base);  // Sub1 へのダウンキャスト(static_cast)
    // base の実体は Sub1 なので問題なし
}