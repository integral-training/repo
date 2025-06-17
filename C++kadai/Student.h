#include <iostream>
#include <string>

#ifndef MYHEADER_H //インクルードガード
#define MYHEADER_H //インクルードガード

// 宣言だけ
class Student{
    public:
    int num;
    int num1;
    int num2;
    std::string str;

    Student(std::string w, int x, int y, int z);
    void printScores();
    int average();
    // void average(); // なんでだめ？
};

#endif  // MYHEADER_H //インクルードガード