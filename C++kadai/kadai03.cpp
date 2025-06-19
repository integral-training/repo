#include <iostream>
#include <random> // 乱数生成用
#include <vector> // ベクタ用

int main() 
{
    // 乱数エンジンと分布を設定
    std::random_device rd; // 非決定的な乱数生成器
    std::mt19937 gen(rd()); // メルセンヌ・ツイスタエンジン
    std::uniform_int_distribution<> dist(1, 100); // 1から100の範囲の整数乱数

    int ranNum = dist(gen); // 乱数
    int input = 0; // 入力値
    std::vector<int> inputList; // 入力値を格納するvector配列

    std::cout << "=== 数字あてゲーム ===" << std::endl;
    std::cout << "1〜100の間の数字を当ててください。" << std::endl;

    // 入力値が乱数と等しくなるまでループ処理
    do 
    {
        std::cout << "数字を入力してください: ";
        std::cin >> input; // 入力値を変数inputに代入
        inputList.push_back(input); // 配列に入力値を格納

        // 以下の2行は追加機能。浮動小数点等によるエラー状態をクリア
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // もし入力値が乱数と等しいなら
        if (input == ranNum) 
        {
            std::cout << "正解です！ " << inputList.size() << " 回目で当たりました！" << std::endl;
            std::cout << std::endl; // 空行
            std::cout << "あなたの入力履歴: ";

            // 配列から値を取り出し続け、配列の最後の値を出力するときに改行するfor文
            for (int i = 0; i < inputList.size(); i++) 
            {
                if (i == inputList.size() - 1) 
                {
                    std::cout << inputList[i] << std::endl;
                }
                else 
                {
                    std::cout << inputList[i] << ", ";
                }
            }
        }
        else if(input > ranNum) // 入力値が乱数より大きいとき
        {
            std::cout << "もっと小さいです！" << std::endl;
        }
        else if(input < ranNum) // 入力値が乱数より小さいとき
        {
            std::cout << "もっと大きいです！" << std::endl;
        }
        else // 追加機能。1～100以外の入力値に対し返す処理。
        {
            std::cout << "不正な入力です。1〜100の間の数字を当ててください。" << std::endl;
        }

    } while(input != ranNum);
}