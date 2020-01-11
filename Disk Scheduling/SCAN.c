#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void scan(int a[],int n)
{
	
	int ptr, b[n+1], i, j, min, x, temp;
	
	printf("\n current pointer location");
	scanf("%d", &ptr);
	
	b[0]= ptr; 
	
	for(i=0; i<n; i++)
	{
	 	b[i+1]= a[i];
	}
	
	for(i=0; i<n; i++)
	{
		min= i;
		
		for(j=i+1; j<n+1; j++)
		{
			if(b[j]<b[min])
			{
			min = j;
			}
		}
		
		temp = b[i];
		b[i] = b[min];
		b[min] = temp;
	}
	
	int dloc;
	



	for(i=0;i<n+1;i++)   // to find loc of disc in array
	{
		 if(ptr==b[i])
	 	{ dloc=i; break; }
	}
	
	for(i=dloc;i>=0;i--)
	{
	printf("%d -->",b[i]);
	}
	
	printf("0 -->");
	
	
	for(i=dloc+1;i<n+1;i++)
	{
	printf("%d-->",b[i]);
	}

	printf("\nTotal cost : %d", ptr+b[n]);
	
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
	
	
	scan(a,n);
}

