// (gdb) p (print略) 変数名 で処理中の変数の値を確認できる
// printで確認した値は $n で記録され、print $n で結果を再利用できる 
// (gdb) print GreatestCommonDivisor(b, a) のように関数も扱えたり、
// (gdb) print &a ポインタや、(gdb) print *a デリファレンスも使える。

#include <iostream>

#include "swap.h"

// 最大公約数
int GreatestCommonDivisor(int a, int b) {
    while (a != 0) {
        b = b % a;
        Swap(&a, &b);
    }
    return b;
}

// 最小公倍数
int LeastCommonMultiple(int a, int b) {
    int gcd = GreatestCommonDivisor(a, b);
    return a * b / gcd;
}

int main() {
    int a = 12;
    int b = 18;
    std::cout << a << " と " << b << " の最小公倍数は "
            << LeastCommonMultiple(a, b) << " です" << std::endl;
    return 0;
}