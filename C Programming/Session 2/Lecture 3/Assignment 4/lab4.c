

#include <stdio.h>

int main() 
{
    int dec, bin = 0, place = 1;

    
    printf("Please enter a decimal number: ");
    scanf("%d", &dec);

   
    while (dec != 0) 
	{
        bin += (dec % 2) * place;
        dec /= 2;
        place *= 10;
    }

  
    printf("Binary = %d\n", bin);

    return 0;
}
