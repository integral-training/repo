#include <string>

#ifndef STUDENT_H //インクルードガード
#define STUDENT_H //インクルードガード

class Student
{
    public:
    std::string m_name; // 名前
    int m_jp; // 国語
    int m_ma; // 算数
    int m_en; // 英語

    Student(std::string name, int jp, int ma, int en); // 初期化コンストラクタ
    void printScores(); // 名前、各教科の点数を出力
    double average(); // 平均点を返す
};

#endif  //インクルードガード