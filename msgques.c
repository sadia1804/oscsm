//sender

#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
struct buffer
{
long msg_type;
char msg[100];
}message;
void main()
{
int msg_id;
key_t my_key;
my_key=ftok("linux",66);
msg_id=msgget(my_key,0666|IPC_CREAT);
message.msg_type=1;
printf("enter message:");
fgets(message.msg,100,stdin);
msgsnd(msg_id,&message,sizeof(message),0);
printf("message sent is %s\n",message.msg);
}

//reciever

#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
struct buffer
{
long msg_type;
char msg[100];
}message;
void main()
{
int msg_id;
key_t my_key;
my_key=ftok("linux",66);
msg_id=msgget(my_key,0666|IPC_CREAT);
msgrcv(msg_id,&message,sizeof(message),1,0);
printf("messaged recieved is  %s\n",message.msg);
}
