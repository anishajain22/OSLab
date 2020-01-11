#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int args,char* arg[])
{
int lines;
int l=0;
int c;
char buff[100];
if(args==2)
{
	int fd=open(arg[1],O_RDONLY);
	lines=10;
	while(l<lines &&(( c=read(fd,buff,100))!=0))
	{
	for(int j=0;j<c;j++)
	{
		if(buff[j]=='\n')
			l++;
		if(l>=lines)
			break;		
		printf("%c",buff[j]);
	}
	}
}
else
{
	if(strcmp(arg[1],"-n")==0)
	{
	int fd=open(arg[3],O_RDONLY);
	lines=atoi(arg[2]);
        while(l<lines &&(( c=read(fd,buff,1))!=0))
        {
        l++;
        for(int j=0;j<c;j++)
		{
		if(buff[j]=='\n')
			l++;
		if(l>=lines)
			break;		
		printf("%c",buff[j]);
		}
		}

	}
}
}
