#include "pch.h"
#include <fstream>
#include "Decryption.h"
#include "Encryption.h"

void Decryption(const char* inputfile, const char* outputfile, const char* key)
{
	// просто вызвать внутри функцию шифрования. Они же одинаковые
	Encryption(inputfile, outputfile, key);
}