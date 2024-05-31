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
	int fd1 = open("a.c",O_RDWR);
	int fd2 = open("b.c",O_RDWR);
	char buf1[50],buf2[50]; 	
	int len1 = read(fd1,buf1,sizeof(buf1));
	int len2 = read(fd2,buf2,sizeof(buf2));
	ftruncate(fd1,0);
	ftruncate(fd2,0);
	lseek(fd1,0,SEEK_SET);
	lseek(fd2,0,SEEK_SET);
	write(fd1,buf2,len2);
	write(fd2,buf1,len1);
	execlp("cat","cat","/home/xmf/warehouse/system/a.c","/home/xmf/warehouse/system/b.c",NULL);
    exit(0);
}

