#include <iostream>
#include <limits> // cin初期化に関係
#include "kadai04.circle.h"
#include "kadai04.rectangle.h"
#include "kadai04.square.h"

int main()
{
    bool loop = true; // do-while条件
    do
    {
        int inputNum = 0; // 入力値
        double constNumA = 0; // コンストラクタ第1引数
        double constNumB = 0; // コンストラクタ第2引数

        std::cout << std::endl;
        std::cout << "図形を選んでください:" << std::endl;
        std::cout << "1. 円" << std::endl;
        std::cout << "2. 四角形" << std::endl;
        std::cout << "3. 正方形" << std::endl;
        std::cout << "4. 終了" << std::endl;
        std::cout << "選択 (1-4): ";
        std::cin >> inputNum;
        // 以下の2行でcinのエラー状態をクリア
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (inputNum) 
        {
            case 1: // 円
            {
                std::cout << "半径を入力してください: ";
                std::cin >> constNumA;
                while(std::cin.fail() || constNumA < 0.0)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cout << "半径を入力してください: ";
                    std::cin >> constNumA;
                }

                Circle circle(constNumA);
                std::cout << "面積: " << circle.calculateArea() << std::endl;
                std::cout << "周の長さ: " << circle.calculatePerimeter() << std::endl;
                break;
            }

            case 2: // 短形
            {
                std::cout << "縦の長さを入力してください: "; // 縦を入力してください: から変更
                std::cin >> constNumA;
                while(std::cin.fail() || constNumA < 0.0)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cout << "縦の長さを入力してください: ";
                    std::cin >> constNumA;
                }

                std::cout << "横の長さを入力してください: "; // 横を入力してください: から変更
                std::cin >> constNumB;
                while(std::cin.fail() || constNumB < 0.0)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cout << "横の長さを入力してください: ";
                    std::cin >> constNumB;
                }

                Rectangle rectangle(constNumA, constNumB);
                std::cout << "面積: " << rectangle.calculateArea() << std::endl;
                std::cout << "周の長さ: " << rectangle.calculatePerimeter() << std::endl;
                break;
            }

            case 3: // 正方形
            {
                std::cout << "1辺の長さを入力してください: ";
                std::cin >> constNumA;
                while(std::cin.fail() || constNumA < 0.0)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cout << "1辺の長さを入力してください: ";
                    std::cin >> constNumA;
                }
                
                Square square(constNumA);
                std::cout << "面積: " << square.calculateArea() << std::endl;
                std::cout << "周の長さ: " << square.calculatePerimeter() << std::endl;
                break;
            }

            case 4:
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