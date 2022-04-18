//-----stack operation(palindreome)----//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 5
//-------------//
int stack[max],top=-1;
//----function prototype----//
void push();
void pop();
void display();
void pali();

//-----main function--------//
void main()
{
    int ch;
    printf("\n\t--------MENUE---------\n");
    printf("\n\t1.PUSH\n\t2.POP\n\t3.Palindreome\n\t4.Display\n\t4.exit\n");
    while(1)
    {
        printf("\n\tEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:pali();
                    break;
            case 4:display();
                    break;
            case 5:exit(0);
            default:printf("\nInvalid input...!!!");
        }
    }
}

//--------push function--------//
void push()
{
    int elem;
    if(top==max-1)
        printf("\nSTACK OVERFLOW...!!!");
    else
    {
        printf("\nEnter the element:");
        scanf("%d",&elem);
        stack[++top]=elem;
    }
}
//--------pop function--------//
void pop()
{
    int item;
    if(top==-1)
        printf("\nSTACK UNDERFLOW...!!!");
    else
    {
        item=stack[top--];
        printf("\nDeleted element:%d",item);
    }
}
//--------desplay function--------//
void display()
{
    int i=top;
    if(top==-1)
        pop();
    else
    {
        printf("\n\tElements are:\n");
        for(i;i>=0;i--)
            printf("%d\t",stack[i]);
    }
}
//------palindrome-------//
void pali()
{
    int j,k,length=0;
    int rev[top+!];
    int x=top;
    int i=0;
    while(x!=-1)
        rev[i++]=stack[x--];
    printf("\nNumbers:\n");
    for(j=0;j<len;j++)
        printf("%d\t",rev[j]);
    
    for(k=0;k<len;k++)
    {
        if(rev[k]==stack[k])
            length++;
    }
    if(top+1==length)
    {
       printf("\npalindrome...!!!");
    }
    else
    {
        printf("\nNOT Palindreome...!!!");
    }
    
}
