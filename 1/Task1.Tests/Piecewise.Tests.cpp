#include "pch.h"
#include "../Task1/Piecewise.h"
#include <math.h> 

TEST(PiecewiseTests, X_minus11__R_3)//вне интервала
{
	ASSERT_FLOAT_EQ(Piecewise(-11, 3), 0);
}
TEST(PiecewiseTests, X_minus10__R_3)//пр€ма€
{
	ASSERT_FLOAT_EQ(Piecewise(-10, 3), 2);
}
TEST(PiecewiseTests, X_minus6__R_3)//пр€ма€
{
	ASSERT_FLOAT_EQ(Piecewise(-6, 3), 0);
}
TEST(PiecewiseTests, X_zero__R_3)//пр€ма€
{
	ASSERT_FLOAT_EQ(Piecewise(0, 3), -3);
}
TEST(PiecewiseTests, X_plus1__R_3)//нижн€€ полуокружность
{
	ASSERT_FLOAT_EQ(Piecewise(1, 3), -sqrtf(8.0F));
}
TEST(PiecewiseTests, X_plus3__R_3)//нижн€€ полуокружность
{
	ASSERT_FLOAT_EQ(Piecewise(3, 3), 0);
}
TEST(PiecewiseTests, X_plus4__R_3)//верхн€€ полуокружность
{
	ASSERT_FLOAT_EQ(Piecewise(4, 3), sqrtf(5.0F));
}
TEST(PiecewiseTests, X_plus6__R_3)//верхн€€ полуокружность
{
	ASSERT_FLOAT_EQ(Piecewise(6, 3), 3);
}
