#include "pch.h"
#include "Inside.h"
#include <math.h>
bool Inside(float x, float y, float R)
{
	// �������� ��� pow
	if (y <= x && x <= 0 && y >= -R)//�����������
		return true;
	return pow(x, 2) + pow(y, 2) <= pow(R, 2) && y >= 0
	// ������ ����� return pow(x, 2) + pow(y, 2) <= pow(R, 2) && y >= 0;  ������ if/else
}