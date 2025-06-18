#include <iostream>
#include <random> // 乱数生成用
#include <vector> // ベクタ用

int main() 
{
    // 乱数エンジンと分布を設定
    std::random_device rd; // 非決定的な乱数生成器
    std::mt19937 gen(rd()); // メルセンヌ・ツイスタエンジン
    std::uniform_int_distribution<> dist(1, 100); // 1から100の範囲の整数乱数

    int rannum = dist(gen); // 乱数生成して保持
    int input = 0; // 入力値を保持
    int inputcount = 0; // 入力回数を数える
    int finishcount = 0; // 拡張for文の取り出し回数を数える
    std::vector<int> array; // 入力値を格納するvector配列

    std::cout << "=== 数字あてゲーム ===" << std::endl;
    std::cout << "1〜100の間の数字を当ててください。" << std::endl;

    // 入力値が乱数と等しくなるまでループする処理
    do 
    {
        std::cout << "数字を入力してください: ";
        std::cin >> input; // 入力値を変数inputに代入
        array.push_back(input); // 配列に入力値を格納
        inputcount++; // 入力回数インクリメント
        // std::cout << inputcount << "回目" << std::endl; // 入力回数確認用

        // もし入力値が乱数と等しいなら
        if (input == rannum) 
        {
            std::cout << "正解です！ " << inputcount << " 回目で当たりました！" << std::endl;
            std::cout << std::endl; // 空白行
            std::cout << "あなたの入力履歴: ";

            // 配列から値を取り出し続け、配列の最後の値を出力するときに改行する拡張for文
            for (int finish : array) 
            {
                finishcount++;
                if (finishcount == array.size()) 
                {
                    std::cout << finish << std::endl;
                } 
                else 
                {
                    std::cout << finish << ", ";
                }
            }
        } 
        else if(input < 1) // 元の仕様には無い機能。不要なら削除。
        {
            std::cout << "不正な入力です。1〜100の間の数字を当ててください。" << std::endl;
        }
         else if(input > 100) // 元の仕様には無い機能。不要なら削除。
        {
            std::cout << "不正な入力です。1〜100の間の数字を当ててください。" << std::endl;
        } 
        else if(input > rannum) // 入力値が乱数より大きいとき
        {
            std::cout << "もっと小さいです！" << std::endl;
        } else if(input < rannum) // 入力値が乱数より小さいとき
        {
            std::cout << "もっと大きいです！" << std::endl;
        }

    } while(input != rannum);
}