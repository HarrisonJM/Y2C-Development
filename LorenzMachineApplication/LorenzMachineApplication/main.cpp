#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

#include "lorenzMachine.h"
#include "teleprinter.h"
#include "wheel.h"

// construct a lorenz machine object using a pinsettings file
lorenzMachine constructLorenzMachine();

int main()
{
	string phrase;

	lorenzMachine encryptionDevice = constructLorenzMachine();
	teleprinter keyboard(encryptionDevice);

	cout << "Enter Phrase to encrypt/decrypt: ";
	//cin >> phrase;
	getline(cin, phrase);

	string encryptedMessage = keyboard.encryptMessage(phrase);
	//string encryptedMessage = keyboard.encryptMessage("JWMFQV--.US"); //what's this for? Output is garbage; incorrect pin settings...

	cout << "ENCRYPTED MESSAGE: " << encryptedMessage << endl;

	std::cout << "Press ENTER to continue... " << flush;
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');

	//string encryptedMessage = keyboard.encryptMessage("JWMFQV--.US");

	return 0;
}

lorenzMachine constructLorenzMachine()
{
	// read pinsettings into memory
	string pinSettings;
	ifstream infile;
	infile.open("pinsettings.dat");
	getline(infile,pinSettings);
	infile.close();

	// create 5 wheel objects and group them together to represent the chi wheels
	wheel chi1(pinSettings.substr(0,43));
	wheel chi2(pinSettings.substr(43,47));
	wheel chi3(pinSettings.substr(90,51));
	wheel chi4(pinSettings.substr(141,53));
	wheel chi5(pinSettings.substr(194,59));
	wheelGroup chi(chi1,chi2,chi3,chi4,chi5);

	// create 2 wheel objects to represent the two motor wheels
	wheel m37(pinSettings.substr(253,37));
	wheel m61(pinSettings.substr(290,61));

	// create 5 wheel objects and group them together to represent the psi wheels
	wheel psi1(pinSettings.substr(351,41));
	wheel psi2(pinSettings.substr(392,31));
	wheel psi3(pinSettings.substr(423,29));
	wheel psi4(pinSettings.substr(452,26));
	wheel psi5(pinSettings.substr(478,23));
	wheelGroup psi(psi1,psi2,psi3,psi4,psi5);

	// create a new encryption device object containing the psi, chi, m37 and m61 objects
	lorenzMachine encryptionDevice(chi, psi, m37, m61);
	
	return encryptionDevice;
}