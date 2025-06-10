#include <iostream>

void kansu(const int* n, std::size_t num);  // 前方宣言

int main() {
    // 配列　いろいろな宣言方法
    int x[] = {1, 2, 3};
    std::cout << x[0] << std::endl;   

    int y[3] = {1, 2, 3};
    std::cout << y[1] << std::endl;   

    int z[5];
    z[0] = 1; z[1] = 2; z[2] = 3; z[3] = 4; z[4] = 5;
    std::cout << z[3] << std::endl;   


    #include <string> // 文字列を使うときのお呪い
    std::string s = "Hello"; // char型 の配列として扱われる
    std::cout << s[0] << std::endl; // H
    std::cout << s[1] << std::endl; // e
    std::cout << s[4] << std::endl; // o
    std::cout << s.size() << std::endl; // s.size() で文字列数を取得できる


    //配列のポインタ　->　配列の先頭を指し示すポインタが取得できる。indexは + で指定する。
    int w[5] = {1, 2, 3, 4};
    int* ww = w;
    std::cout << *ww << std::endl; 
    std::cout << *(ww + 3) << std::endl; 


    // 関数に配列を渡す
    // 配列の先頭要素へのポインタ と 要素数 をセットで渡す必要がある。要素数の情報が欠落するため。
    const std::size_t num = 5;  //要素数
    int n[num] = {0, 1, 2, 3, 4}; //配列
    kansu(n, num); //要素数と配列を渡す

    // std::array はあとで

    return 0;
}

void kansu(const int* n, std::size_t num){
    for (std::size_t i = 0; i < num; ++i) {
        std::cout << n[i] << std::endl;
    }
}

// void kansu(const int n[5]) {
//     static_assert(sizeof(n)==sizeof(int*), "");
//     for (int i = 0; i < 5; ++i) {
//         std::cout << n[i] << std::endl;
//     }
// }





/* おまけ c++11以降の別解
* int main(){
* int arr[3];
* static_assert(size(arr) == 3, "");
* }
*
* template <class T, std::size_t N>
* constexpr std::size_t size(const T (&)[N]) noexcept { return N; }
*/