#include<string.h>
#include<stdlib.h>
#include<stdio.h>
 #include <sys/types.h>
       #include <sys/stat.h>
     #include <fcntl.h>

int main(int args,char* arg[])
{
	char buff[100];
	int c;
	for(int i=1;i<=args;i++)
	{
		int fd=open(arg[i],O_RDONLY);
		while((c=read(fd,buff,100))!=0)
		{
			for(int j=0;j<c;j++)
				printf("%c",buff[j]);
		}
	}
	return 0;
}