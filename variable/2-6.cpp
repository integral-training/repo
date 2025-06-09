#include <iostream>
#include <random>

int main() {
    std::random_device rd;  // 非決定的な乱数生成器
    std::mt19937 mt(rd()); // メルセンヌ・ツイスタ（擬似乱数生成器）
    std::uniform_int_distribution<int> dist(1, 100); // 1から100までの一様分布

    int x = 0;

    //for文
    for (int i = 0; i < 5; ++i) {
         x = dist(mt);  // 乱数を生成

         //if文
         if(x >= 80){
             std::cout << "xは " << x << std::endl;
         }else if(x >= 50){
             std::cout << x << "は50以上 " << std::endl;
         }else {
            std::cout << x << "は50未満 " << std::endl;
        }
    }

    //do while文
    do{
        x = dist(mt);  // 乱数を生成

        //switch文
        switch(x){
            case 66: continue;

            case 80: std::cout << x << std::endl; //フォールスルー
            
            case 90: std::cout << x << std::endl;
            break;
        }
    }while(x <= 88);

    return 0;
}