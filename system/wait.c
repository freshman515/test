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
	pid_t pid = fork();
	assert(pid>=0);
	int status;
	if(pid > 0)
	{
		printf("i am parent ,my pid is %d \n",getpid());
		wait(&status);
	

	}
	else
	{
		for(int i = 0;i<5;i++)
		{
			printf("-------\n");
			sleep(1);
		}
		exit(5);
	}
	printf("child process exit status is %d\n",WEXITSTATUS(status));

    exit(0);
}

