#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
/* PURPOSE: To skip n spaces on a line
RECEIVES: n - the number of spaces to skip
REMARKS: n should be non-negative
*/
void skip(int n)
{
	int i; /* a counter */
	for (i = 0; i <= n; i++)
		cout << " ";
}

/* PURPOSE: To calculate n factorial
RECEIVES: n - calculate the factorial of n
RETURNS: n factorial
REMARKS: n must be >= 0. Also if n is too large overflow may result
*/
int factorial(int n)
{
	int product = 1; /* accumulator for the running product */
	for (int i = 1; i <= n; i++)
	{
		product = product * i;
	}
	return(product);
}

/* PURPOSE: to calculate the number of combinations of n things taken
k at a time (n choose k)
RECEIVES: n - the number of items to choose from
k - the number of items choosen
RETURNS: n choose k
REMARKS: n and k must be non-negative and k <= n. This program uses
the formula (n choose k) = n! / ( k! * (n-k)! ).
*/
int combination(int n, int k)
{
	int comb = factorial(n) / (factorial(k) * factorial(n - k));
	return comb;
}

int main(void)
{
	int nrows; /* the number of rows to print */
	int n; /* a counter for the current row */
	int k; /* a counter for the current column */
	int comb; /* the number of combinations */
	int spaces_to_skip; /* spaces to skip */

	cout << "Enter the number of rows (<=13) in Pascal's triangle: ";
	cin >> nrows;
	cout << "\n\n\n";
	/* print the title */
	skip(16);
	cout << "TABLE 1: THE FIRST " << nrows << " ROWS OF PASCAL'S TRIANGLE\n\n";

	/* start a loop over the number of rows */
	spaces_to_skip = 36;
	for (n = 0; n < nrows; n = ++n)
	{
		skip(spaces_to_skip); /* space to make a triangle */
		spaces_to_skip = spaces_to_skip - 2;

		for (k = 0; k <= n; k++)
		{
			comb = combination(n, k);
			cout << setw(4) << comb;
		}

		cout << "\n";
	}

	system("pause");
	return 0;
}
