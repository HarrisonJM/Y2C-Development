// C++ Development.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void LeapYears();

void PrimeNumbers();
int IsPrimeNumber(int number);

void TimesTables();
void NumberSumOdd();
void NumberSum();
void NameReturn();

int main()
{
	while (1)
	{
		int choice = 0;

		system("cls");

		printf("C++ Development Week 1\n\n\n");

		printf("1...............Hello World\n");
		printf("2...............Name Return\n");
		printf("3...............sum of 1 to n\n");
		printf("4...............sum of multiples of 3 and of from 1 to n\n");
		printf("5...............times table for 1 to 12\n");
		printf("6...............print prime numbers from 1 to 100\n");
		printf("7...............print next 20 leap years\n\n");

		printf("Enter Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Hello World\n\n");
			system("pause");
			break;
		case 2:
			NameReturn();
			break;
		case 3:
			NumberSum();
			break;
		case 4:
			NumberSumOdd();
			break;
		case 5:
			TimesTables();
			break;
		case 6:
			PrimeNumbers();
			break;
		case 7:
			LeapYears();
			break;
		default:
			printf("Exiting Program");
			system("pause");
			return(0);
		}
	}
}

void LeapYears()
{
	int year, i;

	printf("Enter Current year: ");
	scanf("%d", &year);

	for (i = year; i < year + 21; ++i)
	{
		if (i % 4 == 0)
		{
			printf("%d is a leap year \n", i);
		}
	}

	system("pause");
	return;
}

void PrimeNumbers()
{
	int i;

	system("cls");
	printf("Prime Numbers.");

	for (i = 2; i < 101; ++i)
	{
		if (IsPrimeNumber(i) == 1)
		{
			printf("%d\n", i);
		}

	}

	system("pause");
	return;
}

int IsPrimeNumber(int number)
{
	int i, temp = -1, boolean = 0;

	for (i = 2; i < number; ++i)
	{
		if ((i != 0) && (i != 1) && (i != number))
		{
			temp = number % i;
		}

		if (temp == 0) //not prime number
		{
			return 0;
		}
	}

	return 1;
}

void TimesTables()
{
	int i, j;
	system("cls");
	printf("Times tables up to 12");

	for (i = 1; i < 13; ++i)
	{
		printf("**********************\n");
		printf("%d list.\n", i);

		for (j = 1; j < 13; ++j)
		{
			printf("%d x %d = %d\n", j, i, i*j);
		}
	}

	system("pause");
	return;
}

void NumberSumOdd()
{
	int i, n = 0, total = 0;
	system("cls");
	printf("Please enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < n + 1; ++i)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			total += i;
		}
	}

	printf("Sum of numbers up to %d: %d", n, total);

	system("pause");
	return;
}

void NumberSum()
{
	int i, n = 0, total = 0;
	system("cls");
	printf("Please enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < n + 1; ++i)
	{
		total += i;
	}

	printf("Sum of numbers up to %d: %d", n, total);
	
	system("pause");
	return;
}

void NameReturn()
{
	char name[256];

	system("cls");
	printf("Please Enter your name: ");
	scanf("%s", name);

	printf("Hello, %s!", &name);

	system("pause");
	return;
}



