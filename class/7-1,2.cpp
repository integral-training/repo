#include <iostream>

// クラスは変数と関数の集合体
class Member{
    public: // アクセス就職誌は 修飾子: で表す・セミコロンではないよ。
    // クラスが持つフィールド変数を、「 データメンバ 」という
    int num1 = 10;
    int num2 = 20;
    const int num3 = 30;

    // クラスが持つ関数をメンバ関数という
    // クラス宣言の中でメンバ関数を定義した場合、暗黙的に inline 指定されます。
    int Snum1(){
        return num1 + num2;
    }

    int Snum2(){
        return num1 * num2;
    }

    int Snum3(); // 関数の宣言だけ
    
     // constメンバ関数
     // 状態を変化させずに処理を行いたいときに使える
    int Snum4() const {
        // num1 += 10; // データメンバを変更するとエラーになる
        return num2 % num1;
    }
    

    private:
    int yam1 = 6;
    int yam2 = 12;

    int Syum(){
        return yam1 + yam2;
    }


};

// クラスの外で定義した。書き方は 戻り値 クラス名::関数名(){}
int Member::Snum3(){
    // this-> で所属クラスのポインタを取得できる
    return this->num2 / this->num1;
}


int main(){
    // クラス型変数を作り、変数.メンバで参照
    Member mem;

    // ポインタでメンバを参照する場合
    Member* m = &mem;

    auto num = mem.num1 + mem.num2; // 変数.メンバ
    std::cout << num << std::endl;
    std::cout << "足すと" << mem.Snum1() << std::endl; // 変数.メンバ関数
    std::cout << "割ると" << mem.Snum3() << std::endl;

    num += m->num1 + m->num2; // ポインタ->メンバ
    std::cout << num << std::endl;
    std::cout << "掛けると" << m->Snum2() << std::endl; // ポインタ->メンバ関数
    std::cout << "余りは" << m->Snum4() << std::endl; // ポインタ->メンバ関数


    // mem.num3 += 5; // 定数を変更しようとしてエラー
    std::cout << "定数は" << m->num3 << std::endl;
    m->num1 += 10;
    std::cout << mem.num1 << std::endl;

    // アクセス圏外
    // auto yam = mem.yam1 + mem.yam2;
    // std::cout << yam << std::endl;
    
    return 0;
}
