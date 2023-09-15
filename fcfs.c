#include<stdio.h>
void main()
{
int bt[20],wt[20],tat[20],i,n;
float wtavg,tatavg;
printf("enter no. of processes:");
scanf("%d",&n);
printf("enter bt's");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
wt[0]=wtavg=0;
tat[0]=tatavg=bt[0];
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
wtavg=wtavg+wt[i];
tatavg=tatavg+tat[i];
}
printf("\nPROCESS\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
printf("\np%d\t%d\t%d\t%d\n",i,bt[i],wt[i],tat[i]);
printf("avg wt nd tat %f %f\n",wtavg,tatavg);
}
