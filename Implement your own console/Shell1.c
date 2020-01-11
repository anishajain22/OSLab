#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<dirent.h>

       extern char **environ;

#define buffer 64
#define LSH_TOK " \t\r\n\a"

char *builtin_str[]={"help","exit","ps","kill"};
int lsh_num_builtins(){
        return sizeof(builtin_str)/sizeof(char *);
}

int isActive(int pid){
        if(kill(pid,0)) return 0;
        return 1;
}

int lsh_ps(char **args){
        /*struct dirent *sd;
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
                if(f) continue;

                int pid=atoi(sd->d_name);


                if(isActive(pid))
                {
                        printf("%s \t", sd->d_name);
                }
        }
        closedir(dir);*/
	execv("./psc.exe", NULL);
        return 1;
}        

int lsh_kill(char **args){
        int psid=atoi(args[1]);
       //kill(psid,SIGKILL);
	//system(strcat("./killc.exe ", args[1]));
	execv("./killc.exe",args[1]);        
	return 1;
}

int lsh_help(char **args){
        int i;
        printf("Following are the commands available\n");
        for(i=0;i<lsh_num_builtins();i++)
                printf("%s ",builtin_str[i]);
        printf("\n");
        printf("Use man command for more\n");
        return 1;
}

int lsh_exit(char **args){
        return 0;
}

int (*builtin_func[])(char **) = {&lsh_help,&lsh_exit,&lsh_ps,&lsh_kill};


char *lsh_read_line(){
        char *line=NULL;
        ssize_t buff=0;
        getline(&line,&buff,stdin);
        return line;
}

void **lsh_split_line(char *line){
        char *token,**tokens_backup;
        int buff=buffer;
        int pos=0;
        char **tokens=malloc(buff*sizeof(char*));
        if(!tokens){
                printf(stderr,"allocation error\n");
                exit(EXIT_FAILURE);
        }
        token=strtok(line,LSH_TOK);
        while(token!=NULL){
                tokens[pos]=token;
                pos++;

               if(pos>=buff){
                        buff+=buffer;
                        tokens_backup=tokens;
                        tokens=realloc(tokens,buff*sizeof(char*));
                        if(!tokens){
                                free(tokens_backup);
                                printf(stderr,"allocation error\n");
                                exit(EXIT_FAILURE);
                        }
                }
                token=strtok(NULL,LSH_TOK);
        }
        tokens[pos]=NULL;
        return tokens;
}

int lsh_launch(){
        pid_t pid,wpid;
        int status;
        pid=fork();

        if(pid==0){ //child process
                
        }
        else if(pid<0) perror("lsh");
        else{
                do{ //parent process
                        wpid=waitpid(pid,&status,WUNTRACED);
                }while(!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return 1;
}

int lsh_execute(char **args){
        if((args[0])==NULL) return 1;
        printf("try");

        for(int i=0;i<lsh_num_builtins();i++){
                if(strcmp(args[0],builtin_str[i])==0){
                        printf("%s \n",builtin_str[i]);

                        printf(args[1]);
                        printf("\n");
                        /*switch(args[0]){
                                case "help": lsh_help(args);
                                case "exit": lsh_exit(args);
                                case "ps": lsh_ps(args);
                                case "kill": lsh_kill(args);
                        }//return(*builtin_func[i])(args);*/

                        if(strcmp(args[0],"help")==0) return lsh_help(args);
                        else if(strcmp(args[0],"exit")==0) return lsh_exit(args);
                        else if(strcmp(args[0],"ps")==0) return lsh_ps(args);
                        else if(strcmp(args[0],"kill")==0) return lsh_kill(args);
                }
        }
        printf("done5\n");
        return lsh_launch(args);

}

void lsh_loop(){
        char *line;
        char **args;
        int status;
        //printf("entered");
        do{
		if(lsh_launch())
		{	                
			printf("-");
		        line=lsh_read_line();
		        args=lsh_split_line(line);
		        status=lsh_execute(args);
		        free(line);
		        printf("\n");
		}
        }while(status);
}
int main(char **argv){
        lsh_loop();
        return EXIT_SUCCESS;
}