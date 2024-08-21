

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float l;

    printf("Please enter the number of sides: ");
    scanf("%d", &n);

    printf("Please enter the length for each side: ");
    scanf("%f", &l);

    

   
    printf("The area of this polygon is: %.2f\n", (n * l * l) / (4 * tan(M_PI / n)));

    return 0;
}
