#include "pch.h"
#include "../Task1/Trigonometry.h"
TEST(TrigonometryTests, TwoIntegers)
{
	ASSERT_FLOAT_EQ(TrigonometryZ1(10), TrigonometryZ1(10));
}
TEST(TrigonometryTests, TwoNonIntegers)
{
	ASSERT_FLOAT_EQ(TrigonometryZ1(3.1257), TrigonometryZ1(3.1257));
}