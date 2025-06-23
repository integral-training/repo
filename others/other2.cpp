#include <iostream>
// #include で指定ファイルを読み込んでその場に展開します。 単純なファイル展開であるためインクルードガードなどが必要となります。
// ファイルの指定には標準インクルードから検索する "..." とカレントディレクトリから検索する <...> の2種類があります。

#define BUFFER_SIZE 256
#undef BUFFER_SIZE
// #define でマクロを定義して文字列置換を行います。無効化するには #undef を使用します。

#define ECHO(VALUE) VALUE
// 関数形式のマクロは引数を使用して文字列へ置換されます。
#define SUM(VALUE1, VALUE2) VALUE1 + VALUE2 // 修正前
#undef SUM
#define SUM(VALUE1, VALUE2) (VALUE1 + VALUE2) // 修正後

int main() {
    // `char buffer[256];` に置換される
    // char buffer[BUFFER_SIZE]; // 無効化したのでエラー

    // `std::cout << 2 << std::endl;` に置換される
    std::cout << ECHO(2) << std::endl;

    // `std::cout << "abc" << std::endl;` に置換される
    std::cout << ECHO("abc") << std::endl;

    // `1 + 2` に置換される
    int a = SUM(1, 2);

    // `1 + 2 * 3` に置換される
    int b = SUM(1, 2) * 3;

    std::cout << a << std::endl;  
    std::cout << b << std::endl;  

    printf("This is line %d in file %s\n", __LINE__, __FILE__);
    // ファイル名と行番号を取得するマクロ

    // if文のようなもの
    #if true
    std::cout << "true" << std::endl;  // 有効 (コンパイルされる)
    #endif

    #if false
        std::cout << "false" << std::endl;  // 無効 (コンパイル前に削除される)
    #endif

    #if false
        std::cout << "1" << std::endl;  // 無効
    #elif true
        std::cout << "2" << std::endl;  // 有効
    #else
        std::cout << "3" << std::endl;  // 無効
    #endif


    // defined によってマクロが定義されているかどうかを条件にすることができます。
    #if defined SAMPLE_A
    std::cout << "A" << std::endl;  // 有効
    #endif

    #if defined SAMPLE_B
        std::cout << "B" << std::endl;  // 無効
    #endif

    return 0;
}