#include <iostream> // C++で標準入出力を扱うために必須のヘッダー
#include <string>

int main(){
    std::cout << "標準出力";
    // std::endl で改行を出力します。

    std::cout << 1 + 2 << std::endl;
    std::cout << "std::endl で改行します。" << std::endl;
    std::cout << 3 + 4 << std::endl;

    std::cerr << "標準エラー出力" << std::endl;

    std::cout << "好きな食べ物を入力してください: ";
    std::string food;
    std::cin >> food;
    std::cout << "好きな食べ物は " << food << " です。" << std::endl;

    return 0;
}