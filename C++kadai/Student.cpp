#include <iostream>
#include <string>
#include <iomanip>
#include "test.h"

// 定義だけ
Student::Student(std::string w, int x, int y, int z): str(w), num(x), num1(y), num2(z) {};
// コンストラクタで引数受け取り、値を初期化

void Student::printScores(){
    std::cout << "名前：" << str << std::endl;
    std::cout << "国語：" << num << std::endl;
    std::cout << "数学：" << num1 << std::endl;
    std::cout << "英語：" << num2 << std::endl;
};

int Student::average(){
    double av =  (num + num1 + num2) / 3.0;
    std::cout << "平均点: " << av << "点" << std::endl; // 関数内で出力するように
    return 0;
};

    // return static_cast<double>(num + num1 + num2) / 3.0; // 試し打ち