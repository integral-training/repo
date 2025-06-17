// === 数字あてゲーム ===
// 1〜100の間の数字を当ててください。
// 数字を入力してください: 33
// もっと小さいです！
// 数字を入力してください: 21
// 正解です！ 2 回目で当たりました！

// あなたの入力履歴: 33, 21

#include <iostream>
#include <random>
#include <vector>

int main(){
    // 乱数エンジンと分布を設定
    std::random_device rd; // 非決定的な乱数生成器
    std::mt19937 gen(rd()); // メルセンヌ・ツイスタエンジン
    std::uniform_int_distribution<> dist(1, 100); // 1から100の範囲の整数乱数
    int y = dist(gen);
    int x = 0;
    std::vector<int> array;
    int count = 0;
    int finishcount = 0;

    std::cout << "=== 数字あてゲーム ===" << std::endl;
    std::cout << "1〜100の間の数字を当ててください。" << std::endl;
    do{
        std::cout << "数字を入力してください：";
        std::cin >> x;
        array.push_back(x);
        count++;
        // std::cout << count << "回目" << std::endl; // 回数確認用

        if(x == y){
            std::cout << "正解です！ " << count << " 回目で当たりました！" << std::endl;
            std::cout << std::endl;
            std::cout << "あなたの入力履歴：";
            for (int finish : array) {
                finishcount++;
                if (finishcount == array.size()) {
                    std::cout << finish << std::endl;
                }else{
                    std::cout << finish << ", ";
                }
            }
        }else if(x < 1){
            std::cout << "不正な入力です。1〜100の間の数字を当ててください。" << std::endl;
        }else if(x > 100){
            std::cout << "不正な入力です。1〜100の間の数字を当ててください。" << std::endl;
        }else if(x > y){
            std::cout << "もっと小さいです！" << std::endl;
        }else if(x < y){
            std::cout << "もっと大きいです！" << std::endl;
        }

    }while(x != y);
}