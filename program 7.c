//------operation on SLL-------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-------structure-------//
typedef struct node
{
    int ph;
    char name[20];
    struct node*next;
}node;
//------------------------//
node *temp,*h,*t;
int count=0;
//--------create----------//
void create()
{
    char name[20];
    int ph;
    temp=(node*)malloc(sizeof(node));
    printf("\nenter the name and phone no:");
    scanf("%s %d",name,&ph);
    strcpy(temp->name,name);
    temp->ph=ph;
    temp->next=NULL;
    count++;
}
//------insert at end---------//
void insert_end()
{
    if(h==NULL)
    {
        create();
        h=temp;
        t=temp;
    }
    else
    {
        create();
        t->next=temp;
        t=temp;
    }
}
//------insert at beg----------//
void insert_beg()
{
    if(h==NULL)
    {
        create();
        h=temp;
        t=temp;
    }
    else
    {
        create();
        temp->next=h;
        h=temp;
    }
}
//--------delete at end---------//
void delete_end()
{
    node*temp;
    temp=h;
    if(h==NULL)
    printf("\nEMPTY LIST...!!!\n");
    else if(temp->next==NULL)
    {
        printf("\n\tDeleted node data\nName:%s\nph no:%d\n",temp->name,temp->ph);
        free(temp);
        h=NULL;
        count--;
    }
    else
    {
        while(temp->next!=t)
        temp=temp->next;
        printf("\n\tDeleted node data\nName:%s\nph no:%d\n",t->name,t->ph);
        free(t);
        t=temp;
        t->next=NULL;
        count--;
    }
}
//--------delete at beg----------//
void delete_beg()
{
    node*temp;
    temp=h;
    if(h==NULL)
        printf("\nEMPTY LIST...!!!\n");
    else if(temp->next==NULL)
    {
        printf("\n\tDeleted node data\nName:%s\nph no:%d\n",temp->name,temp->ph);
        free(temp);
        h=NULL;
        count--;
    }
    else
    {
        h=h->next;
        printf("\n\tDeleted node data\nName:%s\nph no:%d\n",temp->name,temp->ph);
        free(temp);
        count--;
    }
}
//---------Display-----------//
void display()
{
    node*temp;
    temp=h;
    if(h==NULL)
    printf("\nList is Empty...!!!\n");
    else
    {
        printf("\n\tStudent Data:\n");
        while(temp!=NULL)
        {
            printf("\nName:%s\nph no:%d\n",temp->name,temp->ph);
            temp=temp->next;
        }
    }
}


int main()
{
    int n,ch;
    temp=h=t=NULL;
    printf("\n\t------------MENUE-------------\n");
    printf("\n\t\t1.create\n\t\t2.Display\n\t\t3.Insert at end");
    printf("\n\t\t4.Delete at end\n\t\t5.Insert at beg");
    printf("\n\t\t6.Delete at end\n\t\t7.exit");
    printf("\n");
    do
    {
        printf("\n\t\tenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nenter the no of student:");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                    insert_end();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                insert_beg();
                break;
            case 6:
                delete_beg();
                break;
        }
        
    }while(ch!=7);
    
    return 0;
}
