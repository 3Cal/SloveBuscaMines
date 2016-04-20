#include <stdio.h>
#include "variables.h"

void GeneralRound ( i, f )
	int i;
	void f ( int, int );
{
	int N, S, W, E;

	N = ( i - cx ) >= 0;
	S = ( i + cx ) < MatrixSize;
	W = i % cx;
	E = ( i + 1 ) % cx;

	if ( N ) f ( i - cx, i );
	if ( S ) f ( i + cx, i );
	if ( W ) f ( i - 1, i );
	if ( E ) f ( i + 1, i );

	if ( N && W ) f ( i - cx - 1, i );
	if ( N && E ) f ( i - cx + 1, i );

	if ( S && W ) f ( i + cx - 1, i );
	if ( S && E ) f ( i + cx + 1, i );
}

void ShowRealMatrix ()
{
	int i;
	for ( i = 0; i < MatrixSize; i++ )
	{
		if ( (i % cx) == 0 ) printf ("\n");
		printf ( "%d", realMatrix[i]);
	}
	printf ( "\n" );
}
