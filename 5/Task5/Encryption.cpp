#include "pch.h"
#include <fstream>
#include "Encryption.h"

void Encryption(const char* inputfile, const char* outputfile, const char* key)
{
	char ch;
	bool end = true;
	int i = 0;
	std::ifstream inputFile(inputfile, std::ios_base::binary);
	std::ofstream outputFile(outputfile, std::ios_base::binary);
	while (end)
	{
		ch = inputFile.get();
		if (!inputFile.eof())
		{
			outputFile.put(ch ^ (int)key[i]);
			i++;
			if (key[i] == '\0')
				i = 0;
		}
		else
			end = false;
	}
	inputFile.close();
	outputFile.close();
}
bool OutputArrayToStream(char* arr, size_t count, std::ostream& outStream)
{
	if (!outStream)
		return false;
	for (size_t i = 0; i < count; ++i)
		outStream << arr[i];
	return true;
}
bool OutputArrayToFile(char* arr, size_t count, const char* fileName)
{
	std::ofstream outFile(fileName); 
	if (!outFile)
		return false;
	return OutputArrayToStream(arr, count, outFile);
}