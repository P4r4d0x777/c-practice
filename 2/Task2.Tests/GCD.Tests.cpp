#include "pch.h"
#include "../Task2/GCD.h"

TEST(RecursiveGCDtests, AthirtyBten)
{
	ASSERT_EQ(RecursiveGCD(30,10), 10);
}
TEST(RecursiveGCDtests, AtenBthirty)
{
	ASSERT_EQ(RecursiveGCD(10, 30), 10);
}
TEST(RecursiveGCDtests, AminustenBzero)
{
	ASSERT_EQ(RecursiveGCD(-10, 0), 10);
}
TEST(RecursiveGCDtests, AminustenBminusone)
{
	// Из двух НОДов выбирает больший (то есть натуральный)
	ASSERT_EQ(RecursiveGCD(-10, -1), 1);
}
TEST(RecursiveGCDtests, AthirtyBtvelve)
{
	ASSERT_EQ(RecursiveGCD(30, 12), 6);
}
TEST(RecursiveGCDtests, AtvelveBthirty)
{
	ASSERT_EQ(RecursiveGCD(12, 30), 6);
}


TEST(GCDtests, AthirtyBten)
{
	ASSERT_EQ(GCD(30, 10), 10);
}
TEST(GCDtests, AtenBthirty)
{
	ASSERT_EQ(GCD(10, 30), 10);
}
TEST(GCDtests, AminustenBzero)
{
	ASSERT_EQ(GCD(-10, 0), 10);
}
TEST(GCDtests, AminustenBminusone)
{
	ASSERT_EQ(GCD(-10, -1), 1);
}
TEST(GCDtests, AthirtyBtvelve)
{
	ASSERT_EQ(GCD(30, 12), 6);
}
TEST(GCDtests, AtvelveBthirty)
{
	ASSERT_EQ(GCD(12, 30), 6);
}