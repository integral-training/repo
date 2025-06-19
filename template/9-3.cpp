#include <iostream>
#include "9-3.h"

// 特殊化

// 関数テンプレート
template <typename T>
T Sum(T a, T b) {
    return a + b;
}
// 関数テンプレートの関数の呼び出し
// Sum<int>(1, 2);

// Sum<int>(1, 2) という関数テンプレートの関数の呼び出しによって T が int である関数が必要と判断され、
// 次の関数が生成されます。
// int Sum(int a, int b) {
//     return a + b;
// }
// このように関数・クラステンプレートによって、
// 関数・クラスが生成されることを特殊化（暗黙的インスタンス化）という。


// 完全特殊化（または明示的特殊化）とは、すべてのパラメータが確定した時に別の定義を書き、
// 特定のテンプレート引数に対する挙動を変更すること。
// クラステンプレートの一部のテンプレート引数を確定させたり、制限できる部分特殊化もある。
// 例：通常のテンプレート
template <typename U>
class MyClass 
{
public:
    void display() 
    {
        std::cout << "通常テンプレ" << std::endl;
    }
};

// 例：特定の型（int）に対する完全特殊化
template <> // 関数の前に template <> を付けて完全特殊化を行うことを指定
class MyClass<int> // 関数名の後に <> で対象となるテンプレート引数を指定
{
public:
    void display() 
    {
        std::cout << "完全特殊状態" << std::endl;
    }
};

int main() 
{
    std::cout << Sum(1, 2) << std::endl;
    std::cout << Sumh(1, 2) << std::endl;
    MyClass<double> obj1; // 通常のテンプレートが使用される
    obj1.display();

    MyClass<int> obj2; // 完全特殊化されたテンプレートが使用される
    obj2.display();

    return 0;
}