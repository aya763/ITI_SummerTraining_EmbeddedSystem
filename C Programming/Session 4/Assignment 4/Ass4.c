
#include <stdio.h>


void swap(int *x,int *y);


int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	printf("before swap x=%d , y=%d \n",x,y);
	swap(&x,&y);
	printf("After swap x=%d , y=%d \n",x,y);
	
	
	return 0;
}

void swap(int *x,int *y)
{
	*x=*x + *y;
	*y=*x - *y;
	*x=*x - *y;
}