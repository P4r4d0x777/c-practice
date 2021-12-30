#include "pch.h"
#include "ÑhordMethod.h"
#include <cmath>
double ChordMehod(double (*fp) (double x), double a, double b, double epsilon)
{
    while (abs(b - a) > epsilon) 
    {
        a = b - (b - a) * fp(b) / (fp(b) - fp(a));
        b = a - (a - b) * fp(a) / (fp(a) - fp(b));
    }
    return b;
}