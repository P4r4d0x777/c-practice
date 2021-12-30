#include "pch.h"
#include "../Task5/Encryption.h"
#include <fstream>
// key size = 18.
TEST(TenNumberSystem_Encryption, key_is_18_symbols)
{
	const char inputfilename[] = "bomb.txt"; // ���� � ������� �������
	const char outputfilename[] = "defuse.txt"; // ���� � ���� �������
	const char result[] = "AbcdIfgHijkLmnopqr"; // ����� ���� ����� ������ ����������
	const char key[19] = { 3, 13, 14, 6, 1,7,20,10,12,15,5,8,8,8,26,3,20,22,'\0' }; // ����
	char inputfile[19] = "BombHasBeenDefused"; // �������� �����
	OutputArrayToFile(inputfile, 18, inputfilename); // ������ ��������� ������ � ����� 
	Encryption(inputfilename, outputfilename, key); // ��������� ���� ������
	// �������� ����������� � ���� ������
	std::ifstream fs(outputfilename, std::ios::binary); 
	char arr[19][1]; 
	fs.getline(arr[0], 19, '\0');
	ASSERT_STREQ(result,arr[0]);
}
// ��������� ������������(key size = 3)
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
	char arr[19][1]; // ��������.
	fs.getline(arr[0], 19, '\0');
	ASSERT_STREQ(result, arr[0]);
}