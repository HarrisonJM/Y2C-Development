#include <stdio.h>

//#define _CRT_SECURE_NO_WARNINGS

int fizzybuzzy()
{
	for (int i = 0; i < 1000; ++i)
	{
		if (((i % 3) == 0) && ((i % 5) == 0))
		{
			printf("%d: buzz", i);
		}
		else if (((i % 3) == 0) || ((i % 5) == 0))
		{
			printf("%d : fizz", i);
		}
		else
		{
			printf("%d", i);
		}

		printf("\n");
	}

	return 0;
}
