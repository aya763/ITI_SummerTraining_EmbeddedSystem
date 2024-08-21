
#include <stdio.h>


void findDigitFreq(char str[]) 
{
    int freq[10] = {0}; 
	
	int size=0;
	
	while(str[size]!='\0')
	{
		size++;
	}

    
    for (int i = 0; i < size; i++) 
	{
        if (str[i] >= '0' && str[i] <= '9') 
		{
            freq[str[i] - '0']++;
        }
    }

    
    for (int i = 0; i < 10; i++) 
	{
        printf("%d ", freq[i]);
    }
    printf("\n");
}

int main() 
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    findDigitFreq(str);

    return 0;
}
