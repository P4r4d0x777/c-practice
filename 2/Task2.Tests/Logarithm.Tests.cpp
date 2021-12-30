#include "pch.h"
#include "../Task2/Logarithm.h"

TEST(LogarithmTests, ParametrPlus8)
{
	ASSERT_EQ(Logarithm(8), 3);
}
TEST(LogarithmTests, ParametrMinus2)
{
	ASSERT_EQ(Logarithm(-2), -2);
}
TEST(LogarithmTests, ParametrPlus3)
{
	ASSERT_EQ(Logarithm(3), -1);
}

// Мало тестов => не нашли ошибку.

TEST(LogarithmTests, Zheltest)
{
	ASSERT_EQ(Logarithm(20), -1);
}

TEST(LogarithmTests, ParametrPlus24)
{
	ASSERT_EQ(Logarithm(16), 4);
}
TEST(LogarithmTests, ParametrPlus60)
{
	ASSERT_EQ(Logarithm(60), -1);
}