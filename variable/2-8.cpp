#include <iostream>
#include <random>

// void Random();  // 前方宣言

//関数
// void Random(){
//     std::random_device rd;  // 非決定的な乱数生成器
//     std::mt19937 mt(rd()); // メルセンヌ・ツイスタ（擬似乱数生成器）
//     std::uniform_int_distribution<int> dist(1, 100); // 1から100までの一様分布

//     int x = 0;
//         for (int i = 0; i < 5; ++i) {
//          x = dist(mt);  // 乱数を生成

//          //if文
//          if(x >= 80){
//              std::cout << "xは " << x << std::endl;
//          }else if(x >= 50){
//              std::cout << x << "は50以上 " << std::endl;
//          }else {
//             std::cout << x << "は50未満 " << std::endl;
//         }
//     }
// }

// int main() {
//     Random();
//     return 0;
// }




/*
* main関数にも引数を渡せる。main関数に渡される引数をコマンドライン引数と呼ぶ。
* $ ./a.out <引数1> <引数2> <引数3> ... -> 引数を渡して起動
* int main(int argc, char* argv[]);
* -> int argc: コマンドライン引数の個数を表す
* -> char* argv[]: コマンドライン引数が格納される
*/
// int main(int argc, char* argv[]) {
//     for (int i = 0; i < argc; ++i) {
//         std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
//     }

//     return 0;
// }

//関数ポインタ
// 戻り値の型 (*変数名)(引数の型);
// 関数ポインタには、戻り値の型と引数の型・数・順番が一致している関数のアドレスが代入可能です。

int Add(int x, int y) {
    return x + y;
}

int main() {
    auto fp = Add;  // 上記の関数 Add のアドレスを保持する関数ポインタ fp
    //int (*fp)(int, int) = Add;  // int (*fp)(int, int) -> auto で関数ポインタは楽ちん
    int result = fp(3, 5);      // 関数ポインタ fp を介して関数 Add が実行される
    std::cout << result << std::endl;  // 8

    return 0;
}