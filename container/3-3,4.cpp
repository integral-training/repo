#include <iostream>

// タプルとは、複数の値をひとまとめに扱える 型 です。配列と異なり、全ての要素が同じ型で揃える必要がない。

#include <tuple> // タプルのお呪い
#include <utility> // ペアのお呪い
int main(){
std::tuple<std::string, int, std::string> person { "Bob", 20, "USA" }; // string型と整数型がセットで入ってる
// std::tuple< この中で各要素の型を指定する > person { "Bob", 20, "USA" };
// 今回は<>の中に　std::string, int, std::string　を入れる。

// タプルも要素を参照できる。構文は　std::get< 指定した型 ≒ 要素番号 >(person);　
 std::string name = std::get<0>(person);
 std::cout << name << std::endl;


//std::tie() を使うとタプルの要素を個別の変数にまとめて代入することができます。
std::tuple<std::string, int, std::string> human { "Bobi", 23, "ISA" };

std::string name1; //変数
int age; //変数
std::string country; //変数

std::tie(name1, age, country) = human;
//std::tie( 代入される変数 ) = 代入するタプル名
std::cout << name1 << std::endl;
std::cout << age << std::endl;
std::cout << country << std::endl;


// 初期化のバリエーション
std::tuple<std::string, int> personA { "Bob", 20 };
std::tuple<std::string, int> personB("Bob", 20);
std::tuple<std::string, int> personC = std::make_tuple("Bob", 20);



//ペアは２つの値をひとまとめにして扱う 型 です。タプルと同じ。
std::pair<std::string, int> pear {"梨", 24};
std::get<0>(pear);
std::get<1>(pear);
std::string pears;
int volume;
std::tie(pears, volume) = pear;
std::cout << pears << std::endl;
std::cout << volume << std::endl;



 return 0;
}