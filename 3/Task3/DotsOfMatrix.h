#include "Task3Api.hpp"
TASK3_API double** DotsOfMatrix(const double** arr, size_t countOfRows, size_t countOfColomns);
// ������� ������������ �������� � ������
TASK3_API double MaxOfColomns(const double** arr, size_t count, int row);
// ������� ����������� �������� � ������
TASK3_API double MinOfRows(const double** arr, size_t count, int row);
// ������� ��������� ������ ��� �������������� ���������� ������������� �������
TASK3_API double** CreateDoubleArray(size_t countOfRows, size_t countOfColomns);