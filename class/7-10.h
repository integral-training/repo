#ifndef COUNTER_H_
#define COUNTER_H_

class StaticMem {
public:
    static int count;              // データメンバ。同じアドレス
    // ヘッダファイルが2つ以上のファイルでインクルードされる場合、 ヘッダファイルで実体の定義を行うと多重定義となりリンクエラーになってしまいます。 
    static void increment();       // インクリメントメンバ関数
    static void print();           // 出力メンバ関数
    // 関数も同じでアドレスが共通。memory削減の利点がある。
    // 新たに作られる領域は動的、作られないstatic系の領域を静的領域。
    // 後ろに引きづられて前後の値が一緒に変わってしまう点に注意。関数は用途によっては便利。
    // utilityクラスとか使うけど
};

#endif  // COUNTER_H_