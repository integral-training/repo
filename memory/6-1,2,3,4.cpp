#include <iostream>
//ベクタは実行時に要素数を変更できる配列を扱うときに使います。
#include <vector> // ベクタのお呪い


void Memory();
void ChangeToFifty2(int* v);
void Container();

int main(){

    Memory();

    int b = 100;
    ChangeToFifty2(&b); // b の参照を引数に渡す
    std::cout << b << std::endl; // vポインタの変更により、参照元のbの値が変化した

    return 0;
}

void Memory(){
    int x = 10; // 変数ｘはスタックに格納
    int y = 20; // 変数ｙはスタックに格納


    int* h1 = new int(50);  // int型のメモリを確保し、メモリに値を代入
    int* h2 = new int[5];   // 配列の場合は [] を付ける
    std::cout << *h1 << std::endl;
    delete h1;    // new によって確保されたメモリを delete で解放
    delete[] h2;  // 配列の場合は [] を付ける


    // ディープコピー -> デフォルトの代入
    int xx = 15;
    int yy = xx; // xxをyyにコピー（代入）したことで、yy分の新規メモリ領域が確保される。
    yy = 120;
    std::cout << xx << std::endl;
    

    // シャローコピー -> 実体を指すポインタのみ生成。実体をコピーしないのでメモリ確保が不要。
    int* xxx = new int(50); // xxxポインタにint型の50メモリ確保
    int* yyy = xxx; // xをyへシャローコピーする
    *yyy = 100; // yyyポインタから値を書き換える
    std::cout << *xxx << std::endl; // xxxの値も書き変わった

    // xxx = nullptr; // xxxの値はyyyから操作できるため、xxxをどの変数も参照していないヌルポインタにする
    // これがムーブの考え方

    // 左辺値: 基本的にそのスコープの間生き続ける名前付きのオブジェクト
    // 右辺値: リテラルや関数が返す一時オブジェクトのようなその瞬間に破棄されて不要になるもの
    int xxxx = 300; // x は左辺値。300 のようなリテラルは右辺値。
    int yyyy = function(); // y は左辺値。関数 function が返す一時オブジェクトは右辺値。
    int zzzz = xxxx; // zzzz と xxxx は左辺値。
    //右辺値は左辺値へ格納したら必要無くなるので、右辺値にはムーブの考え方が適用できることがわかります。 
    // C++11 以降、コンパイラはこの考え方を認識し、ムーブを実現してくれるようになりました。


    // x はコンパイラからしてみると左辺値なので、本来は y への代入時にディープコピーされます。
    // そこで、左辺値を右辺値にキャストする std::move を使います。 
    // x を右辺値にキャストすることで、ディープコピーではなくムーブができるようになります。
    std::vector<int> xxxxx(1000000);
    std::vector<int> yyyyy = std::move(xxxxx); // std::move で xxxxx を右辺値にキャスト


    // 右辺値を参照するには && を付けよう


} // 関数の終了とともに変数 x, y はスタックから取り除かれる。
  // スタックはLIFO（後入れ先出し）形式のため y, x の順で取り除かれる。
  // 仮に delete せずに関数が終了すると、int[] 分のメモリが解放されないままになる。

void ChangeToFifty2(int* v) {  // bの参照を引数に受け取ってvにシャローコピー
    // bを指した状態で値を50に変更する
    *v = 50;
}


// 保持する要素をヒープメモリ上に確保
void Container(){
    std::vector<int> x = {0, 1, 2, 3, 4}; //x は要素数が 5 であるような int の配列になります。 
    x[2] = 10;
    std::cout << x.size() << std::endl; // 要素数の取得
}