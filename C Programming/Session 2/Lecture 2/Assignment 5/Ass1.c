
#include <stdio.h>

int main() 
{
    int num[10];
    int ch, found = 0;

    for (int i = 0; i < 10; i++) 
	{
        printf("Please Enter Number %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    
    printf("Please enter a number to search: ");
    scanf("%d", &ch);

    for (int i = 0; i < 10; i++) 
	{
        if (num[i] == ch) 
		{
            printf("The Number you entered is at position: %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) 
	{
        printf("Number not found\n");
    }

    return 0;
}
