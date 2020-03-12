#include <stdio.h>
#include <stdlib.h>

/* compute the n choose k */

// prototype
long factorial(int x);

long nChooseK(int n, int k);

int main( int argc, char* argv[] )
{
    int n = 0, k = 0, waitOnValidInput = 1;
	while(waitOnValidInput){
	    printf("Enter the bigger positive integers: ");
    	scanf("%d",&n);
		printf("Enter the smaller positive integers: ");
    	scanf("%d", &k);
		if(n >= 0 && k >= 0 && n >= k) {
		    printf("n choose k of %d and %d = %ld\n", n, k, nChooseK(n,k));
			break;
		}
		else
		{
			printf("Invalid input. Try again.\n");
		}
	}
	return EXIT_SUCCESS;
}

long nChooseK(int n, int k)
{
	return factorial(n)/(factorial(k)*factorial(n-k));
}


// implementation of the factorial function
long  factorial(int x)
{
    if (x>=1)
        return x*factorial(x-1);
    else
        return 1;
}

