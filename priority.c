#include<stdio.h>
void main()
{
int bt[20],wt[20],tat[20],p[20],pri[20],i,n,k,temp;
float wtavg,tatavg;
printf("enter no. of processes:");
scanf("%d",&n);
printf("enter bt's nd pri's:");
for(i=0;i<n;i++)
{
p[i]=i;
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
//p[i]=i;
scanf("%d",&pri[i]);
}
for(i=0;i<n;i++)
{
for(k=i+1;k<n;k++)
{
if(pri[i]>pri[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;
}
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=pri[k];
pri[k]=temp;
}
wt[0]=wtavg=0;
tat[0]=tatavg=bt[0];
}
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i-1];
wtavg=wtavg+wt[i];
tatavg=tatavg+tat[i];
}
printf("\nprocess\tbt\twt\ttat\n");
for(i=0;i<n;i++)
printf("\np%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
printf("wtavg=%f, tatavg=%f",wtavg,tatavg);
}
