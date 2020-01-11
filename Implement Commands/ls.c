#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int args,char* arg[])
{
	
	struct dirent **namelist;
	int n;
	if(args<0)
		exit(EXIT_FAILURE);
	else if(args==1)
	{
		n=scandir(".",&namelist,NULL,alphasort);
		if(n<0)
			exit(EXIT_FAILURE);
		else while(n--)
		{
			if(namelist[n] -> d_name[0]!='.')
				printf("%s \n", namelist[n] ->d_name);
			free(namelist[n]);	
		} 	
	}
	else if(args==2 && strcmp(arg[1],"-a")==0)
	{
		n=scandir(".", &namelist, NULL,alphasort);
		if(n<0)
			exit(EXIT_FAILURE);
		else while(n--)
		{
			
			printf("%s \n", namelist[n] ->d_name);
			free(namelist[n]);	
		}	
	}
	else if(args==2 && strcmp(arg[1],"-l")==0)
	{
			
	}
	
	free(namelist);

	return 0;
}
