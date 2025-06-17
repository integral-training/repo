#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"

int main() {
    std::string name;
    int jp, ma, en;

    std::cout << "生徒の名前を入力してください: ";
    std::getline(std::cin, name);

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
    student.average(); // 変更
    // std::cout << "平均点: " << student.average() << "点" << std::endl; // 既存の呼び出し

    // return 0;
}

