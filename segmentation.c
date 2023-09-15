#include<stdio.h>
int main()
{
int i,segtble[10][2],noseg,segno,baseadd,phyadd,size,offset;
printf("enter segments for process\n");
scanf("%d",&noseg);
for(i=0;i<noseg;i++)
{
printf("enter limit value and base value for process %d\n",i);
scanf("%d%d",&segtble[i][0],&segtble[i][1]);
}
printf("following r the values given by users\n");
printf("segment value        limit       base address\n");
for(i=0;i<noseg;i++)
{
printf("%d       %d      %d",i,segtble[i][0],segtble[i][1]);
printf("\n");
}
while(1)
{
printf("enter logical address(segno and offset value)\n");
scanf("%d%d",&segno,&offset);
if(segno>noseg)
printf("invalid segno\n");
else if(offset>segtble[segno][0])
printf("invalid offset\n");
else
{
phyadd=segtble[segno][1]+offset;
printf("base address is %d\n",segtble[segno][1]);
printf("physical address is %d\n",phyadd);
}
}
return 0;
}
