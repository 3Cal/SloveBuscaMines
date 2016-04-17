#include <unistd.h> /* fork, dup2, execv */
#include <sys/wait.h> /* wait */
#include <string.h> /* strlen, strchr */

#include "parser.h"

/* Idealment aixo no seera un void ... o si... */
int input ( in )
	char * in;
{
	int pid;
	int fd[2]; /* file descriptor */
	if ( pipe (fd) ) return 30; /* Error pipe */
	pid = fork ();
	if ( pid )
	{ /* parent */
		int status;
		wait (&status);
		if ( status ) return 2; /* Error entrada */
		read (fd[0], in, strlen (in) );
		if (strchr (in, 'm')) /* A repetir l'operacio com tontets jajaja */
			input ( in );
		return parser ( in ); /* Passem tota la responsablitat a aquest */
	} else
	{ /* child */
		char * argv [3] = { "./mineobfusc", in, NULL };
		dup2 ( fd[1], 1); /* Canviem la sortida normal */
		close ( fd[1] ); /* tanquem el fd, no se perque po ho fem */
		execv ( argv[0], argv );
	}
}
