#pragma once // это только в h-файлах
#include "pch.h"
#include "../Task13/Set.h"
#include "../Task13/CorrectPyramid.h"
#include "../Task13/Functors.h"
                        
TEST(SetTests, Test1)
{
	Set<int> A(20);
	for (unsigned i = 0; i < 10; i++)
		A.Add(i);
	ASSERT_EQ(A.Search(5, FunctorInteger()), true);
}
TEST(SetTests, Test2)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i); 
	Set<int> B(20); // 0 - 3
	for (unsigned i = 0; i < 4; ++i)
		B.Add(i);
	Set<int> C;
	C = A + B;
	for (unsigned i = 0; i < 10; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 0 - 9
}
TEST(SetTests, Test3)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 10 - 15
	for (unsigned i = 10; i < 16; ++i)
		B.Add(i);
	Set<int> C;
	C = A + B;
	for (unsigned i = 0; i < 16; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 0 - 15
}
TEST(SetTests, Test4)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 3 - 15
	for (unsigned i = 3; i < 16; ++i)
		B.Add(i);
	Set<int> C;
	C = A + B;
	for (unsigned i = 0; i < 16; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 0 - 15
}	
TEST(SetTests, Test5)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 0 - 5
	for (unsigned i = 0; i < 6; ++i)
		B.Add(i);
	Set<int> C;
	C = A - B;
	for (unsigned i = 6; i < 10; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 6 - 9
}
TEST(SetTests, Test6)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 0 - 5
	for (unsigned i = 0; i < 6; ++i)
		B.Add(i);
	Set<int> C;
	C = A * B;
	for (unsigned i = 0; i < 6; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 0 - 5
}
TEST(SetTests, Test7)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 10 - 20
	for (unsigned i = 10; i < 21; ++i)
		B.Add(i);
	Set<int> C;
	C = A * B;
	for (unsigned i = 0; i < 21; ++i)
		ASSERT_EQ(false, C.Search(i, FunctorInteger()));
	std::cout << C; // NULL
}
TEST(SetTests, Test8)
{
	Set<int> A(20); // 0 - 9
	for (unsigned i = 0; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 0 - 3
	for (unsigned i = 0; i < 4; ++i)
		B.Add(i);
	Set<int> C;
	C = A - B;
	for (unsigned i = 4; i < 10; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 4 - 9
}
TEST(SetTests, Test9)
{
	Set<int> A(20); // 1 - 9
	for (unsigned i = 1; i < 10; ++i)
		A.Add(i);
	Set<int> B(20); // 100
	B.Add(100);
	Set<int> C;
	C = A - B;
	for (unsigned i = 1; i < 10; ++i)
		ASSERT_EQ(true, C.Search(i, FunctorInteger()));
	std::cout << C; // 1 - 9
}
TEST(SetTests, Test10)
{
	Set<double> A(10);
	A.Add(5.2);
	ASSERT_EQ(true, A.Search(5.2, FunctorDouble()));
}
TEST(SetTests, Test11)
{
	CorrectPyramid SABCD;
	SABCD.height = 1;
	SABCD.squareSize = 2;
	Set<CorrectPyramid> A(10);
	A.Add(SABCD);
	ASSERT_EQ(true, A.Search(5.1231, FunctorPyramidArea()));
}