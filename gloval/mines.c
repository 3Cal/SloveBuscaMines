#include "variables.h"

void GeneralRound ( i, f )
	int i;
	void f ( int );
{
	int N, S, W, E;

	N = ( i - cx ) >= 0;
	S = ( i + cx ) < MatrixSize;
	W = i % cx;
	E = ( i + 1 ) % cx;

	if ( N ) f ( i - cx );
	if ( S ) f ( i + cx );
	if ( W ) f ( i - 1 );
	if ( E ) f ( i + 1 );

	if ( N && W ) f ( i - cx - 1 );
	if ( N && E ) f ( i - cx + 1 );

	if ( S && W ) f ( i + cx - 1 );
	if ( S && E ) f ( i + cx + 1 );
}
