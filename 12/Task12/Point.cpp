#pragma once
#include "pch.h"
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;
size_t Point::count = 0;
void Cartesian(char* _data)
{
	strcpy(_data, "Cartesian");
}
void Polar(char* _data)
{
	strcpy(_data, "Polar");
}

Point::Point()
{
	coords.coordsOfCart.x = 1;
	coords.coordsOfCart.y = 1;
	Cartesian(_data);
	count++;
}
Point::Point(float firstCoord, float secondCoord, const char* nameOfSystem)
{
	coords.coordsOfCart.x = firstCoord;
	coords.coordsOfCart.y = secondCoord;
	// Сравнивать целиком со строкой, использовать strcmp
	// еще раз: использовать strcmp. ЗАчем тут тратить ресурсы на создание объектов типа std::string только ради сравнения?
	if (!strcmp(nameOfSystem, "Cartesian"))
	{
		Cartesian(_data);
		count++;
	}
	else if (!strcmp(nameOfSystem, "Polar"))
	{
		Polar(_data);
		count++;
	}
	else
		throw runtime_error("Wrond name of a system, you can use only : C (Cartesian), P (Polar)");
}

Point::Point(const Point& other)
{
	if (!strcmp(other._data, "Cartesian"))
	{
		Cartesian(_data);
		coords.coordsOfCart.x = other.coords.coordsOfCart.x;
		coords.coordsOfCart.y = other.coords.coordsOfCart.y;
	}
	else
	{
		Polar(_data);
		coords.coordsOfPolar.r = other.coords.coordsOfPolar.r;
		coords.coordsOfPolar.polarAngle = other.coords.coordsOfPolar.polarAngle;
	}
	// Ну вы либо крест снимите, либо трусы наденьте.
	// Если решили сделать if/else, то и координаты там копируйте
	// Или уж копируйте так, но и _data тогда тоже просто у other возьмите
	count++;
}

Point::Point(Point&& other) noexcept
{
	(!strcmp(other._data, "Cartesian")) ? Cartesian(_data) : Polar(_data);
	coords.coordsOfCart.x = other.coords.coordsOfCart.x;
	coords.coordsOfCart.y = other.coords.coordsOfCart.y;
	other.coords.coordsOfCart.x = 0;
	other.coords.coordsOfCart.y = 0;
	count++;
}

Point::~Point()
{
	count--;
}

void Point::SetX(float x)
{
	if(!strcmp(_data, "Cartesian"))
		coords.coordsOfCart.x = x;
	else throw invalid_argument("Dot must be in Cartesian system");
}

void Point::SetY(float y)
{
	if (!strcmp(_data, "Cartesian"))
		coords.coordsOfCart.y = y;
	else throw invalid_argument("Dot must be in Cartesian system");
}

void Point::SetR(float r)
{
	if (!strcmp(_data, "Polar"))
		coords.coordsOfPolar.r = r;
	else throw invalid_argument("Dot must be in Polar system");
}

void Point::SetPolarAngle(float polarAngle)
{
	if (!strcmp(_data, "Polar"))
		coords.coordsOfPolar.polarAngle = polarAngle;
	else throw invalid_argument("Dot must be in Polar system");
}

float Point::GetX()
{
	if (!strcmp(_data, "Cartesian"))
		return coords.coordsOfCart.x;
	else
		throw invalid_argument("Dot must be in Cartesian system");
}

float Point::GetY()
{
	if (!strcmp(_data, "Cartesian"))
		return coords.coordsOfCart.y;
	else
		throw invalid_argument("Dot must be in Cartesian system");
}

float Point::GetR()
{
	if (!strcmp(_data, "Polar"))
		return coords.coordsOfPolar.r;
	else
		throw invalid_argument("Dot must be in Polar system");
}

float Point::GetPolarAngle()
{
	if (!strcmp(_data, "Polar"))
		return coords.coordsOfPolar.polarAngle;
	else
		throw invalid_argument("Dot must be in Polar system");
}
// раз const метод, верните const char*
const char* Point::GetNameOfCoords() const
{
	return _data;
}

void Point::ConvertToPolar()
{
	// У вас много где такая проверка. Либо сравнивайте всю строку, либо, что проще - заведите enum/bool и его проверяйте
	if (!strcmp(_data, "Cartesian"))
	{
		Polar(_data);
		float a = coords.coordsOfCart.x;
		float b = coords.coordsOfCart.y;
		coords.coordsOfPolar.r = sqrt(pow(a, 2) + pow(b, 2));
		coords.coordsOfPolar.polarAngle = atan(b / a);
	}
}

