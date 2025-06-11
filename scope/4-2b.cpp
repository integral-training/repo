#include <iostream>
#include <string>

void DoSomething1(int n){
    int b = 0;
    b += n;
    std::cout << b << std::endl;
};

void DoSomething2(const std::string& w){
    std::string s = w;
    std::cout << "文字列サイズは" << s.size() << std::endl;
};