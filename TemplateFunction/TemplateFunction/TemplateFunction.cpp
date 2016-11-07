// TemplateFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//int findMaxValue(int intArray[], int count)
//{
//	int maxValue = 0;
//	for (int i = 0; i<count; i++)
//	{
//		if (intArray[i] > maxValue)
//		{
//			maxValue = intArray[i];
//		}
//	}
//	return maxValue;
//}

//float findMaxValue(float floatArray[], int count)
//{
//	float maxValue = 0;
//	for (int i = 0; i<count; i++)
//	{
//		if (floatArray[i] > maxValue)
//		{
//			maxValue = floatArray[i];
//		}
//	}
//	return maxValue;
//}

template <typename T> 
T findMaxValueT(T Array[], int count)
{
	T maxValue = 0.0f;

	for (int i = 0; i<count; i++)
	{
		if (Array[i] > maxValue)
		{
			maxValue = Array[i];
		}
	}
	return maxValue;
}

int main()
{
	int intArray[] = { 13,12,36,44,25 };
	float floatArray[] = { 12.4f,3.6f,23.2f,14.7f,5.2f };

	cout << "Average of intArray is " << findMaxValueT(intArray, 5) << endl;
	cout << "Average of floatArray is " << findMaxValueT(floatArray, 5) << endl;

	system("pause");

	return 0;
}