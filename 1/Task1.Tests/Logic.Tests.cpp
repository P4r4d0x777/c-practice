#include "pch.h"
#include "../Task1/Logic.h"
TEST(LogicTests, ThreeLogicalVariables_000)
{
	ASSERT_EQ(LogicF(0, 0, 0), LogicG(0, 0, 0));
}
TEST(LogicTests, ThreeLogicalVariables_001)
{
	ASSERT_EQ(LogicF(0, 0, 1), LogicG(0, 0, 1));
}
TEST(LogicTests, ThreeLogicalVariables_010)
{
	ASSERT_EQ(LogicF(0, 1, 0), LogicG(0, 1, 0));
}
TEST(LogicTests, ThreeLogicalVariables_011)
{
	ASSERT_EQ(LogicF(0, 1, 1), LogicG(0, 1, 1));
}
TEST(LogicTests, ThreeLogicalVariables_100)
{
	ASSERT_EQ(LogicF(1, 0, 0), LogicG(1, 0, 0));
}
TEST(LogicTests, ThreeLogicalVariables_101)
{
	ASSERT_EQ(LogicF(1, 0, 1), LogicG(1, 0, 1));
}
TEST(LogicTests, ThreeLogicalVariables_110)
{
	ASSERT_EQ(LogicF(1, 1, 0), LogicG(1, 1, 0));
}
TEST(LogicTests, ThreeLogicalVariables_111)
{
	ASSERT_EQ(LogicF(1,1,1), LogicG(1, 1, 1));
}
