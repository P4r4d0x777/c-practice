#include "Task5Api.hpp"
TASK5_API void Encryption(const char* inputfile, const char* outputfile, const char* key);
// ��� 2 ������� �� ����� ���������
// ��� ��� �� ��������, ��� ���������� ������ � ����
TASK5_API bool OutputArrayToStream(char* arr, size_t count, std::ostream& outStream);
TASK5_API bool OutputArrayToFile(char* arr, size_t count, const char* fileName);