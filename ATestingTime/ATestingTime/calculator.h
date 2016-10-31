#pragma once
// a simple calculator class which provides standard arithmetic operators
// the functions have been defined in a special way to prepare the project
// to be used as a DLL. Every function to be included in the DLLs public
// interface needs to be prefixed with the _declspec(dllimport) directive

class calculator
{
public:
	_declspec(dllexport) float add(float x, float y);
	_declspec(dllexport) float sub(float x, float y);
	_declspec(dllexport) float mul(float x, float y);
	_declspec(dllexport) float div(float x, float y);
};