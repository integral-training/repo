// スタックフレームとは、関数が呼び出されるたびに関数の情報が積みあがる特殊な領域のこと。
// bt (backtrace略) でスタックフレームの一覧を表示できる

#include <iostream>

int GreatestCommonDivisor(int a, int b) {
    if (a == 0) {
        return b;
    }

    return GreatestCommonDivisor(b % a, a);
}

int main() {
    int a = 12;
    int b = 18;
    std::cout << a << " と " << b << " の最大公約数は "
            << GreatestCommonDivisor(a, b) << " です" << std::endl;
    return 0;
}