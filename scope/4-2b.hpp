#include <iostream>
#include <string>

inline void DoSomething1(int n){
    std::cerr << "リンカエラー" << std::endl;
    int b = 0;
    b += n;
    std::cout << b << std::endl;
};

void DoSomething2(const std::string& w){
    std::string s = w;
    std::cout << "文字列サイズは" << s.size() << std::endl;
    std::cout << "文字列サイズは" << s.length() << std::endl;
};

void DoSomething3(){
    int x = 15;
    std::cout << x << std::endl;
};