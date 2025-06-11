#include <iostream>

// 宣言された同名のシンボルを同一のものとして扱うかどうかを示す概念のことを「リンケージ」という

int main(){

// 内部リンケージと無名名前空間
//  宣言に内部リンケージを持たせる場合は、 static ではなく無名名前空間を使うようにしましょう。

// int main() {
//     Print();
//     std::cout << x << std::endl;  // リンクエラー。main.cc からは other.cc の x が参照できない。
//     return 0;
// }
// 4-4b.cpp ファイル内
// #include "4-4c.cpp"
// #include <iostream>
// static int x = 246;  // 内部リンケージ。 4-4b.cpp 内でのみ参照可能
// namespace {
//     int y = 50;  // y に内部リンケージを持たせる
// }  // unnamed namespace
// void Print() {
//     std::cout << y << std::endl;  // ここから y は参照可能
// }
//
// 4-4c.cpp ファイル内
// void Print();


//内部リンケージと定義重複¶
//ソースファイル間で定義が重複している時、通常は定義の重複によるエラーになりますが、 
//各々に内部リンケージを持たせて別のファイルから見えなくしていれば、別の定義として扱うことができます。
// namespace {} // Aファイルの処理
// namespace {} // Bファイルの処理









    return 0;
}