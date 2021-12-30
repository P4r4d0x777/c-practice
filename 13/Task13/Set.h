#pragma once
#include "pch.h"
// #include "Task13Api.hpp" - зачем, если вы ничего не экспортируете?
#include <exception>
#include <iostream>
using namespace std;


template <typename T>
class Set
{
public:
	Set() :_capacity(0), _size(0)
	{
		_dataPtr = nullptr;
	}
	Set(T* _dataPtr, size_t _capacity, size_t _size)
	{
		if (_capacity >= _size && sizeof(_dataPtr) == _size)
		{
			this->_capacity = _capacity; 
			this->_size = _size;
			_dataPtr = new T[_capacity];
			for (unsigned i = 0; i < _size; ++i)
			{
				this->_dataPtr[i] = _dataPtr[i];
			}
		}
		// кидайте более уместные исключения. Например, если не хотите свои создавать
		// то есть же invalid_argument, out_of_range. на крайний случай runtime_error
		else throw invalid_argument("InvalidArguments");
	}
	Set(size_t _capacity) :_capacity(_capacity), _size(0)
	{
		_dataPtr = new T[_capacity];
	}
	Set(const Set& other)
	{
		_dataPtr = new T[_capacity];
		for (unsigned i = 0; i < _size; ++i)
			_dataPtr[i] = other._dataPtr[i];
	}
	Set(Set&& other) noexcept : _capacity(other._capacity), _size(other._size), _dataPtr(other._dataPtr)
	{
		other._dataPtr = nullptr;
		other._capacity = 0;
		other._size = 0;
	}
	~Set()
	{
		delete[] _dataPtr;
	}
	void Add(T el)
	{
		if (_size + 1 >= _capacity)
			throw out_of_range("FullStack");
		_dataPtr[_size] = el;
		++_size;
	}
	template<typename L, typename K>
	bool Search(L el, K functor)
	{
		for (unsigned i = 0; i < _size;++i)
			if (functor(el, _dataPtr[i]))
				return true;
		return false;
	}
	Set& operator= (const Set& other)
	{
		if (this == &other)
			return *this;
		//check nullptr?
		delete[] _dataPtr;
		_capacity = other._capacity;
		_size = other._size;
		_dataPtr = new T[other._capacity];
		for (unsigned i = 0; i < _size; ++i)
			_dataPtr[i] = other._dataPtr[i];
		return *this;
	}
	Set& operator= (Set&& other)
	{
		if (this == &other)
			return *this;
		delete[] _dataPtr;
		_dataPtr = other._dataPtr; // утечка памяти, в _dataPtr же уже что-то было!
		_capacity = other._capacity;
		_size = other._size;
		other._dataPtr = nullptr;
		other._capacity = 0;
		other._size = 0;
	}
	Set operator+(const Set& other)
	{
		// что-то сложный метод. Что есть объединение множеств?
		// Все, что было в первом + все из второго, чего нет в первом. Память можно с запасом выделить, у вас как-то сложно все.
		// Если хотите впритык выделить, ну вызовите метод * и узнайте количество, вы здесь, получается, продублировали метод пересечения
		int equalElements = 0;
		size_t* indexOfEqualEl = nullptr;
		FunctionOfEqual(*this, other, equalElements);
		if (equalElements != 0) // всегда false
			indexOfEqualEl = new size_t[equalElements];
		int index = -1;
		for (unsigned i = 0; i < _size; ++i)
		{
			for (unsigned j = 0; j < other._size; ++j)
			{
				if (_dataPtr[i] == other._dataPtr[j])
				{
					index++;
					indexOfEqualEl[index] = i;
				}
				else continue;
			}
		}
		Set _union;
		_union._capacity = _size + other._size - equalElements; // �������� ����������� ����� ����� ���-�� ��������� � �����������
		_union._size = _size + other._size - equalElements;
		_union._dataPtr = new T[_union._capacity];
		int indexesOfUnion = -1;
		for (unsigned i = 0; i < _size + other._size; ++i)
		{
			if (i < _size && equalElements != 0) // всегда false
			{
				for (int j = 0; j < equalElements; ++j)
				{
					if (i == indexOfEqualEl[j])
						break;
					else if (j == equalElements - 1)
					{
						++indexesOfUnion;
						_union._dataPtr[indexesOfUnion] = _dataPtr[i];
					}
				}
			}
			if (i < _size && equalElements == 0)
			{
				++indexesOfUnion;
				_union._dataPtr[indexesOfUnion] = _dataPtr[i];
			}
			if (i >= _size)
			{
				++indexesOfUnion;
				_union._dataPtr[indexesOfUnion] = other._dataPtr[i - _size];
			}
		}
		return _union;
	}
	Set operator* (const Set& other)
	{
		Set crossing;
		crossing._dataPtr = nullptr;
		crossing._size = 0;
		// если это вынести, то во всех функциях пригодится
		FunctionOfEqual(*this, other, (int&)crossing._size);
		crossing._capacity = crossing._size;
		if (crossing._size != 0)
		{
			crossing._dataPtr = new T[_size];
			int index = -1;
			for (int i = 0; i < _size; ++i)
			{
				for (int j = 0; j < other._size; ++j)
				{
					if (_dataPtr[i] == other._dataPtr[j])
					{
						index++;
						crossing._dataPtr[index] = _dataPtr[i];
					}
				}
			}
		}
		return crossing;
	}
	Set operator-(const Set& other)
	{
		Set unionOf;
		size_t equalElements = 0;
		FunctionOfEqual(*this, other, (int&)unionOf._size);
		size_t indexesOfUnion = 0;
		unionOf._dataPtr = new T[equalElements];
		if (equalElements != 0)  // всегда false
		{
			for (unsigned i = 0; i < _size; ++i)
				for (unsigned j = 0; j < other._size; ++j)
					if (_dataPtr[i] == other._dataPtr[j]) { unionOf._dataPtr[indexesOfUnion] = i; indexesOfUnion++; }
		}
		Set minus;
		minus._size = 0;
		minus._capacity = _size - indexesOfUnion;
		minus._dataPtr = new T[_size - indexesOfUnion];
		if (equalElements == 0)
		{
			for (unsigned i = 0; i < _size; ++i)
			{
				minus._dataPtr[i] = _dataPtr[i];
				minus._size++;
			}
			return minus;
		}
		// никогда не выполнится
		size_t k = 0;
		for (unsigned i = 0; i < _size; ++i)
			for (unsigned j = 0; j < indexesOfUnion; ++j)
			{
				if (i == unionOf._dataPtr[j])
					break;
				else if (j == indexesOfUnion - 1)
				{
					minus._size++;
					minus._dataPtr[k] = _dataPtr[i];
					k++;
				}
			}
		return minus;

	}
	friend ostream& operator<<(ostream& output, const Set& arr)
	{
		unsigned current = 0;
		while (current != arr._size)
		{
			output << arr._dataPtr[current] << " ";
			current++;
		}
		output << "\n";
		return output;
	}
	friend istream& operator>>(istream& input, Set& arr)
	{
		unsigned current = 0;
		while (current != arr._capacity)
		{
			arr._size++;
			input >> arr._dataPtr[current];
			current++;
		}
		return input;
	}
	friend void FunctionOfEqual(const Set<T>& obj1, const Set<T>& obj2, int& size)
	{
		for (int i = 0; i < obj1._size; ++i)
			for (int j = 0; j < obj2._size; ++j)
				if (obj1._dataPtr[i] == obj2._dataPtr[j])
					size++;
	}
private:
	T* _dataPtr;
	size_t _capacity;
	size_t _size;
};
