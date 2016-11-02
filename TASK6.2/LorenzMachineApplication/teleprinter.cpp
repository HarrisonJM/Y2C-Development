#include "stdafx.h"
#include "teleprinter.h"
#include <map>
using std::map;

teleprinter::teleprinter(lorenzMachine encryptor)
{
	this->encryptor = encryptor;

	charToBaudot['*'] = 0x00; // 00000 NULL
	charToBaudot['E'] = 0x01; // 00001 //BUG FIX 6
	charToBaudot['-'] = 0x02; // 00010 LF
	charToBaudot['A'] = 0x03; // 00011
	charToBaudot[' '] = 0x04; // 00100 SPACE
	charToBaudot['S'] = 0x05; // 00101
	charToBaudot['I'] = 0x06; // 00110
	charToBaudot['U'] = 0x07; // 00111
	charToBaudot[','] = 0x08; // 01000 CR
	charToBaudot['D'] = 0x09; // 01001	
	charToBaudot['R'] = 0x0a; // 01010	
	charToBaudot['J'] = 0x0b; // 01011
	charToBaudot['N'] = 0x0c; // 01100
	charToBaudot['F'] = 0x0d; // 01101
	charToBaudot['C'] = 0x0e; // 01110
	charToBaudot['K'] = 0x0f; // 01111
	charToBaudot['T'] = 0x10; // 10000
	charToBaudot['B'] = 0x19; // 11001
	charToBaudot['G'] = 0x1a; // 11010
	charToBaudot['H'] = 0x14; // 10100
	charToBaudot['L'] = 0x12; // 10010
	charToBaudot['M'] = 0x1c; // 11100	
	charToBaudot['O'] = 0x18; // 11000
	charToBaudot['P'] = 0x16; // 10110
	charToBaudot['Q'] = 0x17; // 10111		
	charToBaudot['V'] = 0x1e; // 11110
	charToBaudot['W'] = 0x13; // 10011
	charToBaudot['X'] = 0x1d; // 11101
	charToBaudot['Y'] = 0x15; // 10101
	charToBaudot['Z'] = 0x11; // 10001
	charToBaudot['!'] = 0x1b; // 11011 Shift to figures
	charToBaudot['.'] = 0x1f; // 11111 Shift to letters

	//baudotToChar[0x03] = 'A'; // 00011
	//baudotToChar[0x19] = 'B'; // 11001
	//baudotToChar[0x0e] = 'C'; // 01110
	//baudotToChar[0x09] = 'D'; // 01001
	//baudotToChar[0x01] = 'E'; // 00001
	//baudotToChar[0x0d] = 'F'; // 01101
	//baudotToChar[0x1a] = 'G'; // 11010
	//baudotToChar[0x14] = 'H'; // 10100
	//baudotToChar[0x06] = 'I'; // 00110
	//baudotToChar[0x0b] = 'J'; // 01011
	//baudotToChar[0x0f] = 'K'; // 01111
	//baudotToChar[0x12] = 'L'; // 10010
	//baudotToChar[0x1c] = 'M'; // 11100
	//baudotToChar[0x0c] = 'N'; // 01100
	//baudotToChar[0x18] = 'O'; // 11000
	//baudotToChar[0x16] = 'P'; // 10110
	//baudotToChar[0x17] = 'Q'; // 10111
	//baudotToChar[0x0a] = 'R'; // 01010
	//baudotToChar[0x05] = 'S'; // 00101
	//baudotToChar[0x10] = 'T'; // 10000
	//baudotToChar[0x07] = 'U'; // 00111
	//baudotToChar[0x1e] = 'V'; // 11110
	//baudotToChar[0x13] = 'W'; // 10011
	//baudotToChar[0x1d] = 'X'; // 11101
	//baudotToChar[0x15] = 'Y'; // 10101
	//baudotToChar[0x11] = 'Z'; // 10001
	//baudotToChar[0x04] = ' '; // 00100 SPACE
	//baudotToChar[0x00] = '*'; // 00000 NULL
	//baudotToChar[0x08] = ','; // 01000 CR
	//baudotToChar[0x02] = '-'; // 00010 LF
	//baudotToChar[0x1b] = '!'; // 11011 Shift to figures
	//baudotToChar[0x1f] = '.'; // 11111 Shift to letters

	baudotToChar[0x00] = '*'; // 00000 NULL
	baudotToChar[0x01] = 'E'; // 00001
	baudotToChar[0x02] = '-'; // 00010 LF
	baudotToChar[0x03] = 'A'; // 00011
	baudotToChar[0x04] = ' '; // 00100 SPACE
	baudotToChar[0x05] = 'S'; // 00101
	baudotToChar[0x06] = 'I'; // 00110
	baudotToChar[0x07] = 'U'; // 00111
	baudotToChar[0x08] = ','; // 01000 CR
	baudotToChar[0x09] = 'D'; // 01001
	baudotToChar[0x0a] = 'R'; // 01010
	baudotToChar[0x0b] = 'J'; // 01011
	baudotToChar[0x0c] = 'N'; // 01100
	baudotToChar[0x0d] = 'F'; // 01101
	baudotToChar[0x0e] = 'C'; // 01110
	baudotToChar[0x0f] = 'K'; // 01111
	baudotToChar[0x10] = 'T'; // 10000
	baudotToChar[0x11] = 'Z'; // 10001
	baudotToChar[0x12] = 'L'; // 10010
	baudotToChar[0x13] = 'W'; // 10011
	baudotToChar[0x14] = 'H'; // 10100
	baudotToChar[0x15] = 'Y'; // 10101
	baudotToChar[0x16] = 'P'; // 10110
	baudotToChar[0x17] = 'Q'; // 10111
	baudotToChar[0x18] = 'O'; // 11000
	baudotToChar[0x19] = 'B'; // 11001
	baudotToChar[0x1a] = 'G'; // 11010
	baudotToChar[0x1b] = '!'; // 11011 Shift to figures
	baudotToChar[0x1c] = 'M'; // 11100
	baudotToChar[0x1d] = 'X'; // 11101
	baudotToChar[0x1e] = 'V'; // 11110
	baudotToChar[0x1f] = '.'; // 11111 Shift to letters

}

int teleprinter::getBaudotFromChar(char c)
{
	return charToBaudot[c];
}

char teleprinter::getCharFromBaudot(int b)
{
	return baudotToChar[b];
}

string teleprinter::encryptMessage(string message)
{
	string encMessage = "";

	for(int i=0;i<message.size();i++)
	{
		int baudot = getBaudotFromChar(message[i]);
		int encBaudot = encryptor.encryptChar(baudot);
		char encChar = getCharFromBaudot(encBaudot); //BUG FIX 3
		encMessage.push_back(encChar);
	}

	return encMessage;
}