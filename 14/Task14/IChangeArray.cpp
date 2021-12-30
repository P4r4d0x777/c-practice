#include "pch.h"
#include <fstream>
// А как у вас ОБЪЯВЛЕНИЕ оказалось в cpp файле?
class IChangeArray
{
public:
	virtual ~IChangeArray() {};
	virtual void Sort() = 0;
	virtual void ElementProcessing() = 0;
	virtual void Save(std::ostream& stream) = 0;
};