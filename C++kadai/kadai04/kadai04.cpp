#include <iostream>
#include <string> // チェック関数用
#include <limits> // cin初期化に関係
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

// 各クラスに渡す値の入力チェック処理
double inputCheck(std::string message) //  引数は各図形の入力促すメッセージ
{
    double input = 0.0; // 入力
    while(true)
    {
    	std::cout << message;
    	std::cin >> input;

        if(std::cin.fail() || input < 0.0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "無効な入力です。数値で選択してください。" << std::endl;
        }
        else
        {
            break;
        }
    }
    return input;
}

void calcCircle() // 円の場合
{
    double inputRadius = inputCheck("半径を入力してください: "); // 半径入力

    Circle circle(inputRadius);
    std::cout << "面積: " << circle.calculateArea() << std::endl;
    std::cout << "周の長さ: " << circle.calculatePerimeter() << std::endl;
}

void calcRectangle() // 短形の場合
{
    double inputVertical = inputCheck("縦の長さを入力してください: "); // 縦長入力

    double inputWidth = inputCheck("横の長さを入力してください: "); // 横長入力

    Rectangle rectangle(inputVertical, inputWidth);
    std::cout << "面積: " << rectangle.calculateArea() << std::endl;
    std::cout << "周の長さ: " << rectangle.calculatePerimeter() << std::endl;
}

void calcSquare() // 正方形の場合
{
    double inputLength = inputCheck("1辺の長さを入力してください: "); // 辺長入力
                        
    Square square(inputLength);
    std::cout << "面積: " << square.calculateArea() << std::endl;
    std::cout << "周の長さ: " << square.calculatePerimeter() << std::endl;
}

enum SHARP_TYPE : int // 選択肢
{
    CIRCLE    = 1, // 円
    RECTANGLE = 2, // 矩形
    SQUARE    = 3, // 正方形
    END       = 4  // 終了
};

int main()
{
    bool loop = true; // do-while条件

    do
    {
        int inputSelection = 0; // 選択肢の入力値

        std::cout << std::endl;
        std::cout << "図形を選んでください:" << std::endl;
        std::cout << "1. 円" << std::endl;
        std::cout << "2. 四角形" << std::endl;
        std::cout << "3. 正方形" << std::endl;
        std::cout << "4. 終了" << std::endl;
        std::cout << "選択 (1-4): ";
        std::cin >> inputSelection;
        // 以下の2行でcinのエラー状態をクリア
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (inputSelection)
        {
            case SHARP_TYPE::CIRCLE: // 円
            {
                calcCircle();
                break;
            }

            case SHARP_TYPE::RECTANGLE: // 短形
            {
                calcRectangle();
                break;
            }

            case SHARP_TYPE::SQUARE: // 正方形
            {
                calcSquare();
                break;
            }

            case SHARP_TYPE::END:
            {
                std::cout << "終了します。" << std::endl;
                loop = false;
                break;
            }

            default:
            {
                std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                break;
            }
        }
    } while(loop);

    return 0;
}