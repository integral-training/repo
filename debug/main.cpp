// デバッグビルドは、g++ -std=c++14 -g main.cpp sum.cpp このように書く。
// デバッグビルドされた a.out をデバッグするために $ gdb a.out でGDBを起動します。
// プロンプトと呼ばれる文字列 (gdb) が出力されると GDB 
// (gdb) q (quit略)で終了。(gdb) r (run略)でデバッグ開始。
// なお、breakポイントが設定されていない状態だとプログラム終了まで実行開始されます。
// breakポイントは、(gdb) b (break略) main.cpp:6 や (gdb) b Sum のように記述して設定する。
// breakで一時停止したデバッグは、continue で再開できる。delete でポイントを削除できる。i b のNumで指定できる。
// breakポイントは、(gdb) info breakpoints (i b) で一覧を表示できる。

#include <iostream>

#include "sum.h"

int main() {
    std::cout << Sum(1, 2) << std::endl;
    return 0;
}