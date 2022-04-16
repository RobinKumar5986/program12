//---Tower of henoi---//
#include <stdio.h>
#include <math.h>
void tower(int,char,char,char);
int main()
{
    int num;
    printf("\n\tEnter the number of disks:");
    scanf("%d",&num);
    printf("\n\tThe sequence of moving disks:\n");
    tower(num,'A','B','C');
    printf("\nnumber of steps:%d",(int)pow(2,num)-1);
    return 0;
}
void tower(int num,char A,char B,char C)
{
    if(num==1)
    {
        printf("\nmove disk 1 from peg %c to peg %c\n",A,B);
        return;
    }
    tower(num-1,A,C,B);
    printf("\nmove disk %d from peg %c to peg %c",num,A,B);
    tower(num-1,C,A,B);
}