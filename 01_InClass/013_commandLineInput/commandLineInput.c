#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[] )
{
	// Arguments are the inputs from the command line
	// The first argument (argument 0) is the program name, that's why we start with i = 1 and not with i = 1
	printf("Number of input arguments: %d\n", argc);

	for(int i = 1; i < argc; i++)
	{
		int x = atoi(argv[i]);
	printf("Argument %d was %s and as an int %d\n", i, argv[i], x);
	}

	return 0;
}
