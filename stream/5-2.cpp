#include <fstream> // <fstream> に用意されているクラスを使うことでファイルの操作が出来ます。
#include <iostream>
#include <string>
#include <vector>

int main(){
    // ファイルを読み込む場合は std::ifstream を使います。
    std::ifstream file1("file.txt");  // 読み込むファイルのパスを指定
    std::string line;

    while (std::getline(file1, line)) { // 1行ずつ読み込む
        std::cout << line << std::endl;
    }


    // ファイルに書き込む場合は std::ofstream を使います。
    std::ofstream file2("human.txt"); // 書き出すファイルのパスを指定
    std::vector<std::string> humans = { "田中", "橋本", "高橋" };

    for (const auto human : humans) { // 1行ずつ書き出し
        file2 << human << std::endl;  
    }

    std::ifstream file2a("human.txt"); // 読み込むファイルのパスを指定
    while (std::getline(file2a, line)) { // 1行ずつ読み込む
        std::cout << line << std::endl;
    }

    



    // // ファイルに書き込む場合は std::ofstream を使います。
    // std::ofstream file1a("file.txt", std::ios::app);  // 書き出すファイルのパスを指定
    // std::string quotation("田中", "橋本", "高橋");

    // file1a << std::endl << quotation;

    // std::ifstream file1b("file.txt");  // 読み込むファイルのパスを指定
    // while (std::getline(file1b, line)) {  // 1行ずつ読み込む
    //     std::cout << line << std::endl;
    // }


    return 0;
}