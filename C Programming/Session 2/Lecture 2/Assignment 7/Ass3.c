

#include <stdio.h>

int main() {
    int num,max;
    
	
	printf("Please Enter 5 numbers seperated with white space: ");
    scanf("%d", &num);
	max=num;

    for (int i = 1; i < 5; i++) 
	{
        scanf("%d", &num);
		if(num>max)
		{
			max=num;
		}
    }

    
    printf("Maximum number is %d \n",max);
    

    return 0;
}