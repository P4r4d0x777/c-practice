#include "pch.h" 
#include "../Task3/DotsOfMatrix.h"
#include "../Task3/io.h" // X������� ������ �������������� ������������� ������� � ����������� 
// � ������� ��� �����/������ � ������ ��� ��������� ���� 

// ��������������� ������� ������������ ������������ ������
// ��-��� ���������� ������������� �������
void DelDynamicArray2(double** dynamicArray2, size_t countOfRows)
{
	for (size_t i = 0; i < countOfRows; ++i)
		delete[] dynamicArray2[i];
	delete[] dynamicArray2;
}

TEST(Var4_�1_2_Tests, DotsExist)
{
	const double staticArr[3][4] =
	{
	{ 1.1, 2.2, 3.3 },
	{ 4.4, 5.5, 6.6 },
	{ 7.7, 8.8, 9.9 }
	};
	// � 1 -�� ������ ���������� ������ �����
	// � 2 -�� ������ ���������� ������ ��������
	double **result = new double* [2];
	for (size_t i = 0; i <2; ++i)
		result[i] = new double[1];
	result[0][0] = 3;
	result[1][0] = 1;
	// ����: (��������� ����� � �������� ���������� �� � 0, � � 1)
	// 3
	// 1
	const double **dynamicArr3 = new const double *[3];
	dynamicArr3[0] = staticArr[0];
	dynamicArr3[1] = staticArr[1];
	dynamicArr3[2] = staticArr[2];
	//double** dynamicArr2 = DynamicArray(&staticArr[0][0], 3, 4);
	//dynamicArr3 = dynamicArr2;
	// ���������� �������� ��������������� ������� � ����������, ������� ������ ���� ���������
	ASSERT_EQ(result[0][0], DotsOfMatrix(dynamicArr3, 3, 4)[0][0]);
	ASSERT_EQ(result[1][0], DotsOfMatrix(dynamicArr3, 3, 4)[1][0]);
	/*DelDynamicArray2(dynamicArr2, 3);*/
	DelDynamicArray2(result, 2);
}

