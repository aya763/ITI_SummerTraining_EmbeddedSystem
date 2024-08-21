
#include <stdio.h>
#include <ctype.h>

int main() 
{
    char ch;

    
    printf("Please enter a single character: ");
    scanf("%c", &ch);

    
    switch (tolower(ch)) 
	{
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c is a vowel.\n", ch);
            break;
        default:
            if (isalpha(ch)) 
			{
                printf("%c is a consonant.\n", ch);
            } 
			else 
			{
                printf("%c is neither a vowel nor a consonant.\n", ch);
            }
    }

    return 0;
}
