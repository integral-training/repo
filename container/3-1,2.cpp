#include <iostream>
#include <string> // 文字列を使うときのお呪い
#include <array> // 高性能な配列を使うお呪い

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

    // 配列の範囲for文
    // int x[] = {0, 1, 2, 3, 4};
    // for (auto&& e : x) {
    //     std::cout << e << std::endl;
    // }


    std::string s = "Hello"; // char型 の配列として扱われる
    std::cout << s[0] << std::endl; // H
    std::cout << s[1] << std::endl; // e
    std::cout << s[4] << std::endl; // o
    std::cout << "文字列サイズは" << s.size() << std::endl; // s.size() で文字列数を取得できる


    //配列のポインタ　->　配列の先頭を指し示すポインタが取得できる。要素番号は + で指定する。
    int w[5] = {1, 2, 3, 4};
    int* ww = w;
    std::cout << *ww << std::endl; 
    std::cout << *(ww + 3) << std::endl; 

    // 関数に配列を渡す
    // 配列の先頭要素へのポインタ と 要素数 をセットで渡す必要がある。要素数の情報が欠落するため。
    const std::size_t num = 5;  //要素数
    int n[num] = {0, 1, 2, 3, 4}; //配列
    kansu(n, num); //配列と要素数を渡す


    // std::array -> 高性能な配列
    std::array<int, 5> xxx = {0, 1, 2, 3, 4}; //x は要素数が５であるような int型の配列になります。 
    xxx[3] = 10;
    std::cout << "高性能な数：" <<xxx.size() << std::endl;
    std::cout << "高性能の４番目：" << xxx[3] << std::endl;


    return 0;
}

void kansu(const int* n, std::size_t num){
    for (std::size_t i = 0; i < num; ++i) {
        std::cout << i <<  "番目は" << n[i] << std::endl;
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