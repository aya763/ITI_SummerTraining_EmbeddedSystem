

#include <stdio.h>


int sumArray(int arr[], int size);


int main()
{
	int n;
	printf("Enter size of array:");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Sum of array elements : %d\n",sumArray(arr,n));
	
	return 0;
}



int sumArray(int arr[], int size)
{
	int sum=0;
	
	for(int i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	return sum;
	
	
}