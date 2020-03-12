#include <stdio.h>

int main(void)
{
//exercise 1
	short largeShort = 32760;
	largeShort = largeShort + 12345;

	printf("%d\n", largeShort);

//exercise 2
	int numerator = 19, denominator = 5, result = 0, rest = 0;
	result = numerator/denominator;
	rest = numerator%denominator;

	printf("Result: %d\nRest: %d\n", result, rest);

//exercise 3
	float e = 2.718281828f;
	e++;
	e--;

	printf("%f\n", e);

/*exercise 4 ---> does not work because modulo (%) is not for double float
	double dblNumerator = 12.8, dblDenominator = 3, modulo = 0;
	modulo = dblNumerator%dblDenominator;

	printf("%f\n", (float)modulo);
*/
	return 0;

}
