#include <iostream>

//ベクタは実行時に要素数を変更できる配列を扱うときに使います。
#include <vector> // ベクタのお呪い
int main(){
    std::vector<int> x = {0, 1, 2, 3, 4}; //x は要素数が 5 であるような int の配列になります。 
    x[2] = 10;
    std::cout << x.size() << std::endl; // 要素数の取得


    //要素を追加
    //x.emplace_back() とすると末尾へ要素を追加する
    x.emplace_back(4); // {0, 1, 2, 3, 4, 4}
    std::cout << x.size() << std::endl;
    std::cout << x[3] << std::endl;
    std::cout << x[5] << std::endl;

    //要素を削除
    //x.pop_back() とすると末尾から要素を削除する
    x.pop_back();
    std::cout << x.size() << std::endl;

    //先頭ポインタの取得
    //x.data() とすると配列の先頭ポインタが取得できます。
    std::vector<int> y = {4, 3, 2, 1, 0};
    auto px = y.data();  // 先頭ポインタ
    auto num = *px;  // 4
    std::cout << "先頭ポインタは" << num << std::endl;

    return 0;
}