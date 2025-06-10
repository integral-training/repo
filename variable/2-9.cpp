#include <iostream>
#include <functional>

int main() {
    
    /* 
    * ラムダ式は、簡潔に関数オブジェクトを記述するための式です。 
    * ラムダ式で生成される関数オブジェクトは auto で保持することが出来ます。
    * 構文：auto 変数名 = [ キャプチャ ]( 引数リスト ) -> 戻り値の型 { 処理内容 };
    */

    /* 
    *ラムダ式の外にある変数をラムダ式の中で使用する場合は、 ラムダ式先頭の [] 内でキャプチャと呼ばれるものの指定が必要です。
    *キャプチャには、コピーキャプチャと参照キャプチャの2種類が存在します。
    *
    *記述例	内容
    *[=]	ラムダ式定義時に存在する全ての変数をコピーしてラムダ式の中で使う
    *[&]	ラムダ式定義時に存在する全ての変数を参照してラムダ式の中で使う
    *[a]	変数 a をコピーしてラムダ式の中で使う
    *[&a]	変数 a を参照してラムダ式の中で使う
    *[&a, b]	変数 a は参照し、変数 b はコピーしてラムダ式の中で使う
    *[=, &a]	変数 a は参照し、それ以外はコピーしてラムダ式の中で使う
    *
    *引数の使い方は変わらない。引数無し、戻り値型の記述も省略した場合は()も省略できる
    *ラムダ式内の型推論に任せる場合は、[](){ 戻り値 } このように省略可能

    */

    auto func = [](int a, int b) -> int { return a + b; };  // int を2つ受け取り、足した結果を返すラムダ式のfunc
    int result = func(4, 6);
    std::cout << result << std::endl;  // 10


    int init = 5;
    // キャプチャを指定することで {} 内で変数 init を使うことができる
    auto f = [init](int a, int b) { return init + a + b; };   // コピーキャプチャ
    init = 0; // ラムダ式定義後に値を変えても、式に反映されない
    int result_copy = f(4, 6);
    std::cout << result_copy << std::endl;  // ラムダ式の定義時点で init がコピーされる -> 5
    
    init = 0;
    auto g = [&init](int a, int b) { return init + a + b; };  // 参照キャプチャ
    init = 5; // ラムダ式実行前に参照する値が変更されたら、それを使って処理する
    int result_ref = g(4, 6);
    std::cout << result_ref << std::endl;  // ラムダ式実行時の init の値が参照される -> 0

    auto x = [](int a, int b) { return a + b; };
    int result_x = x(4, 5);
    std::cout << result_x << std::endl; 


    // 関数ポインタに変換できる。キャプチャ無し限定
    // int (*fp)(int, int) = [](int x, int y) { return x + y; };


    // std::function
    // std::function で関数ポインタやラムダ式（キャプチャを持つラムダ式も含む）を保持することが出来ます。 
    // std::function を使うことで、関数ポインタのような複雑な構文が簡潔になるという利点もあります。

    int Add(int x, int y) {
        return x + y;
    }

    std::function<int(int, int)> f = Add;  // std::function<戻り値の型(引数の型)> 変数名
    // function < add関数の戻り値型 ( Add関数の引数 ) 変数f = 元となるAdd関数
    int result = f(3, 5);                  // f を介して関数 Add が実行される
    std::cout << result << std::endl;      // 8
    //ファンクションとポインタ

    f = [](int x, int y) { return x * y; };  // ラムダ式も保持可能
    std::cout << f(4, 7) << std::endl;       // 28



    return 0;
}