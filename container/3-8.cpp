#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
    //イテレータは、コンテナの要素の位置を指すもので、ポインタのように扱う
    std::vector<int> x = {0, 1, 2, 3, 4};

    // begin() でコンテナ内の先頭要素を指すイテレータを取得
    // イテレータが指す要素を参照するには、前に * をつけます。
    auto it = x.begin();
    std::cout << "先頭要素は" << *it << std::endl;

    // イテレータを使用して要素を出力
    std::cout << "先頭要素から" << *it << std::endl;

    // イテレータをクリメントで1つ進める
    ++it;

    // イテレータを使用して要素を出力
    std::cout << "先頭要素から" << *it << std::endl;

    //
    for (auto it = x.begin(); it != x.end(); ++it) {
        std::cout << *it << std::endl;
    }

    //イテレータはcコンテナの種類に依存しないため、どれでも動作する。
    std::set<int> y = {0, 1, 2, 3, 4};
    for (auto it = y.begin(); it != y.end(); ++it) {
        std::cout << *it << std::endl;  
    }
    //そのため #include <algorithm> で提供される機能を使用できる。
    //イテレータで使用できるコンテナは以下のもの。コンテナライブラリで提供されるコンテナ。
    std::array
    std::vector
    std::map
    std::set
    std::unordered_map
    std::unordered_set
    std::string 

    //マップのイテレータ
    // std::map や std::unordered_map のイテレータが指す要素はペアとなっています。 このペアは first がキーで second が値です。
    std::map<std::string, int> persons = { {"Alice", 18}, {"Bob", 20} };

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        const auto& person = *it;  // std::pair<std::string, int>
        const std::string& name = person.first;
        const int age = person.second;
        std::cout << name << ": " << age << std::endl;
    }

    //途中cd ../



















    return 0;
}