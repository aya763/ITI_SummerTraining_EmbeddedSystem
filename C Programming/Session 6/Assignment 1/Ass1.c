
#include<stdio.h>

struct Complex { 
float real; 
float imag; 
}; 
// Function prototypes 
struct Complex add(struct Complex c1, struct Complex c2); 
struct Complex subtract(struct Complex c1, struct Complex c2); 
struct Complex multiply(struct Complex c1, struct Complex c2); 
struct Complex divide(struct Complex c1, struct Complex c2); 
void displayComplex(struct Complex c);

int main()
{
	struct Complex a={10,12};
	struct Complex b={6,7};
	
	
	

	printf("a=");
	displayComplex(a);
	printf("b=");
	displayComplex(b);
	struct Complex res;
	res =add(a,b);
	printf("sum=");
	displayComplex(res);
	res =subtract(a,b);
	printf("sub=");
	displayComplex(res);
	res =multiply(a,b);
	printf("Mul=");
	displayComplex(res);
	res =divide(a,b);
	printf("div=");
	displayComplex(res);
	
	return 0;
}


struct Complex add(struct Complex c1, struct Complex c2)
{
	struct Complex sum;
	sum.real=c1.real + c2.real;
	sum.imag=c1.imag + c2.imag;
	return sum;
} 
struct Complex subtract(struct Complex c1, struct Complex c2)
{
	struct Complex sub;
	sub.real=c1.real - c2.real;
	sub.imag=c1.imag - c2.imag;
	return sub;
}
struct Complex multiply(struct Complex c1, struct Complex c2)
{
	struct Complex mul;
	mul.real = c1.real * c2.real - c1.imag * c2.imag;
    mul.imag = c1.real * c2.imag + c1.imag * c2.real;
    return mul;
	
}
struct Complex divide(struct Complex c1, struct Complex c2)
{
	struct Complex div;
	div.real=(c1.real*c2.real+c1.imag*c2.imag)/((c2.real)*(c2.real) +(c2.imag)*(c2.imag));
	div.imag=(c1.imag*c2.real-c1.real*c2.imag)/((c2.real)*(c2.real) +(c2.imag)*(c2.imag));
	return div;
}
void displayComplex(struct Complex c)
{
	printf("%.2f+i(%.2f)\n",c.real,c.imag);
}






