
#include<stdio.h>



int main()
{
	int x=3,y=4,z=5,*p,*q,*r;
	p=&x;
	q=&y;
	r=&z;
	
	printf("x=%d , y=%d , z=%d , p=%p , q=%p , r=%p ,*p=%d ,*q=%d , *r=%d\n",x,y,z,p,q,r,*p,*q,*r);
	printf("Swapping pointer\n");
	r=p;
	p=q;
	q=r;
	printf("x=%d , y=%d , z=%d , p=%p , q=%p , r=%p ,*p=%d ,*q=%d , *r=%d\n",x,y,z,p,q,r,*p,*q,*r);
	
	
	
	return 0;
}