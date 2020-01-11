#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<signal.h>

int isActive(int pid)
{
	if(kill(pid,0))
		return 0;
	return 1;
}

int main(int args,char* arg[])
{
	struct dirent *sd;
	DIR *dir=opendir("/proc/");
	while((sd=readdir(dir)))
	{	
		int f=0;
		for(int i=0;i<strlen(sd->d_name);i++)
		{
			if(!isdigit(sd->d_name[i]))
			{
				f++;
				break;
			}
		}
		if(f)
		continue;
		
		int pid=atoi(sd->d_name);

	
		if(isActive(pid))
		{
			printf("%s \t", sd->d_name);		
		}
	}
	closedir(dir);
	return 0;

}
