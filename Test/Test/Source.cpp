#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	double fizz3;
	double fizz5;

	for (int i = 0; i < 1000; ++i)
	{
		fizz3 = (double)i / 3.0;
		fizz5 = (double)i / 5.0;

		if ((fizz3 == 0.0) && (fizz5 == 0.0))
		{
			printf("%d: buzz", i);
		}
		else if ((fizz3 == 0) || (fizz5 == 0))
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
