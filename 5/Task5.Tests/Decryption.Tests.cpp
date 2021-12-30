#include "pch.h"
#include "../Task5/Decryption.h"
#include "../Task5/Encryption.h"
#include <fstream>
  
TEST(TenNumberSystem_Decryption, key_is_18_symbols)
{
	const char inputfilename[] = "bomb.txt"; // ���� � ���������� ����������� �������
	const char outputfilename[] = "defuse.txt"; // ���� � ������� ���� �������
	const char result[19] = "BombHasBeenDefused"; //�����  �������� ����� ������ ����������
	const char key[19] = { 3, 13, 14, 6, 1,7,20,10,12,15,5,8,8,8,26,3,20,22,'\0' }; // ����
	char inputfile[19] = "AbcdIfgHijkLmnopqr"; // �������� ���� �����
	OutputArrayToFile(inputfile, 18, outputfilename); // ������ ���� ������ � ����
	Decryption(outputfilename, inputfilename, key); // ��������� ��������� ������
	// �������� ����������� � ���� ������
	std::ifstream fs(inputfilename, std::ios::binary);
	char mass[19][1];
	fs.getline(mass[0], 19, '\0');
	ASSERT_STREQ(result, mass[0]);
}
// ��������� ������������(key size = 3)
TEST(TenNumberSystem_Decryption, key_is_3_symbols)
{
	const char inputfilename[] = "bomb.txt"; 
	const char outputfilename[] = "defuse.txt"; 
	const char result[19] = "bbbbbbbbbbbbbbbbbb";
	const char key[19] = { 3, 5,'\0' };  
	char inputfile[19] = "agagagagagagagagag"; 
	OutputArrayToFile(inputfile, 18, outputfilename); 
	Decryption(outputfilename, inputfilename, key);
	// �������� ����������� � ���� ������
	std::ifstream fs(inputfilename, std::ios::binary);
	char mass[19][1];
	fs.getline(mass[0], 19, '\0');
	ASSERT_STREQ(result, mass[0]);
}