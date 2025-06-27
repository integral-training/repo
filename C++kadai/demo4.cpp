#include <iostream>

class talk
{
    int input = 0; // 入力値
    bool loop = true; // do-while条件

    std::cout << "[状態] 通話中" << std::endl;
    std::cout << std::endl;
    std::cout << "操作を選んでください:" << std::endl;
    std::cout << "1. 着信" << std::endl;
    std::cout << "2. 発信" << std::endl;
    std::cout << "3. 受話（自分または相手）" << std::endl;
    std::cout << "4. 通話終了" << std::endl;
    std::cout << "5. 電源OFF" << std::endl;
    std::cout << "番号を入力: ";
    std::cin >> input;
    // 以下の2行でcinのエラー状態をクリア
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(input == 1)
    {
        std::cout << "着信できるのは待機中のみです。" << std::endl;
    }
    else if(input == 2)
    {
        std::cout << "発信できるのは待機中のみです。" << std::endl;
    }
    else if(input == 3)
    {
        std::cout << "受話できるのは着信中または発信中のみです。" << std::endl;
    }
    else if(input == 4)
    {
        待機に戻る
    }
    else if(input == 5)
    {
        std::cout << "携帯電話の電源を切りました。" << std::endl;
        loop = false;
        break;
    }
    else if(input < 1 || input > 5)
    {
        std::cout << "無効な番号です。1～5の数字を入力してください。" << std::endl;
    }
    else
    {
        std::cout << "無効な入力です。1～5を入力してください。" << std::endl;
    }
}