#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main(int args, char* arg[])
{
	if(args>=1 && strcmp(arg[1],"-r")==0)
	{
		args--;		
		while(args>1)
		{		
			struct dirent *d;
			DIR *dir;
			char buf[256];
			dir=opendir(arg[args]);
			while(d=readdir(dir))
			{
				sprintf(buf,"%s/%s",arg[args],d->d_name);
				remove(buf);
			}
			remove(arg[args]);
			args--;
		}            
	}
	if(args>=1 && strcmp(arg[1], "-i")==0)
	{

		int c=0;
		while(args-- >1)
		{
			printf("enter 1 if you want to delete %s \n", arg[args]);
			scanf("%d",&c);
			if(c==1)
			remove(arg[args]);
		}
	}
	else if(args>=1 && strcmp(arg[1], "-f")==0)
	{
		while(args-- >1)
		{
			remove(arg[args]);
		}
	}
	

	return 0;
}
