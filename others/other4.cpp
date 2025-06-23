// voidポインタ
// 型をもたないポインタを使う場合に void ポインタを使用します。

#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class ValueType {
    Int,
    Double,
    String
};

void print(void* data, ValueType type) {
    switch (type) {
        case ValueType::Int:
            std::cout << *static_cast<int*>(data) << std::endl;
            break;
        case ValueType::Double:
            std::cout << *static_cast<double*>(data) << std::endl;
            break;
        case ValueType::String:
            std::cout << *static_cast<std::string*>(data) << std::endl;
            break;
        default:
            std::cout << "Unknown type\n";
    }
}

class Printable {
public:
    virtual ~Printable() {}
    virtual void print() const = 0;
};

class IntValue : public Printable {
    int value;
public:
    IntValue(int v) : value(v) {}
    void print() const override {
        std::cout << value << std::endl;
    }
};

class DoubleValue : public Printable {
    double value;
public:
    DoubleValue(double v) : value(v) {}
    void print() const override {
        std::cout << value << std::endl;
    }
};

class StringValue : public Printable {
    std::string value;
public:
    StringValue(const std::string& v) : value(v) {}
    void print() const override {
        std::cout << value << std::endl;
    }
};

int main() {
    int i = 10;
    double d = 3.14;
    std::string s = "hello";

    print(&i, ValueType::Int);
    print(&d, ValueType::Double);
    print(&s, ValueType::String);

    std::vector<std::unique_ptr<Printable>> values;
    values.emplace_back(new IntValue(42));
    values.emplace_back(new DoubleValue(2.71));
    values.emplace_back(new StringValue("C++14"));

    for (const auto& val : values) {
        val->print();
    }
}