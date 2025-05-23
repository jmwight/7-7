#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLINE	1024

int main(int argc, char **argv)
{
	/* get file names and argument list
	 * format: ./find [ARGS] file1, file2, ..., fileN */
	if(argc < 3)
	{
		fprintf(stderr, "Error: incorrect format!\n"
				"Format: ./find [ARGS] PATTERN FILE1, FILE2, ..., FILEN\n");
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
		++argv;
	}

	/* get pattern */
	char *pat = strdup(*argv++);
	--argc;

	/* find program run on each file */
	while(--argc > 0)
	{
		/* open each file */
		FILE *fp = fopen(*argv, "r");
		if(fp == NULL)
			fprintf(stderr, "Error: unable to open %s file!\n", *argv);

		printf("File \"%s\"\n", *argv);
		unsigned long lnum = 0;
		char line[MAXLINE], *lp;
		while((lp = fgets(line, MAXLINE, fp)) != NULL)
		{
			lnum++;
			char *fndptr;
			fndptr = strcasestr(line, pat);
			if(x == 0 && fndptr != NULL)
			{
				if(n)
					printf("%-5lu\t", lnum);
				printf("%s", line);
			}
			else if(x == 1 && fndptr == NULL)
			{
				if(n)
					printf("%-5lu\t", lnum);
				printf("%s", line);
			}
		}
		printf("\n\n");
		/* close each file and advance argv */
		fclose(fp);
		if(ferror(fp))
			fprintf(stderr, "Error closing file %s\n", *argv);
		++argv;
	}
}

