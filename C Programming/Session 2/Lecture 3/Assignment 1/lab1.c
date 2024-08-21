

#include <stdio.h>

int main() 
{
    int n, p, res = 1;

 
    printf("Please enter the number: ");
    scanf("%d", &n);
    printf("Please enter the power: ");
    scanf("%d", &p);

    
    for (int i = 0; i < p; i++) {
        res *= n;
    }

   
    printf("Result = %d\n", res);

    return 0;
}
