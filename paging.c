#include <stdio.h>
int main()
{
   int ms,np, frameSize, noframes, freeFrames, phyadd,pgno;
   int i,j,x,y,offset;
   int processReq[10]={0}, pageTable[10][20]={0};

   printf("Enter the memory size\n");
   scanf("%d",&ms);

   printf("Enter the size of the frame or page \n");
   scanf("%d",&frameSize);

   noframes=ms/frameSize;
   printf("The number of frames available is %d\n",noframes);

   printf("Enter the number of processes \n");
    scanf("%d",&np);

    freeFrames= noframes;
    for(i=1; i<=np; i++)
    {
        printf("Enter no of frames required for process%d\n", i);
        scanf("%d",&processReq[i]);

        if(processReq[i] > freeFrames)
        {
            printf("Memory is full \n");
            break;
        }
        freeFrames = freeFrames - processReq[i];
        printf("Enter the page table data for the process%d---",i);
       // printf("process requirement is %d \n",processReq[i]);
        for(j=1; j<=processReq[i]; j++)
         scanf("%d",&pageTable[i][j]);
    }

    printf("Enter the logical address to find the physical address\n");
printf("Enter the process no , page no and offset value \n");
    scanf("%d%d%d",&x,&y,&offset);

    if(x>np )
    {  printf("Invalid process no");
        printf("Number of process in the system is %d\n",np);
    }
    else  if(y >= processReq[x])
        {
             printf("invalid page no\n");
             printf("process %d has %d pages\n",x,processReq[i]);
        }
    else if(offset>=frameSize)
    {
       printf("invalid offset value \n");
       printf("Offset value should be less than or equal to %d \n",frameSize);
    }
    else
    {
       phyadd = pageTable[x][y]*frameSize + offset ;
       printf("\n the physical address is --- %d", phyadd);
    }
    return 0;
}
