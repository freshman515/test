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
	int pid = fork();
	int count = 0;
	if(pid == 0)
	{
		printf("i am son , pid = %d\n, count = %d\n",pid,count);
		count ++;
		printf("i am son , pid = %d\n, count = %d\n",pid,count);
		
	}		
	else  
		printf("i am parent,my son pid  =%d, my pid = %d\n",pid,getpid());
	printf("count = %d\n",count);

    exit(0);
}

