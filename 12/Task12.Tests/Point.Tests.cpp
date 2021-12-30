#pragma once // это только в h-файлах
#include "pch.h"
#include "../Task12/Point.h"
#include <sstream>

TEST(Point_Tests, Test_of_basic_constructor)
{
	Point A;
	ASSERT_EQ(A.GetX(), 1);
	ASSERT_EQ(A.GetY(), 1);
	ASSERT_STREQ(A.GetNameOfCoords(), "Cartesian");
}

TEST(Point_Tests, Test_of_convert_systems)
{
	Point A;
	A.ConvertToPolar();
	ASSERT_THROW(A.GetX(), std::exception);
	ASSERT_STREQ(A.GetNameOfCoords(), "Polar");
}

TEST(Point_Tests, Test_of_my_constructor_and_convert_systems)
{
	Point A(1, 0, "Cartesian");
	ASSERT_EQ(A.GetX(), 1);
	ASSERT_EQ(A.GetY(), 0);
	ASSERT_STREQ(A.GetNameOfCoords(), "Cartesian");
	A.ConvertToPolar();
	ASSERT_EQ(A.GetPolarAngle(), 0);
	ASSERT_EQ(A.GetR(), 1);
	ASSERT_STREQ(A.GetNameOfCoords(), "Polar");
}

TEST(Point_Tests, Test_of_copy_constructor)
{
	Point A(5, 5, "Cartesian");
	Point newA(A);
	ASSERT_NE(&A, &newA);
}

TEST(Point_Tests, Test_of_move_constructor)
{
	Point A(10, 10, "Cartesian");
	Point B((Point&&)A);
	ASSERT_EQ(B.GetX(), 10);
	ASSERT_EQ(B.GetY(), 10);
	ASSERT_STREQ(B.GetNameOfCoords(), "Cartesian");
}

TEST(Point_Tests, Test_of_destructor)
{
	Point A;
	Point B(A);
	ASSERT_NE(&A, &B);
}

TEST(Point_Tests, Test_of_set_elements)
{
	Point A;
	A.SetX(3);
	A.SetY(5);
	ASSERT_EQ(A.GetX(), 3);
	ASSERT_EQ(A.GetY(), 5);
	A.ConvertToPolar();
	A.SetR(1);
	A.SetPolarAngle(0);
	ASSERT_EQ(A.GetR(), 1);
	ASSERT_EQ(A.GetPolarAngle(), 0);
}

TEST(Point_Tests, Test_of_equal)
{
	Point A;
	Point B;
	ASSERT_EQ(A == B, true);
}

TEST(Point_Tests, Test_of_static_count)
{
	Point A;
	Point B;
	Point C;
	Point D;
	Point E;
	ASSERT_EQ(5, Point::getCount());
	Point L((Point&&)A);
	ASSERT_EQ(6, Point::getCount());
}

TEST(Point_Tests, Test_of_equally)
{
	Point A(5, 5, "Cartesian");
	Point B(5, 5, "Cartesian");
	B.SetX(10);
	A = B;
	ASSERT_NE(&A, &B);
	ASSERT_EQ(A.GetX(), B.GetX());
	Point C;
	C.SetX(1000);
	C = C;
	ASSERT_EQ(C.GetX(), 1000);
}

TEST(Point_Tests, Test_of_equally_with_move)
{
	Point A;
	A.SetX(42);
	A = (Point&&)A;
	ASSERT_EQ(A.GetX(), 42);
	Point B;
	B = (Point&&)A;
	ASSERT_EQ(B.GetX(), 42);
}

TEST(Point_Tests, Test_of_move_x_and_y)
{
	Point A(3, 3, "Cartesian");
	A.MoveX(-5);
	A.MoveY(5);
	ASSERT_EQ(A.GetX(), -2);
	ASSERT_EQ(A.GetY(), 8);
}

TEST(Point_Tests, Test_of_distance_between_two_dots)
{
	Point A(4, 6, "Cartesian");
	Point B(4, 7, "Cartesian");
	ASSERT_EQ(A - B, 1);
}

TEST(Point_Tests, Test_of_input_output)
{
	// не должно в тестах быть cin/cout.
	// Протестируйте либо с stringstream, либо с файлами
	Point A;
	std::stringstream s;
	s << A;
	std::string output;
	s >> output;
	EXPECT_EQ(output, (std::string)"(Cart)Point(1,1)");
}