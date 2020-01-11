#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int args,char* arg[])
{
char buff[100];
int fd=open(arg[1],O_RDONLY);
int c;
int wc=0;
int cc=0;
int nc=0;
int i;
while((c=read(fd,buff,100))!=0)
{
	for(i=0;i<c;i++)
	{
		if(buff[i]=='\n')
		{
			wc++;
			nc++;
		}
		else if(buff[i]==' ')
			wc++;
		else 
			cc++;
		printf("%c",buff[i]);
	}
}
printf(" word count %d ,line count %d,character count %d ",wc,nc,cc);
return 0;
}

