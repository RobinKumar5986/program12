//----operation on circular queue----//

#include <stdio.h>
#include <stdlib.h>
#define max 10
//----------------//
int q[max];
int front=0,rare=0;
//--------insert--------//
int insert()
{
    int item;
    printf("\nEnter the element:");
    scanf("%d",&item);
    if(front==(rare+1)%max)
        printf("\nQueue is full...!!!\n");
    else
    {
        rare=(rare+1)%max;
        q[rare]=item;
    }
    return q[rare];
}
//--------delete-------//
int delete()
{
    if(front==rare)
        printf("\nQueue is Empty...!!!\n");
    else
    {
        front=(front+1)%max;
    }
    return q[front];
}
//--------display-------//
int display()
{
    int i;
    i=front+1;
    printf("\n\tQueue elements:\n");
    
    for(i;i<=rare;i++)
        printf("%d\n",q[i]);
    printf("\nfront:%d\nrare:%d\n",q[(front+1)%max],q[rare]);
}

//--------main---------//

int main()
{
    int ch,num;
    printf("\n\t-----------MENUE------------\n");
    printf("\n\t\t1.Insert\n\t\t2.Delete\n\t\t3.Dispplay\n\t\t4.exit\n");
    do{
        printf("\n\t\tEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                num=delete();
                printf("\n\tDeleted element:%d\n",num);
                break;
            case 3:
                display();
                break;
        }
    }while(ch!=4);
    printf("\n\t    ---------Thank You----------\n");
    return 0;
}
