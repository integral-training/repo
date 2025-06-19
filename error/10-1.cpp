#include <iostream>
#include <string>

// 例外処理とはプログラム実行中にエラーが発生した場合に、 
// 後続の処理を行うのをやめてエラー発生時用の処理を行うための機能です。

    // 関数から例外を投げる例
    int StringToInt(const std::string& str) 
    {
        int num = 0;

        for (const auto s : str) 
        {
            num *= 10;

            switch (s) 
            {
                case '0':  num += 0;  break;
                case '1':  num += 1;  break;
                case '2':  num += 2;  break;
                case '3':  num += 3;  break;
                case '4':  num += 4;  break;
                case '5':  num += 5;  break;
                case '6':  num += 6;  break;
                case '7':  num += 7;  break;
                case '8':  num += 8;  break;
                case '9':  num += 9;  break;
                default:
                    throw std::runtime_error("数値ではない文字が入っています");
            }
        }
        return num;
    }

    // noexceptは、関数が例外を送出しないことを明示的に表す
    int Compare(int a, int b) noexcept // (true)(false)などnoexceptの後ろに条件を付属できる
    {
        if (a < b) 
        {
            return -1;
        } else if (a > b) 
        {
            return 1;
        } else // a == b
        {  
            return 0;
        }
    }

    int main() 
    {
        // std::string str = "123456abc"; // std::string str = "123456"; // true
        // try 
        // {
        //     int num = 0;
        //     for (const auto s : str) 
        //     {
        //         num *= 10;
        //         switch (s) 
        //         {
        //             case '0':  num += 0;  break;
        //             case '1':  num += 1;  break;
        //             case '2':  num += 2;  break;
        //             case '3':  num += 3;  break;
        //             case '4':  num += 4;  break;
        //             case '5':  num += 5;  break;
        //             case '6':  num += 6;  break;
        //             case '7':  num += 7;  break;
        //             case '8':  num += 8;  break;
        //             case '9':  num += 9;  break;
        //             default:
        //                 // コンストラクタの引数でエラーメッセージを設定。例外はthrowで投げる。
        //                 throw std::runtime_error("数値ではない文字が入っています");
        //         }
        //     }
        //     std::cout << num << std::endl;  // 問題なく変換できた場合には変換後の値を出力
        // } 
        // catch (const std::runtime_error& e) // エラーをキャッチ
        // {
        //     // what() でエラーメッセージを取得
        //     std::cout << e.what() << std::endl;
        // }


        // 例外の型と型に応じた捕捉。一つのtryに対してcatchは複数設定できる。
        // try 
        // {
        // throw 123; // int型数値を投げて
        // } 
        // catch (const bool v) // int は bool とは異なる型であるため捕捉されない
        // { 
        // std::cout << "bool: " << v << std::endl;
        // } 
        // catch (const int v)  // intを捕まえる
        // {
        //     std::cout << v << std::endl;
        // }

        // エラーのクラス
        // try 
        // {
        // throw std::runtime_error("test");  // std::runtime_error を送出
        // } 
        // catch (const std::runtime_error& e) // 子クラスを先に置かないとエラー
        // {
        //     // 順番が逆だとこの処理は実行されない
        //     std::cout << "std::runtime_error: " << e.what() << std::endl;
        // }
        // catch (const std::exception& e) 
        // {
        //     // std::exception はエラー界の基底クラスだから何でもcatch
        //     std::cout << "std::exception: " << e.what() << std::endl;
        // } 
        // おまけ
        // catch (...) // catch (...) と記載することであらゆる例外を捕捉する
        // {
        // std::cout << "Unexpected exception was thrown." << std::endl;
        // }


        // 関数から例外を投げる例　の実行
        // std::string str = "123XY56";
        // try 
        // {
        //     auto num = StringToInt(str);
        //     std::cout << num << std::endl;
        // } 
        // catch (const std::runtime_error& e) 
        // {
        //     std::cout << e.what() << std::endl;
        // }

        // 例外が捕捉されない場合
        std::string str = "123XY56";
        auto num = StringToInt(str);
        std::cout << num << std::endl;
        return 0;
    }