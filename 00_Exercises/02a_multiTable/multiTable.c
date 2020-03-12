#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void);  //function prototype
void PrintMultiTable( int );

const int lowerLimit = 1;
const int upperLimit = 10;

int main( int argc, char * argv[])
{
	int inputValue = 0;
	if(argc != 2) //not equal 2
	{
		PrintUsageMessage();
		return 0;
	}
	else
	{
		inputValue = atoi(argv[1]);
		if( inputValue >= lowerLimit && inputValue <= upperLimit)
		{
			//input is valid
			PrintMultiTable( inputValue ); 
		}
		else
		{
			//no valid input
			PrintUsageMessage();
			return 0;
		}
	}
	return 0;

}




void PrintUsageMessage(void)
{
	printf("Usage: multiTable wholeNumber\n\t \
wholeNumber: integer on the interval [%d,%d]\n", lowerLimit, upperLimit);
}


void PrintMultiTable( int tableLimit )
{
	for( int i = 1; i <= tableLimit; i++)
	{
		for(int j = 1; j <= tableLimit; j++)
		{
			printf("%d\t", i*j);
		}
		printf("\n");
	}
}
