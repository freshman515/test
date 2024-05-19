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

	int fd = open("b.c",O_CREAT|O_RDWR,0666);
	write(fd,"hello",strlen("hello"));
    exit(0);
}

