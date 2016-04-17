#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ShowByts ( e, n )
	unsigned char *e;
	unsigned int n;
{
	unsigned int i;
	for ( i = n-1; i >= 0; i--)
		printf ("element %d: %d\n", i, e[i]);
	printf ("\n");
}

void AsciitoArray ( acii, array, lenA )
	char * acii;
	unsigned char * array;
	unsigned int lenA;
{
	unsigned int lenF = sizeof (long int); /* retorna la funcio*/
	unsigned int lenS = strlen ( acii );
	int i = 0;

	while ( (2*lenF) <= lenS )
	{
		array[i] = strtol ( acii + lenS - 2*lenF, NULL, 16 );
		lenS	-= 2*lenF;
		i	+= lenF;
	}
}

int main ()
{
	//char *m = "0812000000004d0800018";
	char *m = "0102030405060708";
	unsigned char *b;
	long int t;

	printf ("%s\n", m);
	//AsciitoArray (m, b, 11);
	t = strtol ( m, NULL, 16 );
	b = &t;
	ShowByts ( b, 8 );

return 0;
}
