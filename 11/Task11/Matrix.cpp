#pragma once
#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include <fstream>
using namespace std;

Matrix::Matrix(size_t rows, size_t columns) : _rows(rows), _colums(columns)
{
    _data = new int* [_rows];
    cout << "Call of basic constructor " << this << endl;
    for (int i = 0; i < _rows; ++i)
    {
        _data[i] = new int[_colums];
        for (int j = 0; j < _colums; ++j)
            _data[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& other) : _rows(other._rows), _colums(other._colums)
{
    cout << "Call of copying constructor " << endl;
    _data = new int* [_rows];
    for (int i = 0; i < _rows; ++i)
    {
        _data[i] = new int[_colums];
        for (int j = 0; j < _colums; ++j)
            _data[i][j] = other._data[i][j];
    }
}

Matrix::~Matrix()
{
    delete[] _data;
    cout << "Call of destructor " << this << endl;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this == &other)
        return *this;
    delete[] _data;
    _data = new int* [_rows];
    for (int i = 0; i < _rows; ++i)
    {
        _data[i] = new int[_colums];
        for (int j = 0; j < _colums; ++j)
            _data[i][j] = other._data[i][j];
    }
    return *this;
}

Matrix operator+(const Matrix& first, const Matrix& second)
{
    if (first._colums != second._colums || first._rows != second._rows)
        throw std::runtime_error("Matrix sizes are not equal "); // вы кидаете исключение типа string, а нужно std::runtime_error
    // то есть так: throw std::runtime_error("Matrix sizes are not equal"); (строковый параметр необязателен, но лучше его оставить)
    Matrix sum(first._rows, first._colums);
    for (int i = 0; i < first._rows; ++i)
        for (int j = 0; j < first._colums; ++j)
            sum._data[i][j] = first._data[i][j] + second._data[i][j];
    return sum;
}

int Matrix::GetElement(size_t row, size_t column) {
    if (column > this->_colums || row > this->_rows)
        throw std::exception("There is no such position ");
    return this->_data[row][column];

}

void Matrix::SetElement(int value, size_t row, size_t column)
{
    try {
        if (column > this->_colums || row > this->_rows)
            throw "There is no such position ";
        _data[row][column] = value;
    }
    catch (const char* e) {
        cout << e << endl;
    }
}

Matrix::Matrix(Matrix&& other) noexcept : _rows(other._rows), _colums(other._colums), _data(other._data)
{
    other._data = nullptr;
    other._colums = 0;
    other._rows = 0;
}

Matrix& Matrix::operator=(Matrix&& other)
{
    if (&other == this)
        return *this;
    _rows = other._rows;
    _colums = other._colums;
    _data = other._data;
    other._data = nullptr;
    other._colums = 0;
    other._rows = 0;
    return *this;
}

bool Matrix::operator==(const Matrix& right) const
{
    if (right._colums == _colums && right._rows == _rows)
    {
        for (int i = 0; i < _rows; ++i)
            for (int j = 0; j < _colums; ++j)
            {
                if (_data[i][j] == right._data[i][j])
                    continue;
                else
                    return false;
            }
        return true;
    }
    else
        return false;
}

int* Matrix::operator[](const int index) const
{
    return _data[index];
}

int& Matrix::operator()(size_t row, size_t column)
{
    if (row > _rows || column > _colums)
        throw std::runtime_error("a runtime error");
    return _data[row][column];
}

Matrix Matrix::Transposition() const
{
    Matrix transpObj(_colums, _rows);
    //reverse
    transpObj._data = new int* [_colums];
    for (int i = 0; i < _colums; ++i)
        transpObj._data[i] = new int[_rows];
    for (int i = 0; i < _rows; ++i)
        for (int j = 0; j < _colums; ++j)
            transpObj._data[j][i] = _data[i][j];
    return transpObj;
}

void Matrix::FileInput(const char* location)
{
    ifstream in(location);
    if (in.is_open())
    {
        int count = -1;
        int temp;
        while (!in.eof())
        {
            in >> temp;
            count++;
        }
        in.clear();
        in.seekg(0);
        int count_space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        in.clear();
        in.seekg(0);
        int n = count / (count_space + 1);
        int m = count_space + 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                in >> _data[i][j];
        in.close();
    }
    else
    {
        throw std::exception("No file in this location");
    }
}
