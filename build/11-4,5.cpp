// 動的ロードとは、動的ライブラリを動的リンクしてプログラム実行中にライブラリを読み込むこと

// ライブラリに更新があったとき、ライブラリを使用したプログラムは
// それが動的か静的か、互換性の有無によって修正内容が異なる。

#include <iostream>
#include <dlfcn.h> // dlopen, dlsym, dlclose
#include <cstdlib>

int main() 
{
    // ライブラリをロード
    void* handle = dlopen("./libplugin.so", RTLD_LAZY);
    if (!handle) 
    {
        std::cerr << "dlopen failed: " << dlerror() << std::endl;
        return EXIT_FAILURE;
    }

    // 関数ポインタ取得
    typedef void (*hello_t)();
    hello_t hello = (hello_t)dlsym(handle, "hello");
    const char* dlsym_error = dlerror();
    if (dlsym_error) 
    {
        std::cerr << "dlsym failed: " << dlsym_error << std::endl;
        dlclose(handle);
        return EXIT_FAILURE;
    }

    // 関数を呼び出す
    hello();

    // ライブラリを閉じる
    dlclose(handle);
    return 0;
}
