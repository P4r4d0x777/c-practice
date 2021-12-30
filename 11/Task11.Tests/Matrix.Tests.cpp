#pragma once
#include "pch.h"
#include "..//Task11/Matrix.h"

TEST(Matrix_Tests, Test_of_constructor)
{
	Matrix triple(3, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ASSERT_EQ(triple.GetElement(i, j), 0);
}

TEST(Matrix_Tests, Test_of_copying_cnstructor)
{
	Matrix triple(3, 3);
	Matrix newTriple(triple);
	// И все, ASSERT-ов не будет?
	ASSERT_NE(&triple, &newTriple);
}

TEST(Matrix_Tests, Test_of_destructor)
{
	Matrix one(3, 2);
	Matrix two(2, 3);
	Matrix three(two);
	// И все, ASSERT-ов не будет?
	ASSERT_NE(&one, &two);
	ASSERT_NE(&three, &two);
}

TEST(Matrix_Tests, Test_of_equally)
{
	Matrix one(1, 1);
	Matrix two(1, 1);
	one.SetElement(5, 0, 0);
	one = two;
	// И все, ASSERT-ов не будет?
	ASSERT_NE(&one, &two);
	ASSERT_EQ(one.GetElement(0, 0), two.GetElement(0, 0));
	Matrix N(1, 1);
	N.SetElement(999, 0, 0);
	N = N;
	ASSERT_EQ(N.GetElement(0, 0), 999);
}

TEST(Matrix_Tests, Test_of_plus)
{
	Matrix one(1, 1);
	Matrix two(1, 1);
	one.SetElement(5, 0, 0);
	two.SetElement(5, 0, 0);
	Matrix three = one + two;
	ASSERT_EQ(three.GetElement(0, 0), 10);
}

TEST(Matrix_Tests, Test_get_and_set)
{
	Matrix one(1, 1);
	one.SetElement(1, 0, 0);
	ASSERT_EQ(1, one.GetElement(0, 0));
}


// У вас в коде присутствуют исключения (что правильно и здорово), их тоже
// можно тестировать
// есть макрос ASSERT_THROW, который позволяет протестировать факт генерации исключения.

TEST(Matrix_Error_Tests, Test_get_and_set_error) // Работает, только если убрать try catch, как в GetElement() и оставить просто throw, с try catch неправильно тесты работают. Не знаю как лучше оставить
{                                                // Пишет Actual: it throw nothing, я так понимаю это из за того, что я уже обработал ошибку в блоке catch()?
	Matrix one(1, 1);
	one.SetElement(1, 0, 0);
	ASSERT_THROW(one.GetElement(5, 5), std::exception);
}

TEST(Matrix_Tests, Test_of_move_constructor)
{
	Matrix N(1, 1);
	N.SetElement(99, 0, 0);
	Matrix J((Matrix&&)N);
	ASSERT_EQ(J.GetElement(0, 0), 99);
}

TEST(Matrix_Tests, Test_of_equally_with_move)
{
	Matrix N(1, 1);
	N.SetElement(999, 0, 0);
	N = (Matrix &&)N; 
	ASSERT_EQ(N.GetElement(0, 0), 999);
	Matrix J(1, 1);
	J = (Matrix&&)N;
	ASSERT_EQ(J.GetElement(0, 0), 999);
}

TEST(Matrix_Tests, Test_of_operator_right_and_left_equal)
{
	Matrix N(1, 1);
	Matrix J(1, 1);
	Matrix K(2, 2);
	ASSERT_EQ(J == N, true);
	ASSERT_EQ(N == K, false);
}

TEST(Matrix_Tests, Test_of_index_of_row)
{
	Matrix N(2, 1);
	int* f_row = N[0];
	int* s_row = N[1];
	ASSERT_EQ(f_row, N[0]);
	ASSERT_EQ(s_row, N[1]);
}

TEST(Matrix_Tests, Test_of_operator_index)
{
	Matrix N(2, 2);
	N(1, 1) = 3;
	ASSERT_EQ(N.GetElement(1, 1), N(1, 1));
}

TEST(Matrix_Error_Tests, Test_of_operator_index_Error)
{
	Matrix N(2, 2);
	ASSERT_THROW(N(5,5), std::runtime_error);
}

TEST(Matrix_Tests, Test_of_Transposition_matrix)
{
	Matrix N(3, 2);
	N(0, 0) = 1; //   Matrix: 1 2
	N(0, 1) = 2; //           3 4
	N(1, 0) = 3; //           5 6
	N(1, 1) = 4; //  Transposition Matrix: 1 3 5
	N(2, 0) = 5; //                        2 4 6
	N(2, 1) = 6;
	Matrix A = N.Transposition();    
	for(int i = 0; i < 2; ++i)        
		for(int j = 0; j < 3; ++j)
			ASSERT_EQ(N(j,i),A(i,j));
}

TEST(Matrix_Tests, Input_from_file_Matrix)
{
	Matrix A(2, 3);
	A.FileInput("C:\\input.txt");   // Matrix in file: 99 99 99
	for (int i = 0; i < 2; ++i)     //                 99 99 99
		for (int j = 0; j < 3; ++j)
			ASSERT_EQ(A(i,j),99);
}
