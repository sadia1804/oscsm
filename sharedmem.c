//sender

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
void main()
{
int i;
char buffer[100];
void *shared_memory;
int shmid;
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("id of process is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("shared memory address is %p\n",shared_memory);
printf("enter some data\n");
read(0,buffer,100);
strcpy(shared_memory,buffer);
printf("data send is %s\n",(char*)shared_memory);
}

//reciever

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
void main()
{
int i;
char buffer[100];
void *shared_memory;
int shmid;
shmid=shmget((key_t)2345,1024,0666);
printf("id is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("shared memory address is%p\n",shared_memory);
printf("data reciebved is %s\n",(char*)shared_memory);
}
