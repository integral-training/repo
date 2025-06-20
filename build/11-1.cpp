#include <iostream>

// ビルドとは、ソースファイルから実行ファイルを生成する処理
// プリプロセス -> コンパイル -> リンク の流れで行う

// プリプロセスは、コンパイル前に行われる前処理のこと
// コメントの削除と プリプロセッサ司令 の実行
// g++ -std=c++14 -E 11-1.cpp -> -E を指定するとプリプロセスだけ実行

// コンパイルは、人間語のソースファイルをコンピュータで扱うために機械語に変換すること
// コンパイルはソースファイル単位で行う
// ソースファイルを機械語に変換した結果はオブジェクトファイルと呼ばれます。 
// g++ -std=c++14 -c 11-1.cpp -> -c を指定するとコンパイルだけ実行。11-1.cpp から 11-1.o にコンパイル

// リンクは、オブジェクトファイルなどをまとめて実行ファイルを生成すること
// リンクを行うプログラムはリンカという
// g++ -std=c++14 11-1.o 11-1b.o -> 二つのファイルをリンクして実行ファイルを生成


// サンプルでビルドする流れ
// g++ -std=c++14 -E 11-1.cpp, 11-1b.cpp, 11-1.h
// g++ -std=c++14 -c 11-1.cpp / g++ -std=c++14 -c 11-1b.cpp / g++ -std=c++14 -c 11-1.h -> .oファイル出現
// g++ -std=c++14 11-1.o 11-1b.o -> a.out実行ファイルが出現


#include <iostream>
#include <string>
#include "11-1.h"

int main() {
    std::string name; // 名前
    int jp, ma, en; // 国語、数学、英語

    std::cout << "生徒の名前を入力してください: ";
    std::getline(std::cin, name); // 入力値をnameに代入

    std::cout << "国語の点数を入力してください: ";
    std::cin >> jp;

    std::cout << "数学の点数を入力してください: ";
    std::cin >> ma;

    std::cout << "英語の点数を入力してください: ";
    std::cin >> en;

    // 生徒オブジェクトの作成
    Student student(name, jp, ma, en);

    std::cout << "\n--- 生徒の成績 ---\n";
    student.printScores();
    std::cout << "平均点: " << student.average() << "点" << std::endl;
    return 0;
}