#include <iostream>
#include <limits>
#include <type_traits>

template<typename T>
T inputWithValidation(double inputNum) {
    T value;
    while (true) {
        std::cout << inputNum;
        std::cin >> value;

        // 入力失敗時（型不一致など）
        if (std::cin.fail() || inputRadius < 0.0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "無効な入力です。もう一度入力してください。\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 残りの入力を無視
            return value;
        }
    }
}