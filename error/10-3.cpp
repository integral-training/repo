#include <cassert> // assert用
#include <iostream>
#include <limits>
#include <vector>

// アサーションとは、実行時に条件を満たさないとプログラムを異常終了させる処理
// assert はデバッグ機能で、 NDEBUG が定義されるリリースビルドでは無効となります。 
// NDEBUG を定義するには -DNDEBUG を指定します。$ g++ -std=c++11 -DNDEBUG main.cc

int Max(const std::vector<int>& v) 
{
    assert(!v.empty());

    int max = std::numeric_limits<int>::min();
    for (auto e : v) 
    {
        if (e > max) 
        {
            max = e;
        }
    }
    return max;
}

template <typename T, int N>
class Array 
{
    // コンパイル時に条件を満たさないとコンパイルエラーにする処理
    static_assert(N > 0, "サイズは0より大きくなければなりません");

 public:
    int size() const 
    { 
        return N; 
    }

    T data_[N];  // サイズ 0 の配列はコンパイルエラーにならない
};

int main() 
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2;

    std::cout << Max(v1) << std::endl;
    std::cout << Max(v2) << std::endl;

    Array<int, 0> a;
    return 0;

    return 0;
}