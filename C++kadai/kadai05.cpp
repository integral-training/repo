#include <iostream>

int main()
{
    std::cout << "携帯電話ステートマシン" << std::endl; // 初回だけ表示
    std::cout << "[状態] 待機中" << std::endl; // 値によって変化。以下はループ
    std::cout << std::endl;
    std::cout << "操作を選んでください:" << std::endl;
    std::cout << "1. 着信" << std::endl;
    std::cout << "2. 発信" << std::endl;
    std::cout << "3. 受話（自分または相手）" << std::endl;
    std::cout << "4. 通話終了" << std::endl;
    std::cout << "5. 電源OFF" << std::endl;
    std::cout << "番号を入力: ";
    std::cin >> inputNum;
}