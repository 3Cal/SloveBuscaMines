#include <stdio.h>
#include "parser/input.h"

/*
 1	Not correct number arguments
 2	Input argument is incorrect

 30	Error pipe System
 31	Error malloc
*/

int main ( int argc, char * argv [] )
{
	int status;
	if ( argc == 2 )
		status = input ( argv[1] );
	else return 1;
	if ( status ) return status;
return 0;
}
