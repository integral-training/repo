#include <iostream>
#include <string>
#include "Student.h"

Student::Student(std::string name, int jp, int ma, int en): nameh(name), jph(jp), mah(ma), enh(en) {};
// Student.hを介して引数を受け取り、値を初期化コンストラクタ

// 名前、各教科の点数を出力
void Student::printScores() 
{
    std::cout << "名前: " << nameh << std::endl;
    std::cout << "国語: " << jph << "点" << std::endl;
    std::cout << "数学: " << mah << "点" << std::endl;
    std::cout << "英語: " << enh << "点" << std::endl;
};

// 平均点を返す
double Student::average() 
{
    double av =  (jph + mah + enh) / 3.0;
    return av;
};