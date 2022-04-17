//-----Array opration------//

#include<stdio.h>
//------global varieable-------//
int arr[50];
int n=-1;
//---functions prototype---//
void create();
void insert();
void delete();
void display();
//----main function-----//

void main()
{
    int ch;
    printf("\n----------MENUE-----------\n");
    printf("\n\t1.CREATE\n\t2.INSERT\n\t3.DELETE\n\t4.DISPLAY\n\t5.EXIT");  
    while(ch!=5)
    {
        printf("\n\tEnter your coice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:insert();break;
            case 3:delete();break;
            case 4:display();break;
        }
    }
}
//-------create function-----//
void create()
{
    int item;
    printf("\n\tEnter the number of term:");
    scanf("%d",&n);
    printf("\nEnter the values:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        arr[i]=item;
    }
}
//-------insert function-----//
void insert()
{
    int item,po;
    if(n==-1)
    {
        printf("\nfirst create an array...!!");
    }
    else
    {
        printf("\nEnter the position:");
        scanf("%d",&po);
        printf("\n\nenter the value:");
        scanf("%d",&item);
        for(int i=n-1;i>=po;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[po]=item;
        n=n+1;
    }
}
//-------delete function-----//
void delete()
{
    int po;
    if(n==-1)
    {
        printf("\nEMPTY array...!!!");
    }
    else{
        printf("\nEnter the position:");
        scanf("%d",&po);
        printf("\nDeleted element:%d",arr[po]);
        for(int i=po;i<=n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        n--;
    }
}
//-------display function-----//
void display()
{
    printf("\n\tElements are:\n");
    for(int i=0;i<n;i++)
        printf("\t%d",arr[i]);
}