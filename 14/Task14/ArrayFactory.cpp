#include "pch.h"
#include <map>
#include "IChangeArray.cpp"

typedef  IChangeArray* (*Loader)(std::ifstream& stream);

struct ArrayFactory
{
	void RegisterLoader(const std::string& typeName, Loader loader)
	{
		_registered[typeName] = loader;
	}

	Loader GetLoader(const std::string& typeName)
	{
		if (_registered.find(typeName) == _registered.end())
			throw std::runtime_error("Illegal type!");
		return _registered[typeName];
	}

	static ArrayFactory& GetInstance()
	{
		static ArrayFactory soleInstance;

		return soleInstance;
	}
private:
	std::map<std::string, Loader> _registered;
};