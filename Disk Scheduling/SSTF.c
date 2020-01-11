
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sstf(int a[],int n)
{
		
		int i, j, ptr, count, x, m=n-1, b[n], min=9999, temp;
		
		printf("\n current pointer location");
		scanf("%d", &ptr);
		
		j=ptr;
		
		for(i=0; i<n; i++)
		{
			b[i] =a[i];
		}
		
		while(m>=0)
		{
			min=9999;
			i=m;
			while(i>=0)
			{
				if(abs(b[i]-ptr)<min)
				{
					min= abs(b[i]-ptr);
					x=i;
				}
			
				--i;
			}
			
			ptr=a[x];
			temp= b[x];
			b[x] = b[m];
			b[m] = temp;
			
			--m;
		}
		
		count = abs(j-b[n-1]);
		
		printf("execution order:\n");
		for(i=n-1; i>=1; i--)
		{
		printf("%d ", b[i]);
		count =count+ abs(b[i]-b[i-1]);
		}
		
		printf("%d ", b[0]);
		printf("\nTotal cost : %d", count);
		
}

int main()
{
	int n;
	
	printf("Total no of elements ");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter elements ");
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	
	sstf(a,n);
}

