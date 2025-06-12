#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <map>

int main(){
    //イテレータは、コンテナの要素の位置を指すもので、ポインタのように扱う
    std::vector<int> x = {0, 1, 2, 3, 4};

    // begin() でコンテナ内の先頭要素を指すイテレータを取得
    // イテレータが指す要素を参照するには、前に * をつけます。
    auto it = x.begin();
    std::cout << "先頭要素は" << *it << std::endl;

    // イテレータをクリメントで1つ進める
    ++it;

    // イテレータを使用して要素を出力
    std::cout << "先頭要素から" << *it << std::endl;

    //イテレータを使ったコンテナのループ
    for (auto it = x.begin(); it != x.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // 以下の範囲for文でシンプル化
    // for (auto&& e : x) {
    // std::cout << e << std::endl;
    // }

    //イテレータはcコンテナの種類に依存しないため、どれでも動作する。
    std::set<int> y = {0, 1, 2, 3, 4};
    //セット配列ｙの始まりから終わりまで、という条件式
    //end() で取得するイテレータは最終要素ではなく、 最終要素の1つ先であるためループの終了条件として使用できます。
    for (auto it = y.begin(); it != y.end(); ++it) {
        std::cout << *it << std::endl;  
    }
    //そのため #include <algorithm> で提供される機能を使用できる。
    //イテレータで使用できるコンテナは以下のもの。コンテナライブラリで提供されるコンテナ。
    // std::array
    // std::vector
    // std::map
    // std::set
    // std::unordered_map
    // std::unordered_set
    // std::string 

    //マップのイテレータ
    // std::map や std::unordered_map のイテレータが指す要素はペアとなっています。 このペアは first がキーで second が値です。
    std::map<std::string, int> persons = { {"Alice", 18}, {"Bob", 20} };

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        const auto& person = *it;  // std::pair<std::string, int>
        const std::string& name = person.first; //キー
        const int age = person.second; //値
        std::cout << name << ": " << age << std::endl;
    }


    // 色々なイテレータ
    // 前方向イテレータ (Forward Iterator) -> イテレータを前に進めるだけ
    std::unordered_set<int> fx = {0, 1, 2, 3, 4};

    auto fit = fx.begin();
    std::cout << *fit << std::endl;

    ++fit;  // 前に進める
    std::cout << *fit << std::endl;


    // 双方向イテレータ(Bidirectional Iterator) -> 前後に移動できる
    std::set<int> bx = {0, 1, 2, 3, 4};

    auto bit = bx.begin();
    std::cout << *bit << std::endl;  

    ++bit;  // 前に進める
    std::cout << *bit << std::endl;  

    --bit;  // 後ろへ戻す
    std::cout << *bit << std::endl;  


    // ランダムアクセスイテレータ (Random Access Iterator) -> 任意の位置にイテレータを動かせる
    std::vector<int> rx = {0, 1, 2, 3, 4};

    auto rit = rx.begin();
    std::cout << *it << std::endl;  // 0

    ++rit;  // 前に進める
    std::cout << *rit << std::endl;  // 1

    --rit;  // 後ろへ戻す
    std::cout << *rit << std::endl;  // 0

    rit = rit + 3;  // 3つ前に進める
    std::cout << *rit << std::endl;  // 3

    // it は変更せずに it から2つ後ろへ戻した要素を参照
    std::cout << rit[-2] << std::endl;  // 1 (irt から2つ後ろへ戻した要素)
    std::cout << *rit << std::endl;  // 3 (rit は変更されていない)




    // イテレータと参照の無効化
    // 要素の追加や削除を行うと 既存のイテレータや要素への参照が無効になることがあります。 
    // 無効化されたイテレータや参照を使用した場合の挙動は未定義動作 (保証されない) です。
    // たとえば std::vector の要素を削除すると、 削除した要素の位置とそれ以降の位置のイテレータと参照が無効化されます。

    // std::vector<int> x = {0, 1, 2, 3, 4, 5, 6};
    // auto it1 = x.begin() + 2;
    // auto it2 = x.begin() + 3;
    // auto it3 = x.begin() + 4;
    // std::cout << *it1 << std::endl;  // 2
    // std::cout << *it2 << std::endl;  // 3
    // std::cout << *it3 << std::endl;  // 4

    // x.erase(x.begin() + 3);  // index=3 の要素を削除

    // std::cout << *it1 << std::endl;  // 2 (有効なまま)
    // std::cout << *it2 << std::endl;  // 未定義動作 (無効化される)
    // std::cout << *it3 << std::endl;  // 未定義動作 (無効化される)

















    return 0;
}