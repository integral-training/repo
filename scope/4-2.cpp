// 4-2.cpp + 4-2b.cpp + 4-2h.cpp の３ファイルで実行中
#include <iostream>
#include <string>

#include "4-2h.cpp"  // 4-2b.cppのプロトタイプコードを、4-2h.cppで宣言し、4-2.cppで扱えるようにインポートした。
// これで 4-2h.cpp を介して 4-2b.cpp のコードを呼び出す。
//　コンパイル時には、ヘッダファイルを指定する必要はありません。  g++ -std=c++14 4-2.cpp 4-2b.cpp でOk

#include "4-2h.cpp" // 同じファイルを2回インクルードしている
#include "4-2h.cpp" // 同じファイルを3回インクルードしている
#include "4-2h.cpp" // 同じファイルを4回インクルードしている
#include "4-2h.cpp" // 同じファイルを5回インクルードしている
// インクルードガードがないと、void foo(); の宣言が 2回読み込まれ、重複定義とみなされることがあります（特にクラス定義では深刻です）。
// 何十に定義を重ねても動いちゃう

// MYHEADER_H が定義されていない → 中身を読み込む & MYHEADER_H を定義
// 2回目に読み込もうとすると → MYHEADER_H は既に定義されている → 読み飛ばす


// 以下の宣言により、別ファイル 4-2b.cpp のコードを扱えるようにした。
void DoSomething1(int n);   // プロトタイプ宣言

int main(){
    int b = 0;
    int x = 11;

    DoSomething1(34); // 呼び出して使用する
    // なお、ファイルを跨いで実行する場合は　$ g++ -std=c++14 4-2.cpp 4-2b.cpp　のように、複数個記述する
    std::cerr << "リンカエラー" << std::endl;

    DoSomething2("バ");
    DoSomething2("バナ");
    DoSomething2("バナナ");
    DoSomething2("バナーナ");
    DoSomething3();

    std::string s = "橋本";
    std::cout << "橋本は" << s.size() << std::endl;
    std::cout << "橋本は" << s.length() << std::endl;



    return 0;
}

inline void DoSomething1(int n){
    std::cerr << "リンカエラー" << std::endl;
    int b = 0;
    b += n;
    std::cout << b << std::endl;
};