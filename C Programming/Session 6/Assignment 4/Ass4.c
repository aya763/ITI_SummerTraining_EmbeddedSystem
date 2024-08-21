

#include <stdio.h>
#include <math.h> 

typedef long int uint32_t;


typedef struct {
    uint32_t x;
    uint32_t y;
    uint32_t z;
} MyStruct;


double calculateArea(MyStruct t) 
{
    double s = (t.x + t.y + t.z) / 2.0;
    return sqrt(s * (s - t.x) * (s - t.y) * (s - t.z));
}


void sort(MyStruct triangles[], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
	{
        for (int j = 0; j < n - i - 1; ++j) 
		{
            if (calculateArea(triangles[j]) > calculateArea(triangles[j + 1])) 
			{
                MyStruct temp = triangles[j];
                triangles[j] = triangles[j + 1];
                triangles[j + 1] = temp; 
            }
        }
    }
}
int main() 
{
    int n; 
    scanf("%d", &n);

    MyStruct triangles[n];

    
    for (int i = 0; i < n; ++i) 
	{
        scanf("%u %u %u", &triangles[i].x, &triangles[i].y, &triangles[i].z);
    }

    
    sort(triangles, n);

	printf("\n");
    
    for (int i = 0; i < n; ++i) 
	{
        printf("%u %u %u\n", triangles[i].x, triangles[i].y, triangles[i].z);
    }

    return 0;
}
