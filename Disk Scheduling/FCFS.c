#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void fcfs(int a[],int n)
{
	int order[n], i, x, count=0, ptr;
	
	printf("\n current pointer location");
	scanf("%d", &ptr);
	
	for(i=0; i<n; i++)
	{
		order[i] = a[i];
	}
	
	x= ptr- a[0];
	
	if(x>0)
	count=x;
	else
	count= -x;
	
	
	for(i=1; i<n; i++)
	{
		x= a[i] - a[i-1];
		if(x<0)
		count =count+ (-x);
		else
		count =count+  x;
	}
	
	printf("Execution order:\n");
	



	for(i=0; i<n; i++)
	{
	printf("%d ", order[i]);
	}
	
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
	
	
	fcfs(a,n);
}

