#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	/* get file names and argument list
	 * format: ./find [ARGS] file1, file2, ..., fileN */
	if(argc < 2)
	{
		fprintf(stderr, "Error: incorrect format!\n"
				"Format: ./find [ARGS] file1, file2, ..., fileN\n");
		exit(EXIT_FAILURE);
	}

	int n, x; /* n = line number, x = except */
	n = x = 0;
	/* find arguments */
	if(**++argv == '-' && --argc > 0)
	{
		while(*++*argv != '\0')
		{
			if(**argv == 'n')
				n = 1;
			else if(**argv == 'x')
				x = 1;
			else
			{
				fprintf(stderr, "Error: incorrect argument\n"
						"-n, -x, or -nx only\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	/* get files */
	while(
	/*TODO: GET FILE INPUTS */
	

	/* TODO: FIND PROGRAM */	
}

