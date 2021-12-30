#include "pch.h"
#include "OverloadDivision.h"
double Division(double a, double b)
{
	return a / b;
}
ComplexNumber Division(ComplexNumber a, ComplexNumber b)
{
	ComplexNumber res;
	res.integer = (a.integer * b.integer + a.imaginary * b.imaginary) / (pow(b.integer, 2) + pow(b.imaginary, 2));
	res.imaginary = (b.integer * a.imaginary - a.integer * b.imaginary) / (pow(b.integer, 2) + pow(b.imaginary, 2));
	return res;
}
double Division(std::string a, std::string b)
{
	return std::stoi(a) / std::stoi(b);
}