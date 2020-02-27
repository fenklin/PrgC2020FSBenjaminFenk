#include <stdio.h>

/* binary number print */

int main(void)
{
	// "programmer input"
	int decimalNumber = 14;

	printf("Initial Decimal: %d\n", decimalNumber);

	// It is from LSB to MSB!!!!!
	printf("Binary Form (LSB to MSB): 0b");

	//variables needed for calculation
	int divisionResult = decimalNumber;
	int remainder = 0;

	while(divisionResult > 0)


	{
		remainder = divisionResult%2;
		printf("%d", remainder);
		divisionResult = divisionResult/2;
	}
	printf("\n");
	return 0;


}
