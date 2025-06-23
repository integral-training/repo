#include <iostream>
#include <cstdlib>

class NewDelete {
public:
    NewDelete() {
    std::cout << "NewDelete' constructor is called." << std::endl;
    }
    ~NewDelete() {
    std::cout << "NewDelete' destructor is called." << std::endl;
    }
};

    int main(){
        // sizeof 演算子を使うことで、オブジェクトや型のバイト単位のサイズを取得することが出来ます。
        double x = 3.14;
        std::cout << sizeof(3) << std::endl;    // 4
        std::cout << sizeof(int) << std::endl;  // 4
        std::cout << sizeof(x) << std::endl;    // 8
        std::cout << sizeof(&x) << std::endl;   // 8

        // ヒープにメモリを動的に確保する場合は malloc を利用します。
        // ( 型名* ) malloc ( 確保する領域のサイズ )
        int* x1 = (int*)malloc(sizeof(int));
        int* x2 = (int*)malloc(sizeof(int) * 5);  // int[5] の領域を確保する場合

        // ヒープに確保したメモリを解放する場合は free を利用します。
        int* x3 = (int*)malloc(sizeof(int) * 5);
        free(x3);  // メモリ解放

        // malloc/free で生成されたオブジェクトはコンストラクタ・デストラクタの呼び出しが行われません。
        // 基本は new/delete を使うこと。

        std::cout << "---new/delete---" << std::endl;

        NewDelete* mc1 = new NewDelete();
        delete mc1;

        std::cout << "---malloc/free---" << std::endl;

        NewDelete* mc2 = (NewDelete*)malloc(sizeof(NewDelete));
        free(mc2);

        return 0;
    }