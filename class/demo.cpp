#include <iostream>

// 何かを作ろうとしてた

class Number{
    virtual int Addition(int x) = 0;
// // //     virtual int Subtraction() = 0;
// // //     virtual int Multiplication() = 0;
// // //     virtual int Division() = 0;
};

class Add : public Number{
    public:
    int Addition(int x){
        return x * x;
    }
};

// class sub : public Number{}

// class mul : public Number{}

// class div : public Number{}

int main(){
    Add add;

    int x; 
    std::cout << "数字を入力して" ;
    std::cin >> x;
    std::cout << x << std::endl; // 角煮用

    std::cout << add.Addition(x) << std::endl;


    return 0;
}