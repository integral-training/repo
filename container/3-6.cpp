#include <iostream>

// マップとは、要素参照をする際に任意の型をキーとして指定する。連想配列や辞書と呼ばれる。
#include <map> // マップのお呪い
#include <unordered_map>
int main(){
    std::map<std::string, int> person = { {"Alice", 18} }; // { キー, 要素 ｝

    std::unordered_map<std::string, int> persons = { {"Alice", 18}, {"Bob", 20} };

    //要素参照
    std::cout << person["Alice"] << std::endl; //Aliceをキーに参照
    std::cout << persons["Bob"] << std::endl; //Bobをキーに参照

    //要素追加
    persons.insert({"Eve", 19});
    std::cout << persons.size() << std::endl;
    //要素削除
    persons.erase("Bob");
    std::cout << persons["Eve"] << std::endl;
    std::cout << persons.size() << std::endl;

    //補足
    //maoはキーの順番を保持する。unordered_mapはキーから計算する値でデータを管理する。
    //キーから計算する値のハッシュ値とは、ハッシュ関数から生成された固定長のビット列・値のこと




























    return 0;
}