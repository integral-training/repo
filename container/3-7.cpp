#include <iostream>

//セットとは、任意の型の集合を扱う 型 です。
#include <set> // お呪い
#include <unordered_set>
int main(){

    std::set<int> numbers = { 1, 5, 8, 14, 666 };
    std::cout << numbers.size() << std::endl;

    std::unordered_set<std::string> persons = { "Alice", "Boby" , "Mery"};
    std::cout << persons.size() << std::endl;

    //追加
    persons.insert("Eve");
    std::cout << persons.size() << std::endl;

    //削除
    numbers.erase(666);
    std::cout << numbers.size() << std::endl;

    return 0;
}