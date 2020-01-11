#include <stdio.h> 
int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 

	int n, m, i, j, k; 
	n = 5; // Number of processes 
	m = 3; // Number of resources 
	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix 
						{ 2, 0, 0 }, // P1 
						{ 3, 0, 3 }, // P2 
						{ 2, 1, 1 }, // P3 
						{ 0, 0, 2 } }; // P4 

	int request[5][3] = { { 0,0,0 }, // P0 
					{ 2,0,2 }, // P1 
					{ 0,0,0 }, // P2 
					{ 1,0,0 }, // P3 
					{ 0,0,2 } }; // P4 

	int avail[3] = { 0,0,0 }; // Available Resources 
	int work[3]={0,0,0};

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m];
	int flag=0; 
	while(1)
	{
		flag=0;
		for(int i=0;i<5;i++)
		{
			if(f[i]==0)
			{
				int j;
				for(j=0;j<3;j++)
				{
					if(request[i][j]<=work[j])
					continue;
					else break;
				}
				if(j==3)
				{
					flag=1;
					for(int k=0;k<3;k++)
					{
						work[k]+=alloc[i][k];
					}
					f[i]=1;
				}
			}	
		}
		if(flag==0)
		break;
		
	}
	int i;
	for(i=0;i<5;i++)
	{	
		if(f[i]==0)
		{
			printf("Deadlock occurs \n");
			break;
		}
	}
	if(i==5)
	{
		printf("No deadlock occurs \n");
	}
	return (0); 

} 

