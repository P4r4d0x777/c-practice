#include "pch.h"
#include "../Task5/Encryption.h"
#include <fstream>
// key size = 18.
TEST(TenNumberSystem_Encryption, key_is_18_symbols)
{
	const char inputfilename[] = "bomb.txt"; // Файл с входным текстом
	const char outputfilename[] = "defuse.txt"; // Файл с шифр текстом
	const char result[] = "AbcdIfgHijkLmnopqr"; // Какой шифр текст должен получиться
	const char key[19] = { 3, 13, 14, 6, 1,7,20,10,12,15,5,8,8,8,26,3,20,22,'\0' }; // Ключ
	char inputfile[19] = "BombHasBeenDefused"; // Исходный текст
	OutputArrayToFile(inputfile, 18, inputfilename); // Запись исходного текста в файла 
	Encryption(inputfilename, outputfilename, key); // Получение шифр текста
	// проверка записанного в файл текста
	std::ifstream fs(outputfilename, std::ios::binary); 
	char arr[19][1]; 
	fs.getline(arr[0], 19, '\0');
	ASSERT_STREQ(result,arr[0]);
}
// Проверяет циклинчность(key size = 3)
TEST(TenNumberSystem_Encryption, key_is_3_symbols)
{
	const char inputfilename[] = "bomb.txt";
	const char outputfilename[] = "defuse.txt";
	const char result[] = "agagagagagagagagag";
	const char key[19] = { 3, 5,'\0' };
	char inputfile[19] = "bbbbbbbbbbbbbbbbbb";
	OutputArrayToFile(inputfile, 18, inputfilename);
	Encryption(inputfilename, outputfilename, key);
	std::ifstream fs(outputfilename, std::ios::binary);
	char arr[19][1]; // транслит.
	fs.getline(arr[0], 19, '\0');
	ASSERT_STREQ(result, arr[0]);
}