void Point::ConvertToCartesian()
{
	// аналогично
	if(!strcmp(_data, "Polar"))
	{
		Cartesian(_data);
		float a = coords.coordsOfPolar.r;
		float b = coords.coordsOfPolar.polarAngle;
		coords.coordsOfCart.x = a * cos(coords.coordsOfPolar.polarAngle);
		coords.coordsOfCart.y = a * sin(coords.coordsOfPolar.polarAngle);
	}
}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	if (!strcmp(other._data, "Cartesian"))
		Cartesian(_data);
	else
		Polar(_data);
	coords.coordsOfCart.x = other.coords.coordsOfCart.x;
	coords.coordsOfCart.y = other.coords.coordsOfCart.y;
	count++;
	return *this;
}
Point& Point::operator=(Point&& other)
{
	if (&other == this)
		return *this;
	if (!strcmp(other._data, "Cartesian"))
		Cartesian(_data);
	else
		Polar(_data);
	coords.coordsOfCart.x = other.coords.coordsOfCart.x;
	coords.coordsOfCart.y = other.coords.coordsOfCart.y;
	other.coords.coordsOfCart.x = 0;
	other.coords.coordsOfCart.y = 0;
	count++;
	return *this;
}

void Point::MoveX(float x)
{
	if (strcmp(_data, "Polar"))
	{
		coords.coordsOfCart.x += x;
	}
	else cout << "Need convert dot in Cartesian, to do this method";
}

void Point::MoveY(float y)
{
	if (strcmp(_data, "Polar"))
	{
		coords.coordsOfCart.y += y;
	}
	else cout << "Need convert dot in Cartesian, to do this method";
}

int Point::getCount()
{
	return count;
}

float operator-(const Point& first, const Point& second)
{
	float distance = NULL;
	if (strcmp(first._data, second._data))
		throw invalid_argument("Dots must be represented in the same coordinate system");
	if (!strcmp(first._data, "Polar"))
	{
		// если возведение в квадрат, то обходиться без pow - просто умножать
		distance = sqrt((first.coords.coordsOfPolar.r * first.coords.coordsOfPolar.r) + (second.coords.coordsOfPolar.r * second.coords.coordsOfPolar.r) - 2 * (first.coords.coordsOfPolar.r * second.coords.coordsOfPolar.r * acos(first.coords.coordsOfPolar.polarAngle - second.coords.coordsOfPolar.polarAngle)));
	}
	else
	{
		distance = sqrt((first.coords.coordsOfCart.x - second.coords.coordsOfCart.x) * (first.coords.coordsOfCart.x - second.coords.coordsOfCart.x) + (first.coords.coordsOfCart.y - second.coords.coordsOfCart.y) * (first.coords.coordsOfCart.y - second.coords.coordsOfCart.y));
	}
	return distance;
}

bool Point::operator==(const Point& right) const
{
	// нельзя так сравнивать double
	// И так тоже нельзя, почему именно с точностью 0.0000001? Есть выделенная для типа double точность -  DBL_EPSILON
	if (right.coords.coordsOfCart.x - coords.coordsOfCart.x < .0000001 && right.coords.coordsOfCart.y - coords.coordsOfCart.y < .0000001)
		return true;
	return false;
	// Вы злой какой-то. Сравните все равно, пространство-то одно, и две точки, даже если представлены в разных координатах, имеют право совпадать
}


std::ostream& operator<< (std::ostream& out, const Point& p)
{
	if (!strcmp(p._data, "Cartesian"))
		out << "(Cart)Point(" << p.coords.coordsOfCart.x << "," << p.coords.coordsOfCart.y << ")";
	else
		out << "(Polar)Point(" << p.coords.coordsOfPolar.r << "," << p.coords.coordsOfPolar.polarAngle << ")";
	return out;
}

std::istream& operator>> (std::istream& in, Point& p)
{
	char system[10];
	in >> system;
	if (!strcmp("Cartesian", system))
	{
		Cartesian(p._data);
		in >> p.coords.coordsOfCart.x;
		in >> p.coords.coordsOfCart.y;
	}
	else if (!strcmp("Polar", system))
	{
		Polar(p._data);
		in >> p.coords.coordsOfPolar.r;
		in >> p.coords.coordsOfPolar.polarAngle;
	}
	else
		throw runtime_error("Wrond name of a system, you can use only : C (Cartesian), P (Polar)");
	return in;
}