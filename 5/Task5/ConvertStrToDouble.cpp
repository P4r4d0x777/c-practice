#include "pch.h"
#include <iostream>
#include <math.h>
#include "ConvertStrToDouble.h"  
const int CountOfInteger(const char* str)
{
    int i = 0;
    int j = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        ++j;
    }
    while (str[j] != '\0' && str[j] != '.')
    {
        i++;
        ++j;
    }
    const int  l = i;
    return l;
}
double FifthToDEC(char* str, size_t numbersystem)
{
    int k;
    double ResultOfConvert = 0;
    int length = strlen(str) - 1;
    int maxDegree = 1;
    for (int i = 0; i < length; i++)
    {
        maxDegree *= numbersystem;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        k = 0;
        while (alphabet[k] != str[i])
            ++k;
        ResultOfConvert += k * maxDegree;
        maxDegree /= numbersystem;
        length--;
    }
    return ResultOfConvert;
}
double ConvertToDouble(const char* str, size_t ss)
{
    int k = 0; // длина всей строки
    bool flag = true; // отвечает за знак 
    bool nodigitfrac = false;
    bool nodigitint = false;
    if (str[0] == '-')
        flag = false;
    while (str[k] != '\0')
    {
        k++;
    }
    int i = 0, j = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    char* integer = new char[CountOfInteger(str) + 1]; // целая чать
    if (CountOfInteger(str) + 1 == k)
        nodigitfrac = true;
    if (CountOfInteger(str) + 1 + k == k)
        nodigitint = true;
    char* fractional = new char[k - CountOfInteger(str) - i];   // дробная часть
    integer[CountOfInteger(str)] = '\0';
    fractional[k - CountOfInteger(str) - 1 - i] = '\0';
    while (str[i] != '\0')
    {
        if (str[i] == '.')
            break;
        else
        {
            integer[j] = str[i];
            i++;
            j++;
        }
    }
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            i++;
        }
        fractional[j] = str[i];
        j++;
        i++;
    }
    double m, n;
    if (nodigitint == false)
        m = FifthToDEC(integer, ss);
    else
        m = 0;
    if (nodigitfrac == false)
        n = FifthToDEC(fractional, ss);
    else
        n = 0;
    if (flag == true)
        return m + n / pow(10, j);
    return -(m + n / pow(10, j));
}