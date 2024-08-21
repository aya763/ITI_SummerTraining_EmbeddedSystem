

#include <stdio.h>

int main() 
{
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are:\n ", num);
    for (int i = 1; i <= num; i++) 
	{
        if (num % i == 0) 
		{
            printf("%d\n ", i);
        }
    }
   

    return 0;
}
