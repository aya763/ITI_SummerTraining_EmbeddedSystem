
#include <stdio.h>


int sumOfDigits(int n);


int main()
{
	
	int num;

  
    printf("Please enter a number: ");
    scanf("%d", &num);
	
	printf("Sum = %d\n", sumOfDigits(num));
	
	return 0;
}


int sumOfDigits(int n)
{
	if(n==0)
	{
		return 0;
	}
	else 
	{
		return (n%10)+sumOfDigits(n/10);
	}
}

