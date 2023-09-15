#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
void main()
{
mkfifo("fifo",0777);
printf("name pipe created");
}

//senders
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
int res;
res=open("fifo1",O_WRONLY);
write(res,"hello",4);
printf("sending done with %d\n",getpid());
}

//reciever
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
int res,n;
char buffer[100];
res=open("fifo1",O_RDONLY);
n=read(res,buffer,100);
printf("reader process %d shared\n",getpid());
printf("data recieved by %d is %s \n",getpid(),buffer);
}
