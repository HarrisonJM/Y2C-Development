#include "stdafx.h"
#include "teleprinter.h"

teleprinter::teleprinter(lorenzMachine encryptionDevice)
{
	char c[] = { "*E-A_SIU,DRJNFCKTZLWHYPQOBG.MXV!" };
	
	for (int i = 0b00000; i < 0b11111; ++i)
	{
		charToBaudot[c[i]] = i;
	}

	for (int i = 0b00000; i < 0b11111; ++i)
	{
		baudotToChar[i] = c[i];
	}

	encryptor = encryptionDevice;

	/* Very long list */
	/*charToBaudot['*'] = 00000;
	charToBaudot['E'] = 00001;
	charToBaudot['-'] = 00010;
	charToBaudot['A'] = 00011;
	charToBaudot[' '] = 00100;
	charToBaudot['S'] = 00101;
	charToBaudot['I'] = 00110;
	charToBaudot['U'] = 00111;
	charToBaudot[','] = 01000;
	charToBaudot['D'] = 01001;
	charToBaudot['R'] = 01010;
	charToBaudot['J'] = 01011;
	charToBaudot['N'] = 01100;
	charToBaudot['F'] = 01101;
	charToBaudot['C'] = 01110;
	charToBaudot['K'] = 01111;
	charToBaudot['T'] = 10000;
	charToBaudot['Z'] = 10001;
	charToBaudot['L'] = 10010;
	charToBaudot['W'] = 10011;
	charToBaudot['H'] = 10100;
	charToBaudot['Y'] = 10101;
	charToBaudot['P'] = 10110;
	charToBaudot['Q'] = 10111;
	charToBaudot['O'] = 11000;
	charToBaudot['B'] = 11001;
	charToBaudot['G'] = 11010;
	charToBaudot['.'] = 11011;
	charToBaudot['M'] = 11100;
	charToBaudot['X'] = 11101;		
	charToBaudot['V'] = 11110;
	charToBaudot['!'] = 11111;*/
}

int teleprinter::getBaudotFromChar(char c)
{
	int baudot;

	baudot = charToBaudot[c];

	//switch (c)
	//{
	//case '*': // (NULL) *
	//	baudot = 0b00000;
	//	break;
	//case ' ': //SPACE
	//	baudot = 0b00100;
	//	break;
	//case 'Q': //Q
	//	baudot = 0b10111;
	//	break;
	//case 'W': //W
	//	baudot = 0b10011;
	//	break;
	//case 'E': //E
	//	baudot = 0b00001;
	//	break;
	//case 'R': //R
	//	baudot = 0b01010;
	//	break;
	//case 'T': //T
	//	baudot = 0b10000;
	//	break;
	//case 'Y': //Y
	//	baudot = 0b10101;
	//	break;
	//case 'U': //U
	//	baudot = 0b00111;
	//	break;
	//case 'I': //I
	//	baudot = 0b00110;
	//	break;
	//case 'O': //O
	//	baudot = 0b11000;
	//	break;
	//case 'P': //P
	//	baudot = 0b10110;
	//	break;
	//case 'A': //A
	//	baudot = 0b00011;
	//	break;
	//case 'S': //S
	//	baudot = 0b00101;
	//	break;
	//case 'D': //D
	//	baudot = 0b01001;
	//	break;
	//case 'F': //F
	//	baudot = 0b01101;
	//	break;
	//case 'G': //G
	//	baudot = 0b11010;
	//	break;
	//case 'H': //H
	//	baudot = 0b10100;
	//	break;
	//case 'J': //J
	//	baudot = 0b01011;
	//	break;
	//case 'K': //K
	//	baudot = 0b01111;
	//	break;
	//case 'L': //L
	//	baudot = 0b10010;
	//	break;
	//case 'Z': //Z
	//	baudot = 0b10001;
	//	break;
	//case 'X': //X
	//	baudot = 0b11101;
	//	break;
	//case 'C': //C
	//	baudot = 0b01110;
	//	break;
	//case 'V': //V
	//	baudot = 0b11110;
	//	break;
	//case 'B': //B
	//	baudot = 0b11001;
	//	break;
	//case 'N': //N
	//	baudot = 0b01100;
	//	break;
	//case 'M': //M
	//	baudot = 0b11100;
	//	break;
	//case ',': //(Carriage return) ,
	//	baudot = 0b01000;
	//	break;
	//case '-': // (line feed) -
	//	baudot = 0b00010;
	//	break; 
	//case '.': // (letter shift) .
	//	baudot = 0b11011;
	//	break;
	//case '!': // (Figure Shift) !
	//	baudot = 0b11111;
	//	break;
	//}

	return baudot;
}

char teleprinter::getCharFromBaudot(int b)
{
	char c;

	c = baudotToChar[b];

	//switch (b)
	//{
	//case 0b00000: // (NULL) *
	//	c = '*';
	//	break;
	//case 0b00100: //SPACE
	//	c = ' ';
	//	break;
	//case 0b10111: //Q
	//	c = 'Q';
	//	break;
	//case 0b10011: //W
	//	c = 'W';
	//	break;
	//case 0b00001: //E
	//	c = 'E';
	//	break;
	//case 0b01010: //R
	//	c = 'R';
	//	break;
	//case 0b10000: //T
	//	c = 'T';
	//	break;
	//case 0b10101: //Y
	//	c = 'Y';
	//	break;
	//case 0b00111: //U
	//	c = 'U';
	//	break;
	//case 0b00110: //I
	//	c = 'I';
	//	break;
	//case 0b11000: //O
	//	c = 'O';
	//	break;
	//case 0b10110: //P
	//	c = 'P';
	//	break;
	//case 0b00011: //A
	//	c = 'A';
	//	break;
	//case 0b00101: //S
	//	c = 'S';
	//	break;
	//case 0b01001: //D
	//	c = 'D';
	//	break;
	//case 0b01101: //F
	//	c = 'F';
	//	break;
	//case 0b11010: //G
	//	c = 'G';
	//	break;
	//case 0b10100: //H
	//	c = 'H';
	//	break;
	//case 0b01011: //J
	//	c = 'J';
	//	break;
	//case 0b01111: //K
	//	c = 'K';
	//	break;
	//case 0b10010: //L
	//	c = 'L';
	//	break;
	//case 0b10001: //Z
	//	c = 'Z';
	//	break;
	//case 0b11101: //X
	//	c = 'X';
	//	break;
	//case 0b01110: //C
	//	c = 'C';
	//	break;
	//case 0b11110: //V
	//	c = 'V';
	//	break;
	//case 0b11001: //B
	//	c = 'B';
	//	break;
	//case 0b01100: //N
	//	c = 'N';
	//	break;
	//case 0b11100: //M
	//	c = 'M';
	//	break;
	//case 0b01000: //(Carriage return) ,
	//	c = ',';
	//	break;
	//case 0b00010: // (line feed) -
	//	c = '-';
	//	break;
	//case 0b11011: // (letter shift) .
	//	c = '.';
	//	break;
	//case 0b11111: // (Figure Shift) !
	//	c = '!';
	//	break;
	//}

	return c;
}

string teleprinter::encryptMessage(string message)
{
	string encmessage;
	encmessage.resize(message.length(), '.');

	int baudot, xor;

	encmessage.empty();

	for (int i = 0; i < message.length(); ++i)
	{
		
		baudot = getBaudotFromChar(toupper(message[i])); //get baudot number

		xor = encryptor.encryptChar(baudot);

		encmessage[i] = getCharFromBaudot(xor);
	}

	encmessage[encmessage.length()] = EOF;

	return encmessage;
}