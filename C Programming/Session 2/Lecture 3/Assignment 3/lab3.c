

#include <stdio.h>

int main() 
{
    int num, rev = 0;

   
    printf("Please enter a number: ");
    scanf("%d", &num);

    
    while (num != 0) 
	{
        rev = rev * 10 + (num%10); 
        num /= 10;                
    }

    
    printf("Reversed Number = %d\n", rev);

    return 0;
}
