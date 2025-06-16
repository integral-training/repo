#include <iostream>

int main(){
    int x = 0;
    int y = 0;

    std::cout << "縦のサイズ（行数）を入力してください：";
    std::cin >> x;
    std::cout << x << std::endl; // 入力値表示
    std::cout << "横のサイズ（列数）を入力してください：";
    std::cin >> y;
    std::cout << y << std::endl; // 入力値表示
    std::cout << "出力結果：" << std::endl;

    for(int i = 0; i < x ; i++){
        for(int j = 0; j < y ; j++){
            if(j == y-1){
                std::cout << "＊" << std::endl;
            }else{
                std::cout << "＊" ;
            }
    }
    }
    return 0;
}