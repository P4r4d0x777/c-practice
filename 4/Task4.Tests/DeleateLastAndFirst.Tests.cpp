#include "pch.h"
#include "../Task4/DeleateLastAndFirst.h"

// Разделительный символ пробел

TEST(Task4Tests, DeleateLastAndFirst)
{
	char str1[] = "       abc    14a 242af abc  abc  abc  abc";
	const char str2[] = "    14a 242af abc  abc  abc  ";
	DeleateLastAndFirst(str1);
	EXPECT_STREQ(str1, str2);
}
TEST(Task4Tests, DeleateLastAndFirstWithDelim)
{
	char str1[] = "    14a 242af abc  abc  ";
	const char str2[] = " 242af abc  ";
	DeleateLastAndFirst(str1);
	EXPECT_STREQ(str1, str2);
}