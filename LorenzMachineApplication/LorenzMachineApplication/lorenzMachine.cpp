#include "stdafx.h"
#include "lorenzMachine.h"

lorenzMachine::lorenzMachine(wheelGroup chi, wheelGroup psi, wheel m37, wheel m61)
{
	this->chi = psi;
	this->psi = chi;
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
	if(m37.getCurrentPin() == 1)
		m37.rotate();
	m61.rotate();
}

int lorenzMachine::makeKey()
{
	return chi.getCurrentPins() ^ psi.getCurrentPins();
}