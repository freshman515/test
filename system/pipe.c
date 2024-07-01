#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <pthread.h>
void sys_err(const char * error)
{
	perror(error);
	exit(1);
}
int main(int argc,char *argv[])
{
	int fd[2];
	pipe(fd);
	fflush(NULL);
	pid_t pid = fork();
	if(pid == 0)
	{
		char str[20];
		read(fd[0],str,sizeof(str));
		printf("i am son, i am reading all data,it is %s\n",str);
	}
	else
	{
		write(fd[1],"hello world",strlen("hello world"));
		wait(NULL);
	}
	
    exit(0);
}

