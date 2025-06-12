#include <iostream>
#include <memory> // スマートポインタのお呪い

int Question(){
    int* a = new int(100);
    int* b = a; // b からも a と同じリソースを参照できるようにする。

    // 同じリソースの所有権を持つ a と b のどちらを delete するべきか？

    return 0;
}


int Shared_ptr() {
    // std::shared_ptr は動的確保したリソースの所有権を共有できるスマートポインタです。 
    // 内部で所有権を持つオブジェクトの一覧を管理し、所有者がいなくなった時に自動的に delete する仕組みです。

    // std::shared_ptr オブジェクトを生成するには、 std::make_shared を利用します。
    std::shared_ptr<int> x = std::make_shared<int>(100); // int* x = new int(100); の代わり
                                                         // 所有者は1人。
                                                         
    {
        std::shared_ptr<int> y = x; // 通常のポインタ同様、コピーすることで所有権が共有される
                                    // 所有者が2人に増える。
        std::cout << *y << std::endl;
    } // y が破棄されて所有者が1人になる。

    std::cout << *x << std::endl;

    return 0;
} // 所有者が0人になるので、 x が自動で delete が行われる。



inline int Unique_ptr(){
    // std::unique_ptr は、 std::shared_ptr と違い、コピーが出来ません。 
    // そのため、確保したリソースの所有者が常に1人になります。
    std::unique_ptr<int> xx(new int(150));
    // std::unique_ptr<int> yy = xx; // コピーが出来ない

    std::cout << *xx << std::endl;

    return 0;
} // xx が所有しているリソースが解放される。


// 続き
inline int Unique_ptr(){
    std::unique_ptr<int> xxx(new int(200));
    std::unique_ptr<int> yyy(std::move(x)); // ムーブが出来るため、所有権の移動が可能。
                                          // 所有権を移動したため、x は何も所有していない。
    std::cout << *yyy << std::endl;

    return 0;
} // yyy が所有しているリソースが解放される。




int Weak_ptr() {
    std::shared_ptr<int> sp = std::make_shared<int>(250);
    std::weak_ptr<int> wp = sp; // sp を監視対象として wp に登録する

    std::shared_ptr<int> sp2 = wp.lock(); // 有効な場合は sp とリソースを共有する sp2 が作られる
    if (sp2) {
        std::cout << *sp2 << std::endl;
    } else {
        std::cout << "リソースは解放済み" << std::endl;
    }

    return 0;
}