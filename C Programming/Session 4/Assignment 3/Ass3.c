#include <stdio.h>


double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() 
{
    
    double (*array[4])(double, double) = {add, subtract, multiply, divide};

    int ch;
    double num1, num2;
	
	printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
	
	printf("\t1.Addition\n\t2.Substruction\n\t3.Multiblication\n\t4.Division\n");
	printf("your choice:");
	scanf("%d",&ch);
	

    if (ch >= 1 && ch <= 4) 
	{
        double res = array[ch - 1](num1,num2);
        printf("Result: %.2lf\n", res);
    } 
	else 
	{
        printf("Wrong choice. Please select 1-4.\n");
    }

    return 0;
}

double add(double a, double b) 
{ 
	return a + b; 
}
double subtract(double a, double b) 
{
	return a - b; 
}
double multiply(double a, double b) 
{
	return a * b;
}
double divide(double a, double b) 
{ 
	if(b!=0)
	{
		return a / b; 
	}
	else 
	{
		printf("ERROR! Division by zero, return -1 indicate for error\n");
		return -1;
	}
	
}
