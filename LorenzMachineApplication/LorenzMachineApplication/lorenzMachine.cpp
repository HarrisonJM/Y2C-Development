#include "stdafx.h"
#include "lorenzMachine.h"

lorenzMachine::lorenzMachine(wheelGroup chiwheels, wheelGroup psiwheels, wheel m37wheel, wheel m61wheel)
{
	chi = chiwheels;
	psi = psiwheels;
	m37 = m37wheel;
	m61 = m61wheel;
}

int lorenzMachine::encryptChar(int baudtoChar)
{
	int key = makeKey();
	int xor = baudtoChar ^ key;

	rotateWheels();

	return xor;
}

void lorenzMachine::rotateWheels()
{
	chi.rotate();

	if (m37.getCurrentPin() == '1')
	{
		psi.rotate();
	}

	if (m61.getCurrentPin() == '1')
	{
		m37.rotate();
	}

	m61.rotate();
}

int lorenzMachine::makeKey()
{
	int chiw, psiw, key;

	chiw = chi.getCurrentPins();
	psiw = psi.getCurrentPins();

	key = chiw ^ psiw;

	return key;
}