#include <iostream>
#include "7-10.h"


// staticデータメンバ
// static データメンバの初期化/破棄はプログラムの開始/終了時にまとめて行われますが、 実行順序を制御することができない点が注意
// class StaticMem {
//     public:
//     static int count;
// };

int main() {
    StaticMem::increment();   // count をインクリメント
    StaticMem::print();       // 結果を表示（11と出力される）
    return 0;
}
// int StaticMem::count = 10;
// static データメンバはクラスの外で実体を定義する必要がある。
// ヘッダファイルが2つ以上のファイルでインクルードされる場合、 ヘッダファイルで実体の定義を行うと多重定義となりリンクエラーになってしまいます。 
// この問題を避けるために static データメンバの実体の定義はソースファイルで行います。