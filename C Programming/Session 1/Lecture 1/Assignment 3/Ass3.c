

#include <stdio.h>


int main()
{
	int x, y;
	printf("Please enter num 1: ");
	scanf("%d",&x);
	printf("Please enter num 2: ");
	scanf("%d",&y);
	printf("a + b = %d \n",x+y);
	printf("a - b = %d \n",x-y);
	printf("a & b = %d \n",x&y);
	printf("a | b = %d \n",x|y);
	printf("a ^ b = %d \n",x^y);
	
	
	return 0;
}