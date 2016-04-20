#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <string.h> /* strchr */

#include "../global/variables.h" /* MINE, MINES, realMatrix */
#include "../global/mines.h" /* GeneralRound, for debug: ShowRealMatrix */


void  addOne ( i )
	int i;
{
	if ( realMatrix[i] != MINE )
		realMatrix[i]++;
}

/* Idea, gratament copiada del source 002 */
void GenerateRealMatrix ( in )
	char * in;
{
	char aux[2] = { 0, 0 }; /* interes en posar un zero al final */
	int i = 0, j;
	while ( i < MatrixSize )
	{
		aux[0] = in[0]; in++; // Simulant el getch ()

		aux[0] = strtol ( aux, NULL, 16 ); // Per anar de AsCii a binary array

		for ( j = 0x08; ( j > 0 ) && ( i < MatrixSize ); j >>= 1 )
		{
			if ( aux[0] & j )
			{
				MINES++;
				realMatrix[i] = MINE;
				GeneralRound ( i, addOne );
			}
			i++;
		}
	}
}



/* Quan estem aquest nivell, significa que la entrada es correcta */
/*
 31	Error malloc
*/
int parser ( in )
	char * in;
{
	unsigned int i;
	cx = atoi ( in ); /* definim el primer valor */
in = strchr ( in, 'x') + 1;
	MatrixSize = atoi ( in ) * cx; /* definim el tamany total */
in = strchr ( in, ':') + 1;
	begin = atoi ( in );
in = strchr ( in, ',') + 1;
	begin += atoi ( in ) * cx; /* diem on comenzem */
in = strchr ( in, 'u') + 1;

	realMatrix = ( char * ) malloc ( MatrixSize );

	GenerateRealMatrix ( in );

	printf ("long int: %d", sizeof (long int));
	printf ("Real valor: %s\n", in);
	printf ("Digit: %ld\n", strtol ( in, NULL, 16) );

	printf ( "First: %d\n", cx );
	printf ( "Total: %d\n", MatrixSize);
	printf ( "Begin: %d\n", begin);
	printf ( "Mines: %d", MINES );

	ShowRealMatrix ();

return 0;
}
