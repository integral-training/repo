#include <iostream>

#ifndef SUM_H_
#define SUM_H_

// 特殊化はコンパイラによって行われるため、
// ヘッダでテンプレートを使用する際は定義も書いておく。
template <typename T>
inline T Sumh(T a, T b) {  // inline 指定が必要
    return a + b;
}

#endif  // SUM_H_