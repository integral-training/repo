#include <iostream>

void HelloWorld();  
void HelloWorld();  
void Hello();
void Hello(int n);

int main(){
    HelloWorld();
    Hello();
    Hello(16); 
    return 0;
}


void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

// 見方
// void HelloWorld(); -> 関数の宣言
// { std::cout << "Hello World!" << std::endl; } -> {}内の実装を定義
// 上記の関数は関数を宣言すると同時に、実装を定義している


//変数の場合
int x = 100;  // 変数を宣言(int x)しつつ、定義(= 100)して初期化。


// 以下はテキストメモ
// 関数の宣言は、プロトタイプ宣言と呼ばれることもあります。

// 定義は、シンボルの詳細を示すことです。 定義があることで、そのシンボルが具体的にどういうものなのか分かります。 
// 関数の場合は、実装そのものが定義としてみなされます。


// 宣言 は重複できます
// void HelloWord();  // 宣言
// void HelloWord();  // 重複してもOK

// 定義 は重複できない
void Hello() {
    std::cout << "Hello World!" << std::endl;
}

// void Hello() {  // 重複のためエラー
void Hello(int n) {
    std::cout << "Hello World!!!!!!" << std::endl;
}