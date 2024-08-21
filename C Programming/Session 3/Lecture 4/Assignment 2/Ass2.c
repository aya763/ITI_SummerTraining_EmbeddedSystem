

#include <stdio.h>


// Recursive function for nth fibonacci number

int fibonacci(int n) 
{
    if (n <= 0) 
	{
        return 0; 
    } 
	else if (n == 1) 
	{
        return 1; 
    } 
	else 
	{
        return fibonacci(n - 1) + fibonacci(n - 2); 
    }
}

int main() 
{
    int n;
    printf("Enter the position index starting from 1: ");
    scanf("%d", &n);

    //start postion index from 1
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n-1));

    return 0;
}
