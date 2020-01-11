#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int args,char* arg[])
{
	int c=creat("createtext.txt",O_CREAT);
	printf("%d",c);
	return 0;
}
