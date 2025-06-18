#include <iostream>

int main() 
{
    int row = 0; // 入力値の行数を保持
    int column = 0; // 入力値の列数を保持

    std::cout << "縦のサイズ（行数）を入力してください: ";
    std::cin >> row; // 入力値（行数）を変数rowに代入

    std::cout << "横のサイズ（列数）を入力してください: ";
    std::cin >> column; // 入力値（列数）を変数columnに代入

    std::cout << std::endl; // 空白行
    std::cout << "出力結果:" << std::endl;

    // 条件式のiが行数より小さい間、列数分の*を出力し続け、
    // もし列数分に達したら改行し、再び次の行から列数分の出力を繰り返す処理。
    for (int i = 0; i < row ; i++) 
    {
        for (int j = 0; j < column ; j++) 
        {
            if (j == column-1) 
            {
                std::cout << "*" << std::endl;
            } 
            else 
            {
                std::cout << "*" ;
            }
        }
    }
    return 0;
}