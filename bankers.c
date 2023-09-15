#include<stdio.h>
//#include<conio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r,i,j;
void input();
void show();
void cal();
int main()
{
input();
show();
cal();
//getch();
return 0;
}
void input()
{
printf("enter no. of processes:");
scanf("%d",&n);
printf("enter no. of  resources:");
scanf("%d",&r);
printf("max matrix");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("allocation matrix");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&alloc[i][j]);
}
}
printf("enter available resoources:");
for(j=0;j<r;j++)
{
scanf("%d",&avail[j]);
}
}
void show()
{
printf("process\tmax\tallocation\tavailable\n");
for(i=0;i<n;i++)
{
printf("\nP%d\t",i+1);
for(j=0;j<r;j++)
{
printf("%d\t",alloc[i][j]);
}
for(j=0;j<r;j++)
{
printf("%d\t",max[i][j]);
}
if(i==0)
{
for(j=0;j<r;j++)
printf("%d",avail[j]);
}
}
}
void cal()
{
int finish[100],safe[100],flag=1,k,cl=0;
for(i=0;i<n;i++)
{
finish[i]=0;
}
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
printf("\n");
while(flag)
{
flag=0;
for(i=0;i<n;i++)
{
int c=0;
for(j=0;j<r;j++)
{
if((finish[i]==0)&&(need[i][j]<=avail[j]))
{
c++;
if(c==r)
{
for(k=0;k<r;k++)
{
avail[k]+=alloc[i][j];
finish[i]=1;
flag=1;
}
printf("P%d->",i);
if(finish[i]=1)
{
i=n;
}
}
}
}
}
}
for(i=0;i<n;i++)
{
if(finish[i]==1)
{
cl++;
}
else
{
printf("P%d->",i);
}
}
if(cl==n)
{
printf("\n the sys is safe");
}
else
{
printf("\ndeadlock");
printf("\n unsafe");
}
}
