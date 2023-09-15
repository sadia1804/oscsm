#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
int fd[2],n;
char buffer[100];
pid_t pipe(fd);
int p;
p=fork();
if (p>0)
{
printf("parent process sending");
write(fd[1],"hello \n",8);
wait(0);
}
else
{
printf("child recieving process");
n=read(fd[0],buffer,100);
write(1,buffer,n);
}
}
