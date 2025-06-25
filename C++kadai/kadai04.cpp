#include <iostream>
#include <limits> // cin初期化に関係

class IShape // インターフェース
{
    public:
    virtual double calculateArea() const = 0; // 面積計算
    virtual double calculatePerimeter() const = 0; // 外周の長さ計算
};

class Circle : public IShape // 円クラス
{
    public:
    Circle(double inputRadius) : radius(inputRadius)
    {
    }

    double calculateArea() const override // 円の面積
    {
        return 3.14159 * (radius * radius);
    }

    double calculatePerimeter() const override // 円の外周の長さ
    {
        return (3.14159 * 2) * radius;
    }

    private:
    double radius = 0.0; // 半径
};

class Rectangle : public IShape // 短形クラス
{
    public:
    Rectangle(double inputVertical, double inputWidth) : vertical(inputVertical), width(inputWidth)
    {
    }

    double calculateArea() const override // 短形の面積
    {
        return vertical * width;
    }

    double calculatePerimeter() const override // 短形の外周の長さ
    {
        return (width + vertical) * 2;
    }

    private:
    double vertical = 0.0; // 縦の長さ
    double width = 0.0; // 横の長さ
};

class Square : public IShape // 正方形クラス
{
    public:
    Square(double inputLength) : length(inputLength)
    {
    }

    double calculateArea() const override // 正方形の面積
    {
        return length * length;
    }

    double calculatePerimeter() const override // 正方形の外周の長さ
    {
        return 4 * length;
    }

    private:
    double length = 0.0; // 1辺の長さ
};


int main()
{
    bool loop = true; // do-while条件
    do
    {
        int inputNum = 0; // 入力値
        double constNumA = 0; // コンストラクタ第1引数
        double constNumB = 0; // コンストラクタ第2引数

        std::cout << std::endl;
        std::cout << "図形を選んでください:" << std::endl;
        std::cout << "1. 円" << std::endl;
        std::cout << "2. 四角形" << std::endl;
        std::cout << "3. 正方形" << std::endl;
        std::cout << "4. 終了" << std::endl;
        std::cout << "選択 (1-4): ";
        std::cin >> inputNum;
        // 以下の2行でcinのエラー状態をクリア
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (inputNum) 
        {
            case 1: // 円
            {
                std::cout << "半径を入力してください: ";
                std::cin >> constNumA;

                if (std::cin.fail() || constNumA < 0.0)
                {
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                Circle circle(constNumA);
                std::cout << "面積: " << circle.calculateArea() << std::endl;
                std::cout << "周の長さ: " << circle.calculatePerimeter() << std::endl;
                break;
            }

            case 2: // 短形
            {
                std::cout << "縦の長さを入力してください: "; // 縦を入力してください: から変更
                std::cin >> constNumA;

                if (std::cin.fail() || constNumA < 0.0)
                {
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                std::cout << "横の長さを入力してください: "; // 横を入力してください: から変更
                std::cin >> constNumB;

                if (std::cin.fail() || constNumB < 0.0)
                {
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                Rectangle rectangle(constNumA, constNumB);
                std::cout << "面積: " << rectangle.calculateArea() << std::endl;
                std::cout << "周の長さ: " << rectangle.calculatePerimeter() << std::endl;
                break;
            }

            case 3: // 正方形
            {
                std::cout << "1辺の長さを入力してください: ";
                std::cin >> constNumA;

                if (std::cin.fail() || constNumA < 0.0)
                {
                    std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                
                Square square(constNumA);
                std::cout << "面積: " << square.calculateArea() << std::endl;
                std::cout << "周の長さ: " << square.calculatePerimeter() << std::endl;
                break;
            }

            case 4:
            {
                std::cout << "終了します。" << std::endl;
                loop = false;
                break;
            }

            default:
            {
                std::cout << "無効な入力です。数値で選択してください。" << std::endl;
                break;
            }
        }      
    } while(loop);

    return 0;
}