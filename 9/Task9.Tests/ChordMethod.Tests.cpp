#include  "pch.h"
#include "../Task9/�hordMethod.h"
#include <cmath>
double F1(double x)
{
	return log(x) + pow(x + 1, 3);
}
double F2(double x)
{
	return log(x) + 1;
}
double F3(double x)
{
	return log(x);

double(*(functions[3]))(double) = { &F1, &F2, &F3 };
TEST(ChordMethodTests, func1)
{
	ASSERT_EQ(floor(0.187439), floor(ChordMehod(functions[0], 0.1, 1, 0.000001)));
}
TEST(ChordMethodTests, func2)
{
	ASSERT_EQ(floor(0.367879), floor(ChordMehod(functions[1], 0.05, 0.2, 0.0001)));
}
TEST(ChordMethodTests, func3)
{
	ASSERT_EQ(1, ChordMehod(functions[2], 0.5, 2, 0.000001));
}