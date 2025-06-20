#include <gtest/gtest.h> // Google Test を利用するため

#include "sample.h" // テスト対象

// テスト関数。TEST( テストケース名, テスト名 ) {}
// イベントテストのNegative、Zero、Positiveテストを行っている。
TEST (IsEvenTest, Negative) 
{
    EXPECT_FALSE(IsEvenx(-1));
    EXPECT_TRUE(IsEvenx(-2));
}

TEST (IsEvenTest, Zero) 
{
    EXPECT_TRUE(IsEvenx(0));
}

TEST (IsEvenTest, Positive) 
{
    EXPECT_FALSE(IsEvenx(1));
    EXPECT_TRUE(IsEvenx(2));
}

TEST(IsEvenTest, AssertPositive) {
    ASSERT_FALSE(IsEveny(1));  // ASSERTテストは失敗すると中断
    std::cout << "中断により、この文字列は出力されない" << std::endl;
    ASSERT_TRUE(IsEveny(2));
}

TEST(IsEvenTest, ExpectPositive) {
    EXPECT_FALSE(IsEveny(1));  // EXPECTテストは失敗しても続行
    std::cout << "続行のため、この文字列は出力される" << std::endl;
    EXPECT_TRUE(IsEveny(2));
}

// Google Test に用意されているアサーションを利用することで、 テスト対象コードの動作を検証することが出来ます。
// アサーション -> 実行時の条件を満たさないと異常終了

// true/falseのアサーション
// EXPECT_TRUE(condition);  // condition が true か
// EXPECT_FALSE(condition);  // condition が false か

// // 2つの値を比較するアサーション
// // EXPECT_ は、テストに失敗してもテスト関数がそのまま続行
// // ASSERT_ は、テストに失敗した時点でテストを中断し、テスト関数を抜ける
// EXPECT_EQ(expected, actual);  // expected == actual か
// EXPECT_NE(expected, actual);  // expected != actual か
// EXPECT_LT(expected, actual);  // expected < actual か
// EXPECT_LE(expected, actual);  // expected <= actual か
// EXPECT_GT(expected, actual);  // expected > actual か
// EXPECT_GE(expected, actual);  // expected >= actual か

// これらのアサーションを利用する場合は、 期待結果 (expected)、 テスト対象 (actual)の順で記述します。