#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

int main(int args,char* arg[])
{
	int psid;
	psid=atoi(arg[1]);
	printf("hgfdsijerht %d",psid);
	kill(psid,SIGKILL);
	return 0;
}
