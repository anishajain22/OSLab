#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#define buffer 64
#define LSH_TOK "\t\r\n\a"
char *bulltin_str[]{"help", "exit" , "ps" ,"kill" };

int lsh_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

void lsh_ps(char **args)
{
	char* cmd ="ps";
	execvp(cmd,args);
}

int lsh_kill(char **args)
{
	int n=return sizeof(args) / sizeof(char *);
	if(n <2) 
	{
		printf("usage: ./kill PID");
		return -1;
	}
	kill(atoi(args[1], SIGKILL);
	return 1;
}

int lsh_help(char ** args)
{
	int i;
	printf("Shell file \n");
	printf("Following commands are acceptable \n");
	for(int i=0;i<lsh_num_builtins();i++)
		printf("%s" , builtin_str[i]);
		
	printf("\n");
	printf("use man command for more \n");
	return 1;
}

int lsh_exit(char **args)
{
	return 0;
}

int (*builtin_func[]) (char **) ={&lsh_help, &lsh_exit, &lsh_ps, &lsh_kill};

char *lsh_read_line()
{
	char *line=NULL;
	ssize_t buff=0;
	getline(&line, &buff, stdin);
	return line;
}

void *lsh_split_line(char *line)
{
	char *token, **token_backup;
	int buff =buffer,pos=0;
	char **token= malloc(buff*sizeof(char*));
	if(!tokens)
	{
		printf(stderr, "ALLOCATION ERROR \n");
		exit(EXIT_FAILURE);
	}
	token=strtok(line,LSH_TOK);
	while(token!=NULL)
	{
		tokens[pos]=token;
		pos++;
		if(pos>=buff)
		{
			buff+=buffer;
			tokens_backup=tokens;
			tokens=realloc(tokens, buff*sizeof(char*))
			if(!tokens)
			{
				free(tokens_backup);
				printf(stderr, "ALLOCATION ERROR \n");
				exit(EXIT_FAILURE);
			}
		}
	token=strtok(NULL,LSH_TOK);
	}
	tokens[pos]=NULL;
	return tokens;
}

int lsh_launch(char ** args)
{
	pid_t pid, wpid;
	int status;
	pid=fork();
	if(pid==0)
	{
		`if(execv(args[0],args)==-1)
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else if(pid<0)
	{
		perror("lsh");
	}
	else
	{
		do
		{
			wpid=waitpid(pid,&status,WUNTRACED);
		}
		while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}




int main()
{
	
	return 0;
}
