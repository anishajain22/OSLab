#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main(int args, char* arg[])
{
	struct dirent *d;
	DIR *dir;
	char buf[256];
	dir=opendir("dummy");
	while(d=readdir(dir))
	{
	sprintf(buf,"%s/%s","dummy",d->d_name);
	remove(buf);
	}
	sprintf(buf,"dummy");
	remove(buf);
	return 0;
}
