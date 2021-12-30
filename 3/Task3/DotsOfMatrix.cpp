#include "pch.h"
#include "DotsOfMatrix.h"
                   // const double**, ����� � ��� ��������
double** DotsOfMatrix(const double** arr, size_t countOfRows, size_t countOfColomns)
{
    int str; int clm;
    int c = 0;
    double** matrix= CreateDoubleArray(2,1);
    for (int i = 0; i < countOfRows; i++)
    {
        for (int j = 0; j < countOfColomns; j++)
        {
            if (MaxOfColomns(arr, countOfRows, j) == MinOfRows(arr, countOfRows, i))
            {
                // ���-�� ����� = const, ��������� ������ �������
                matrix = CreateDoubleArray(2, c + 1); 
                // � 1-�� ������ ��������� ������ �����, �� 2-�� ������ ��������
                matrix[0][c] = i+1;
                matrix[1][c] = j + 1;
                c++;// ��� �� � ��� ���� ����������. ���� ��� � ����� > 0, ������ ����� ����� ����, flag ��� ������ �� �����
            }
        }
    }
    if(c>0)
        return matrix;
    else
    {
        double** matrix = CreateDoubleArray(1, 1);
        matrix[0][0] = -1; // ���� ����� ��� �� � ������� ����� ���������� ������������ ������� = -1
        return matrix;
    }
}


// ������� ����������� �������� � ������
double MinOfRows(const double** arr, size_t count, int row)
{
    double minOfRows;
    minOfRows = arr[row][0];
    for (int i = 1; i < count; i++)
    {
        if (arr[row][i] < minOfRows)
        {
            minOfRows = arr[row][i];
        }
    }
    return minOfRows;
}
// ������� ������������ �������� � ������
double MaxOfColomns(const double** arr, size_t count, int row)
{
    double maxOfColomns;
    maxOfColomns = arr[0][row];
    for (int j = 1; j < count; j++)
    {
        if (arr[j][row] > maxOfColomns)
        {
            maxOfColomns = arr[j][row];
        }
    }
    return maxOfColomns;
}

// ������� ��������� ������ ��� �������������� ���������� ������������� �������
double** CreateDoubleArray(size_t countOfRows, size_t countOfColomns)
{
    // ��������� ������ ��� ���������������� ������� ���������� �� ������
    double** arr2 = new double* [countOfRows]; // (1)
    // ��������� ������ ��� ����� �������
    for (size_t i = 0; i < countOfRows; ++i) // (2)
        arr2[i] = new double[countOfColomns]; // (3)
    return arr2;
}