#include<stdio.h>
void main()
{
int bt[20],wt[20],tat[20],ct[20],i,n,k,t,max;
float wtavg=0,tatavg=0,temp=0;
printf("enter no. of processes:");
scanf("%d",&n);
printf("enter bt's:");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
ct[i]=bt[i];
}
printf("enter time slice:");
scanf("%d",&t);
max=bt[0];
for(i=1;i<n;i++)
{
if(max>bt[i])
 max=bt[i];
}
for(k=0;k<(max/t);k++)
{
for(i=0;i<n;i++)
{
if(bt[i]!=0 && bt[i]<=t)
{
tat[i]=temp+bt[i];
temp=temp+bt[i];
bt[i]=0;
}
else
{
bt[i]=bt[i]-t;
temp=temp++;
}
wt[i]=tat[i]-ct[i];
wtavg=wtavg+wt[i];
tatavg=tatavg+tat[i];
}
}
printf("\nprocess\tbt\twt\ttat\n");
for(i=0;i<n;i++)
printf("\np%d\t%d\t%d\t%d\n",i+1,ct[i],wt[i],tat[i]);
printf("wtavg=%f, tatavg=%f",wtavg,tatavg);
}
