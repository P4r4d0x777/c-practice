#include "pch.h"
#include "../Task1/Inside.h"
TEST(InsideTests, PerimeterOfTriangle1)
{
	ASSERT_EQ(Inside(0,-10,10), true);
}
TEST(InsideTests, PerimeterOfTriangle2)
{
	ASSERT_EQ(Inside(-10, -10, 10), true);
}
TEST(InsideTests, InsideTriangle)
{
	ASSERT_EQ(Inside(-5, -6, 10), true);
}
TEST(InsideTests, PerimeterOfCircle1)
{
	ASSERT_EQ(Inside(-10, 0, 10), true);
}
TEST(InsideTests, PerimeterOfCircle2)
{
	ASSERT_EQ(Inside(10, 0, 10), true);
}
TEST(InsideTests, InsideCircle)
{
	ASSERT_EQ(Inside(0, 6, 10), true);
}
TEST(InsideTests, Outside)
{
	ASSERT_EQ(Inside(100, 100, 10), false);
}