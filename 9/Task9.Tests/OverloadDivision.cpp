#include  "pch.h"
#include "../Task9/OverloadDivision.h"
#include <string>
TEST(OverloadDivision, two_double)
{
	ASSERT_EQ(3.5, Division(7, 2));
}
TEST(OverloadDivision, two_struct)
{
	ComplexNumber a, b;
	a.integer = 7;
	a.imaginary = -4;
	b.integer = 3;
	b.imaginary = 2;
	ComplexNumber res = Division(a, b);
	ASSERT_EQ(res.integer, 1);
	ASSERT_EQ(res.imaginary, -2);
}
TEST(OverloadDivision, two_string)
{
	std::string a = "6";
	std::string b = "2";
	ASSERT_EQ(Division(a, b), 3);
}