#include <iostream>
#include <string>

class A{
    public:
    const int cnum; //定数
    int num1; //変数
    int num2; //変数
    std::string str; //変数

    // コンストラクタで引数受け取り、値を初期化
    A(int x, int y, int z, std::string a): cnum(x),num1(y),num2(z), str(a) {};

    // 名前と年齢を表示する関数
    void Name(){
        std::cout << str << "の年齢は" << cnum << std::endl;
    }

    
    // デスコンストラクタ -> オブジェクトを破棄する際に呼び出されるメンバ関数
    // ~ にクラス名をつけた名前で戻り値がない関数がデストラクタになります。 デストラクタは引数をもちません。
    // 明示的に定義しない場合、 コンパイラが暗黙的にデストラクタを定義します。
    ~A(){std::cout << "thank you for kintetu rail way" << std::endl;};
    // クラス宣言外でデスコンストラクタも定義できる
    // 継承関係にあるクラスでデスコンストラクタを行う場合、子クラス -> 親クラスの流れになる
};

int main(){
    A a(15, 22, 30, "うおおおおおおお"); // コンストラクタに引数を渡す

    a.Name();

    return 0;
}