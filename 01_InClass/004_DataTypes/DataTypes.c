#include <stdio.h>

int main(void)

{
	printf("Printing data type sizes in bytes... \n");

	//prints size of data type in bytes

	printf("Size of char: %ld\n", sizeof(char));
	printf("Size of short: %ld\n", sizeof(short));
	printf("Size of long and long long: %ld and %ld\n", sizeof(long), sizeof(long long));

	return 0;
}	
