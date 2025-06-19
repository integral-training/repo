#include <iostream>
#include "Student.h"

// Student.hを介して引数を受け取り、メンバ変数の初期化コンストラクタ
Student::Student(std::string name, int jp, int ma, int en)
    : m_name(name), m_jp(jp), m_ma(ma), m_en(en) 
    {
    }

// 名前、各教科の点数を出力
void Student::printScores() 
{
    std::cout << "名前: " << m_name << std::endl;
    std::cout << "国語: " << m_jp << "点" << std::endl;
    std::cout << "数学: " << m_ma << "点" << std::endl;
    std::cout << "英語: " << m_en << "点" << std::endl;
}

// 平均点を返す
double Student::average() 
{
    double av =  (m_jp + m_ma + m_en) / 3.0;
    return av;
}