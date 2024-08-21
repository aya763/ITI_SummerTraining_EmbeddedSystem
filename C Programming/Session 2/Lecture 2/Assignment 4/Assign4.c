

#include <stdio.h>

int main()
{
	int ch=0,x=0,y=0;
	printf("Enter two number:");
	scanf("%d %d",&x,&y);
	
	
	printf("\t1.Addition\n\t2.Substruction\n\t3.Multiblication\n\t4.Division\n");
	printf("your choice:");
	scanf("%d",&ch);
	
	
	
	switch(ch)
	{
		case 1:
			printf("%d + %d = %d\n",x,y,x+y);
		break;
		case 2:
			printf("%d - %d = %d\n",x,y,x-y);
		break;
		case 3:
			printf("%d * %d = %d\n",x,y,x*y);
		break;
		case 4:
			if(y!=0)
			{
				printf("%d / %d = %.2f\n",x,y,(float)x/y);
			}
			else 
			{
				printf("ERROR! Division by zero\n");
			}
			
		break;
		default:
			printf("Wrong choice\n");
		break;
		
		
	}
	
	return 0;
}