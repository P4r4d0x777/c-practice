#include "pch.h"
#include "../Task5/ConvertStrToDouble.h"

TEST(FifthNumberSystem_Decryption, sometest1)
{
	double d = 718.01;
	char ch[7] = "32D.01";
	ASSERT_EQ(d, ConvertToDouble(ch,15));
}
TEST(FifthNumberSystem_Decryption, sometest2)
{
	double d = 718.01;
	char ch[8] = "+32D.01";
	ASSERT_EQ(d, ConvertToDouble(ch, 15));
}
TEST(FifthNumberSystem_Decryption, sometest3)
{
	double d = -718.01;
	char ch[8] = "-32D.01";
	ASSERT_EQ(d, ConvertToDouble(ch, 15));
}
TEST(FifthNumberSystem_Decryption, sometest4)
{
	double d = -718;
	char ch[8] = "-32D";
	ASSERT_EQ(d, ConvertToDouble(ch, 15));
}
TEST(FifthNumberSystem_Decryption, sometest5)
{
	double d = -0.01;
	char ch[8] = "-.01";
	ASSERT_EQ(d, ConvertToDouble(ch, 15));
}
TEST(FifthNumberSystem_Decryption, sometest6)
{
	double d = 0.01;
	char ch[8] = ".01";
	ASSERT_EQ(d, ConvertToDouble(ch, 15));
}