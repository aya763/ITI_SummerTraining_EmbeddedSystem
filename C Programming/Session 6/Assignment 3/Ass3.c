
#include <stdio.h> 
typedef long int uint32_t; 
uint32_t a = 0; 
uint32_t b = 0; 
uint32_t c = 0; 
typedef struct{ 
uint32_t x; 
uint32_t y; 
uint32_t z; 
} MyStruct;

 
int main() 
{ 
	MyStruct * ptr = &a;
	
	ptr->x = 10;
    ptr->y = 20;
    ptr->z = 30;

	printf("a = %d\n", a); 
	printf("b = %d\n", b); 
	printf("c = %d\n", c); 
	
	return 0;
} 
