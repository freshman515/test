#include <stdio.h>
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
	pid_t pid;
	pid = fork();
	assert(pid != -1);
	if(pid == 0)
	{
		execlp("ps","ps","-aux",NULL);
		perror("execl perror");
		exit(1);
	}
	else
		printf("i am parent,my pid  = %d \n",getpid());
    exit(0);
}

