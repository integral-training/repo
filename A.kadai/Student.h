#include <iostream>
#include <string>

#ifndef MYHEADER_H //インクルードガード
#define MYHEADER_H //インクルードガード

class Student{
    public:
    int jph; // ヘッダー版国語
    int mah; // ヘッダー版算数
    int enh; // ヘッダー版英語
    std::string nameh; // ヘッダー版名前

    Student(std::string name, int jp, int ma, int en); // 初期化コンストラクタ
    void printScores(); // 名前、各教科の点数を出力
    double average(); // 平均点を返す
};

#endif  //インクルードガード