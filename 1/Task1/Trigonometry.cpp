#include "pch.h"
#include "Trigonometry.h"
#include <cmath> 

float TrigonometryZ1(float z1)
{
	return  (sin(z1) + sin(5 * z1) - sin(3 * z1)) / (cos(z1) - cos(3 * z1) + cos(5 * z1));;
}

float TrigonometryZ2(float z2)
{
	return tan(3 * z2);
}