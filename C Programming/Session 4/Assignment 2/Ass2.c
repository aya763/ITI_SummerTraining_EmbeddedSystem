
#include <stdio.h>

int main() 
{
    int arr[5] = {10, 20, 30, 40, 50};

    
    printf("Using array indexing:\n");
    for (int i = 0; i < 5; i++) 
	{
        printf("Element %d >>Address: %p\n", i, &arr[i]);
    }

   
    printf("\nUsing pointers:\n");
    int *ptr = arr; 
    for (int i = 0; i < 5; i++) 
	{
        printf("Element %d >>Address: %p\n", i, ptr + i);
    }
	
	printf("\nSince it is array of integer number and size of int in my machine is 4 bytes,\
	\nit add 4 byte seguentially to array base address\n");

    return 0;
}


