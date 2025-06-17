#include <iostream>
#include <string>

#ifndef MYHEADER_H //インクルードガード
#define MYHEADER_H //インクルードガード

// 宣言だけ
class Student{
    public:
    int num; //定数
    int num1; //変数
    int num2; //変数
    std::string str; //変数

    Student(std::string w, int x, int y, int z);
    void printScores();
    int average();
};

#endif  // MYHEADER_H //インクルードガード