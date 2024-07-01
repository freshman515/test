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
void* hello(void* str)
{
	for(int i=0;i<7;i++)
	{
		printf("%s\n",(char*)str);
		sleep(1);
	}
	
}
int main(int argc,char *argv[])
{
	pthread_t pid;
	int ret;
	ret = pthread_create(&pid,NULL,hello,"hello,world");
	if(ret){
		fprintf(stderr,"pthread_create err:%s\n",strerror(ret));
		exit(1);
	}
	
	
	sleep(4);
	ret = pthread_cancel(pid);
	if(ret){
		fprintf(stderr,"pthread_ret err:%s\n",strerror(ret));
		exit(1);
	}
	pthread_join(pid,NULL);	
    exit(0);
}

