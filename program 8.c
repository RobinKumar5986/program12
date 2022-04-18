//-----operation on DLL-------//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char name[20];
    char usn[20];
    struct node *prev;
    struct node *next;
}node;
//------------//
node *h,*temp,*temp1;
int count=0;
//------------create function----------//
void create()
{
    char name[20],usn[20];
    temp=(node*)malloc(sizeof(node));
    temp->prev=NULL;
    temp->next=NULL;
    printf("\nEnter the name and usn:\n");
    scanf("%s %s",name,usn);
    strcpy(temp->name,name);
    strcpy(temp->usn,usn);
    count++;
}
//----------inser beg-------//
void insertbeg()
{
    if(h==NULL)
    {
        create();
        h=temp;
        temp1=h;
    }
    else
    {
        create();
        h->prev=temp;
        temp->next=h;
        h=temp;
        
    }
}
//----------inser end--------//
void insertend()
{
    if(h==NULL)
    {
        create();
        h=temp;
        temp1=h;
    }
    else
    {
        create();
        temp1->next=temp;
        temp->prev=temp1;
        temp1=temp;
    }
}
//------------delete beg-------//
void deletebeg()
{
    node*temp;
    temp=h;
    
    if(h==NULL)
    {
        printf("\nList is empty...!!!\n");
    }
    else if(temp->next==NULL)
    {
        printf("\n\t\tDeleted(beg) NODE data\nname:%s\nusn:%s\n",temp->name,temp->usn);
        free(temp);
        h=NULL;
        count--;
    }
    else
    {
        h=h->next;
        printf("\n\t\tDeleted(beg) NODE data\nname:%s\nusn:%s\n",temp->name,temp->usn);
        free(temp);  
        count--;
    }
    
}
//------------delete end-------//
void deleteend()
{
    node*temp;
    temp=temp1;
    if(h==NULL)
        printf("\nList is empty...!!!\n");
    else if(h->next==NULL)
    {
        printf("\n\tDeleted(end) NODE data\nusn:%s\nname:%s\n",h->usn,h->name);
        free(h);
        h=NULL;
        count--;
    }
    else
    {
        temp1=temp1->prev;
        temp1->next=NULL;
        printf("\n\tDeleted(end) NODE data\nusn:%s\nname:%s\n",temp->usn,temp->name);
        free(temp);
        count--;
        
    }
}
//------------display----------//
void displaybeg(){
    node*temp;
    temp=h;
    if(temp==NULL)
        printf("\nList is empty...!!!\n");
        
    else
    {
        for(int i=0;i<count;i++)
        {
            printf("\nusn:%s\nname:%s\n",temp->usn,temp->name);
            temp=temp->next;
        }
    }
        
    printf("\nTotal number of employes:%d\n",count);
}
//------------------------------//
int main()
{
    int ch,n,i;
    h=NULL;
    temp=temp1=NULL;
    printf("\n------------MENUE------------\n");
    printf("\n1.Create\n2.Display from begning\n3.Inser at end");
    printf("\n4.Delete at end\n5.Isert at beg\n6.Delete beg\n7.exit\n");
    while(ch!=7)
    {
        printf("\n\t\tEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the no of employes:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    insertend();
                }
                break;
            case 2:
                displaybeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                insertbeg();
                break;
            case 6:
                deletebeg();
                break;
            case 7:
                exit(0);
            default:
                printf("\ninvalid input...!\n");
                exit(0);
        }
    }
    return 0;
}
