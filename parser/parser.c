#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <string.h> /* strchr */
#include <math.h> /* round */

#include "../var/variables.h"


void ShowMine ( m )
	char *m;
{
	int i;
	char show = 0;
	for ( i = 0; i < MatrixSize; i++ )
	{
		if ( (i % cx) == 0 ) printf ("\n");
		if ( show == 0) show = 0x80;
		printf ( "%d", 1 && (show & realMatrix [i/8]) );
		show >>=1;
	}
}






/* Quan estem aquest nivell, significa que la entrada es correcta */
/*
 31	Error malloc
*/
int parser ( in )
	char * in;
{
	cx = atoi ( in ); /* definim el primer valor */
	in = strchr ( in, 'x') + 1;
	MatrixSize = atoi ( in ) * cx; /* definim el tamany total */
	in = strchr ( in, ':') + 1;
	begin = atoi ( in );
	in = strchr ( in, ',') + 1;
	begin += atoi ( in ) * cx; /* diem on comenzem */
	in = strchr ( in, 'u') + 1;

	realMatrix = ( char * ) malloc ( (int) (ceil (MatrixSize/8.)));
printf ( "len: %d - byts: %d\n", strlen (in), (int) ceil (MatrixSize/8.));
	realMatrix = strtol ( in, NULL, 16 );

/* Fals, ja que aixo no es el valor, sino el string... */
	realMatrix = in; /* Ja tenim la matriu real ;) */

	printf ("Digit: %ld\n", strtol ( in, NULL, 16) );

	printf ( "First: %d\n", cx );
	printf ( "Total: %d\n", MatrixSize);
	printf ( "Begin: %d\n", begin);

	ShowMine ( realMatrix );

return 0;
}
