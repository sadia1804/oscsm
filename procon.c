#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10;
int data=0;
void producer()
{
--mutex;
++full;
--empty;
data++;
printf("\n producer produces %d data\n",data);
++mutex;
}
void consumer()
{
--mutex;
--full;
++empty;
printf("consumer consumes %d data\n",data);
data--;
++mutex;
}
int main()
{
int i,ch;
printf("\n1.producer\n2.consumer\n3.exit\n");
for(i=1;i>0;i++)
{
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
  if((mutex==1)&&(empty!=0))
  {
producer();
}
  else
  {
printf("buffer full\n");
}
  break;
case 2:
  if((mutex==1)&&(full!=0))
  {
consumer();
}
  else
  {
printf("buffer emmty\n");
}
  break;
case 3:
  exit(0);
  break;
}
}
}
