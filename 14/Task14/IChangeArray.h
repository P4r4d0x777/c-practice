#pragma once
#include <math.h>
#include <string>
#include <vector>
#include "ArrayFactory.cpp"
typedef unsigned int UINT;

// Все равно не доделали, каждый класс в своЙ *.h
template <typename T>
class Bubble : public IChangeArray
{
public:

	~Bubble()
	{
		delete[] _data;
	}

	Bubble() :_size(5)
	{
		_data = new T[_size];
		// UINT - вы так язык C любите?
		for (UINT i = 0; i < _size; ++i)
			_data[i] = rand() % 100 + 1;
	}

	Bubble(T* data, size_t size)
	{
		_size = size;
		if (size <= 0)
			throw std::invalid_argument("Size must be > 0");
		_data = new T[size];
		for (UINT i = 0; i < size; ++i)
			_data[i] = data[i];
	}

	T& operator[](size_t i)
	{
		if (i >= _size)
			throw std::invalid_argument("Bad index");
		return *(_data + i);
	}

	size_t length() const
	{
		return _size;
	}

	virtual void Sort() override
	{
		for (UINT i = 1; i < _size; ++i)
			for (UINT j = 0; j < _size - i; ++j)
				if (_data[j] < _data[j + 1])
				{
					T temp = _data[j];
					_data[j] = _data[j + 1];
					_data[j + 1] = temp;
				}
	}

	virtual void ElementProcessing() override
	{
		for (UINT i = 0; i < _size; ++i)
			_data[i] = sqrt(_data[i]);
	}

	static IChangeArray* Load(std::ifstream& stream)
	{
		int* data = NULL;
		size_t size = 0;
		int symb = -1;

		stream >> symb;
		size = symb;
		data = new int[size];

		for (UINT i = 0; i < size; ++i)
			data[i] = symb;

		return new Bubble<int>(data, size);
	}

	void Save(std::ostream& stream) override
	{
		stream << "Bubble ";
		stream << _size << "   ";
		for (UINT i = 0; i < _size; i++)
			i == _size - 1 ? stream << _data[i] << "" : stream << _data[i] << " ";
		stream << "\n";
	}
private:
	T* _data;
	size_t _size;
};

template <typename T>
class Choice : public IChangeArray
{
public:

	~Choice()
	{
		delete[] _data;
	}

	Choice() :_size(5)
	{
		_data = new T[_size];
		for (UINT i = 0; i < _size; ++i)
			_data[i] = rand() % 100 + 1;
	}

	Choice(T* data, size_t size)
	{
		_size = size;
		if (size <= 0)
			throw std::invalid_argument("Size must be > 0");
		_data = new T[size];
		for (UINT i = 0; i < size; ++i)
			_data[i] = data[i];
	}

	T& operator[](size_t i)
	{
		if (i >= _size)
			throw std::invalid_argument("Bad index");
		return *(_data + i);
	}

	size_t length() const
	{
		return _size;
	}

	virtual void Sort() override
	{
		for (UINT i = 0; i < _size; i++)
			for (UINT j = i + 1; j < _size; j++)
				if (_data[i] > _data[j])
				{
					T temp = _data[i];
					_data[i] = _data[j];
					_data[j] = temp;
				}
	}

	virtual void ElementProcessing() override
	{
		for (UINT i = 0; i < _size; ++i)
			_data[i] = log(_data[i]);
	}

	static IChangeArray* Load(std::ifstream& stream)
	{
		int* data = NULL;
		size_t size = 0;
		int symb = -1;

		stream >> symb;
		size = symb;
		data = new int[size];

		for (UINT i = 0; i < size; ++i)
			data[i] = symb;

		return new Choice<int>(data, size);
	}

	void Save(std::ostream& stream) override
	{
		stream << "Choice ";
		stream << _size << "   ";
		for (UINT i = 0; i < _size; i++)
			i == _size - 1 ? stream << _data[i] << "" : stream << _data[i] << " ";
		stream << std::endl;
	}
private:
	T* _data;
	size_t _size;
};

template <typename T>
void RegisterLoaders()
{
	ArrayFactory::GetInstance().RegisterLoader("Bubble", Bubble<T>::Load);
	ArrayFactory::GetInstance().RegisterLoader("Choice", Choice<T>::Load);
}

void Save(std::ostream& stream, IChangeArray** bases, size_t count)
{
	for (size_t i = 0; i < count; ++i)
		bases[i]->Save(stream);
}

std::vector<IChangeArray*> Load(std::ifstream& stream)
{
	std::vector<IChangeArray*> result;
	std::string typeName = "";
	std::string word;
	while (!stream.eof())
	{
		stream >> word;
		// не, читайте целиком название типа, а если я попрошу еще 1 класс добавить, который тоже начинается на 'C'?
		if (word=="Choice")
		{
			typeName = "Choice";
			IChangeArray* base = ArrayFactory::GetInstance().GetLoader(typeName)(stream);
			result.push_back(base);
		}
		if (word == "Bubble")
		{
			typeName = "Bubble";
			IChangeArray* base = ArrayFactory::GetInstance().GetLoader(typeName)(stream);
			result.push_back(base);
		}
	}
	return result;
}
bool Save(const char* fileName, IChangeArray** objects, size_t size)
{
	std::ofstream outFile(fileName);
	if (!outFile)
		return false;

	Save(outFile, objects, size);

	for (size_t i = 0; i < size; ++i)
		delete objects[i];

	return true;
}
std::vector<IChangeArray*> Load(const char* fileName)
{
	std::ifstream inFile(fileName);
	if (!inFile)
		throw std::runtime_error("Cannot open file!");

	auto objects = Load(inFile);

	return objects;
}