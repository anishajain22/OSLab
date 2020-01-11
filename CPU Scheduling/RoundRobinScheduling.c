#include<stdio.h>

void findWaiting(int processes[], int n, int bt[],int wt[],int quantum)
{

	int rem_bt[n];
	for(int i=0;i<n;i++)
		rem_bt[i]=bt[i];

	int t=0;

	while(1)
	{
		int k=1;
		for(int i=0;i<n;i++)
		{
			if(rem_bt[i]>0)
			{
				k=0;
				
				if(rem_bt[i]>quantum)
				{
					t = t + quantum;
					rem_bt[i] = rem_bt[i]-quantum;
				}
				else
				{
					t= t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
	
		if(k==1)
		break;
	}
}


void findTurnaround(int processes[], int n, int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];

}

void findTime(int processes[],int n, int bt[],int quantum)
{

	int wt[n] , tat[n] , total_wt=0 , total_tat = 0;

	findWaiting(processes,n,bt,wt,quantum);

	findTurnaround(processes,n,bt,wt,tat);

	printf("Processes   Burst time   Waiting time   Turn around time\n");  

	for(int i=0;i<n;i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("   %d ",(i+1)); 
       	 	printf("       %d ", bt[i] ); 
        	printf("              %d",wt[i] ); 
        	printf("              %d\n",tat[i] );  
	}
	
	float s=(float)total_wt / (float)n; 
    	float t=(float)total_tat / (float)n; 
    	printf("Average waiting time = %f",s); 
    	printf("\n"); 
    	printf("Average turn around time = %f ",t);  
	
}

int main()
{

	int processes[]={1,2,3};
	int n=3;

	int burst_time[]={10,5,8};

	int quantum=2;

	findTime(processes,n,burst_time,quantum);

}

