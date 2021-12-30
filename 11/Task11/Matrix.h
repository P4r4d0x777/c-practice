
#pragma once
#include "MatrixApi.h"

class Matrix
{ // { переносить на новую строку
	// В ++ принято private-область в конце, то есть и эту дружественную функцию стоит объявить ниже
	// Здесь названия other1/other2 не совсем удачные. В НЕдруежственных функциях, где второй аргумент этого же типа это уместно,
	// там есть неявный this (то есть "этот") и аргумент ("другой"), в случае явного указания аргументов одинаковых типов лучше называть first/second
	// Или в случае арифметических операций можно переводить названия (первоеСлагаемое, второеСлагаемое, делимое, делитель и т.д.)
public:
	// new лишнее. Просто rows/columns или rowsCount/columnsCount. Аргументы называть со строчной буквы
	MATRIX_API Matrix(size_t rows, size_t columns);
	// не хватает конструктора перемещения
	MATRIX_API Matrix(const Matrix& other);
	MATRIX_API Matrix(Matrix&& other) noexcept;
	MATRIX_API ~Matrix();
	MATRIX_API Matrix& operator=(const Matrix& other);
	MATRIX_API Matrix& operator =(Matrix&& other);
	// не хватает оператора присванивания с перемещением
	// Это уже субъективно, но я бы назвал просто row/column. Вспомните алгебру, вы когда индексируете матрицу,
	// говорите просто i-ая СТРОКА, j-ый СТОЛБЕЦ, а не i-ая координата столбца. Можно не исправлять, но я бы сделал так.
	MATRIX_API int GetElement(size_t row, size_t column); // column. Или вы одну буквы решили сэкономить.
	// То же самое
	MATRIX_API void SetElement(int value, size_t row, size_t column);
	MATRIX_API bool operator==(const Matrix& right) const;
	MATRIX_API int* operator[](const int index) const;
	MATRIX_API int& operator()(size_t row, size_t column);
	MATRIX_API Matrix Transposition() const;
	MATRIX_API void FileInput(const char* location);
	
	MATRIX_API friend Matrix operator+(const Matrix& first, const Matrix& second);
private:
	int** _data; // призываю в таких случаях, когда в классе есть очевидно "главное" свойство, которое что-то хранит, называть его _data.
	size_t _rows;
	size_t _colums; // columns
	// Объявление лучше после всех методов, но ДО полей
};

// Балл не повысился, потому что я сначала не то задание залил, лучше стало, но с учетом обновленного задания оценка такая.