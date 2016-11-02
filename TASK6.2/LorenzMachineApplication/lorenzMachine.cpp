#include "stdafx.h"
#include "lorenzMachine.h"

lorenzMachine::lorenzMachine(wheelGroup chi, wheelGroup psi, wheel m37, wheel m61)
{
	this->chi = chi; //BUG FIX 7
	this->psi = psi;
	this->m37 = m37;
	this->m61 = m61;
}

int lorenzMachine::encryptChar(int baudotChar)
{
	int key = makeKey();

	rotateWheels();

	return (key ^ baudotChar);
}

void lorenzMachine::rotateWheels()
{
	chi.rotate();

	if(m37.getCurrentPin() == 1)
		psi.rotate();

	if(m61.getCurrentPin() == 1) //BUG FIX 4
		m37.rotate();

	m61.rotate();
}

int lorenzMachine::makeKey()
{
	//int chin = chi.getCurrentPins();
	//int psin = psi.getCurrentPins();
	//int ret = chin ^ psin;

	//return ret

	return chi.getCurrentPins() ^ psi.getCurrentPins();
}