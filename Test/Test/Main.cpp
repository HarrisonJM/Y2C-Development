#include <stdio.h>

void genbits(char *p, unsigned char val);

int ian(int argc, char *argv[])
{
	char bits[9];
	unsigned char i = 0xff;
	int j;
	for (j = 0; j<256; j++)
	{
		genbits(bits, i);
		printf("%3d %s %02X\n", i, bits, i);
		i = i--;
	}

	getchar();
	return 0;
}
/**********************************************
** Name: genbits **
** Author: IRJ **
** Date: 26-SEP-2001 **
** Desc: function to produce an 8 char **
** ASCII string of the binary of val**
**********************************************/
void genbits(char *p, unsigned char val)
{
	int i;
	unsigned char mask;
	mask = 0x01; /* init mask */
	*(p + 8) = '\0'; /* insert null */
	for (i = 0; i<8; i++) /* foreach bit */
	{
		if (val & mask) /* if its 1 */
			*(p + 7 - i) = '1';
		else
			*(p + 7 - i) = '0';
		mask = mask << 1; /* move mask to next
						  bit */
	}
}