#include <iostream>
#include <limits> // cin初期化に関係

enum TELEPHONE_ACTION : int // 電話の動作
{
    INCOM   = 1, // 着信
    CALL    = 2, // 発信
    RECEIVE = 3, // 受話
    END     = 4, // 通話終了
    OFF     = 5  // 電源OFF
};

enum TELEPHONE_STATUS : int // 電話の状態
{
    IDLE        = 1, // 待機中
    CALLING     = 2, // 発信中
    INCOMING    = 3, // 着信中
    ONCALLING   = 4  // 通話中
};

// 定型文関数。引数に電話の状態を受け取る。
int inputTelephoneAction(const int status)
{
    int inputAction = 0; // 電話の動作を決める入力値

    while (true)
    {
        std::string message = "[状態] ";
        if (status == TELEPHONE_STATUS::IDLE)
        {
            message += "待機中";
        }
        else if (status == TELEPHONE_STATUS::CALLING)
        {
            message += "発信中";
        }
        else if (status == TELEPHONE_STATUS::INCOMING)
        {
            message += "着信中";
        }
        else if (status == TELEPHONE_STATUS::ONCALLING)
        {
            message += "通話中";
        }
        else
        {
            message += "不明";
        }
        std::cout << message << std::endl;
        std::cout << std::endl;
        std::cout << "操作を選んでください:" << std::endl;
        std::cout << "1. 着信" << std::endl;
        std::cout << "2. 発信" << std::endl;
        std::cout << "3. 受話（自分または相手）" << std::endl;
        std::cout << "4. 通話終了" << std::endl;
        std::cout << "5. 電源OFF" << std::endl;
        std::cout << "番号を入力: ";
        std::cin >> inputAction;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "無効な入力です。数値で選択してください。" << std::endl;
        }
        else if (inputAction < 1 || inputAction > 5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "無効な入力です。1～5の数字を入力してください。" << std::endl;
        }
        else
        {
            break;
        }
    }
    return inputAction;
}

// 着信動作。電話の状態を受け取り、遷移可能な状態かによって処理が分岐
void actionIncoming(int& currentTelStatus)
{
    // 待機状態なら着信に遷移可
    if (currentTelStatus == TELEPHONE_STATUS::IDLE)
    {
        // 電話の状態を着信に変更
        currentTelStatus = TELEPHONE_STATUS::INCOMING;
    }
    else
    {
        std::cout << "着信できるのは待機中のみです。" << std::endl;
    }
}

// 発信動作。電話の状態を受け取り、遷移可能な状態かによって処理が分岐
void actionCalling(int& currentTelStatus)
{
    // 待機状態なら発信に遷移可
    if (currentTelStatus == TELEPHONE_STATUS::IDLE)
    {
        // 電話の状態を発信に変更
        currentTelStatus = TELEPHONE_STATUS::CALLING;
    }
    else
    {
        std::cout << "発信できるのは待機中のみです。" << std::endl;
    }
}

// 受話動作。電話の状態を受け取り、遷移可能な状態かによって処理が分岐
void actionReceiving(int& currentTelStatus)
{
    // 着信状態 or 発信状態なら通話に遷移可
    if (currentTelStatus == TELEPHONE_STATUS::CALLING || currentTelStatus == TELEPHONE_STATUS::INCOMING)
    {
        // 電話の状態を通話に変更
        currentTelStatus = TELEPHONE_STATUS::ONCALLING;
    }
    else
    {
        std::cout << "受話できるのは着信中または発信中のみです。" << std::endl;
    }
}

// 通話終了動作。電話の状態を受け取り、遷移可能な状態かによって処理が分岐
void actionEnd(int& currentTelStatus)
{
    // 通話状態なら待機に遷移可
    if (currentTelStatus != TELEPHONE_STATUS::IDLE)
    {
        // 電話の状態を待機に変更
        currentTelStatus = TELEPHONE_STATUS::IDLE;
    }
    else
    {
        std::cout << "現在通話中ではありません。" << std::endl;
    }
}

int main()
{
    int action = 0; // 関数から受け取る行動値
    bool loop = true; // do-while条件
    int currentTelStatus = TELEPHONE_STATUS::IDLE; // 初期状態は待機中
    
    std::cout << "携帯電話ステートマシン" << std::endl;

    while (loop)
    {
        action = inputTelephoneAction(currentTelStatus); // 電話の状態を定型文関数に渡す
        // currentTelStatus状態のとき、電話のACTIONを起こせるか判別する
        if (action == TELEPHONE_ACTION::INCOM) // 1 = 着信
        {
            actionIncoming(currentTelStatus);
        }
        else if (action == TELEPHONE_ACTION::CALL) // 2 = 発信
        {
            actionCalling(currentTelStatus);
        }
        else if (action == TELEPHONE_ACTION::RECEIVE) // 3 = 受話
        {
            actionReceiving(currentTelStatus);
        }
        else if (action == TELEPHONE_ACTION::END) // 4 = 通話終了
        {
            actionEnd(currentTelStatus);
        }
        else if (action == TELEPHONE_ACTION::OFF) // 5 = 電源OFF
        {
            std::cout << "携帯電話の電源を切りました。" << std::endl;
            loop = false;
        }
        else
        {
            std::cout << "不明なアクションです。" << std::endl;
        }
    }
    return 0;
}