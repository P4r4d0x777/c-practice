#include "pch.h"
#include "Logic.h"

bool LogicF(bool a, bool b, bool c)
{
	return (!a | b) | !c;
}
bool LogicG(bool a, bool b, bool c)
{
	return !(a & !b) | !c;
}