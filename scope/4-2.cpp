// 4-2.cpp + 4-2b.cpp + 4-2h.cpp の３ファイルで実行
#include <iostream>
#include <string>

// 4-2b.cppのプロトタイプコードを、4-2h.cppで宣言し、4-2.cppで扱えるようにインポートした。
#include "4-2h.cpp" // これで 4-2h.cpp を介して 4-2b.cpp のコードを呼び出す。
//　コンパイル時には、ヘッダファイルを指定する必要はありません。  g++ -std=c++14 4-2.cpp 4-2b.cpp でOk


// 以下の宣言により、別ファイル 4-2b.cpp のコードを扱えるようにした。
void DoSomething1(int n);   // プロトタイプ宣言

int main(){
    DoSomething1(34); // 呼び出して使用する
    // なお、ファイルを跨いで実行する場合は　$ g++ -std=c++14 4-2.cpp 4-2b.cpp　のように、複数個記述する

    DoSomething2("バナーナ");





    return 0;
}