#pragma once
#include <math.h>
#include <string>
template <int row, typename T>
void ChangeElements(T  (&arr)[row]) {
	T min = arr[0];
	for (int i = 1 ; i < row;i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	for (int i = 0; i < row;i++)
	{
		arr[i] += sqrt(abs(min));
	}
}
template <typename T>
T Maximum(T* arr, size_t size){
	T max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
template<>
const char* Maximum<const char*>(const char** arr, size_t size){
	char* max = const_cast<char*>(arr[0]);
	for (int i = 0;i < size;i++)
	{
		if (strcmp(arr[i],max) > 0)
			max = const_cast<char*>(arr[i]);
	}
	return max;
}
template <typename T>
T Sum(T *arr, size_t size) {
	T sum = 0;
	for (int i = 0; i < size;i++)
		sum += arr[i];
	return sum;
}
int SumOfString(const char* arr)
{
	int sumOfElements = 0;
	while (*arr)
	{
		sumOfElements++;
		arr++;
	}
	return sumOfElements;
}
// ну так вы просто стерли мой комментарий

//там так было, я стёр template<>
// template<> // это не нужно, функции не предусматривают частичной специализации, так что просто
// пишете как бы "обычную" функцию, и тогда это и будет считаться полной специализацией
// Частично согласен, но const char* Sum<const char*>(const char** arr, size_t size) { должно было превратиться в const char* Sum(const char** arr, size_t size) {
const char* Sum<const char*>(const char** arr, size_t size) {
	int *count = new int[size];
	for (int i = 0; i < size;i++) {
		count[i] = SumOfString(arr[i]);
	}
	size_t sum = 0;
	for (int i = 0; i < size;i++) {
		sum += count[i];
	}
	char* res = new char[sum+(size_t)1];
	res[sum] = '\0';
	int index = 0;
	int indexForRes = 0;
	for (int i = 0; i < size;i++) {
		while (*arr[i]) {
			res[indexForRes] = *arr[index];
			indexForRes++;
			arr[i]++;
		}
		index++;
	}
	delete[] count;
	return res;
}
template <typename T>
T* ChangeArr(T* arr, size_t size) {
	T* newArr = new T[size+2];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	newArr[size] = Maximum(arr, size);
	newArr[size + 1] = Sum(arr, size);
	delete[] arr;
	return newArr;
}