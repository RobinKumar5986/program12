//-----postfix elaluation-------//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max 50
int num[max];
char post[max];
int top= -1;
void push(int i);
void cal(char c);

int main()
{
    printf("\n\tEnter the expression:\n");
    scanf("%s",post);
    int i=0;
    for(i=0;i<strlen(post);i++)
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            push(i);
        }
        if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^')
        {
            cal(post[i]);
        }
    }
    printf("\nResult::%d",num[top]);

    return 0;
}
//--------------//
void push(int i)
{
    top++;
    num[top]=(int)(post[i]-48);
}
//--------------//
void cal(char c)
{
    int a,b,ans;
    a=num[top];
    num[top]='\0';
    top--;
    b=num[top];
    num[top]='\0';
    top--;
    switch(c)
    {
        case '+':ans=b+a;
        break;
        case '-':ans=b-a;
        break;
        case '*':ans=b*a;
        break;
        case '/':ans=b/a;
        break;
        case'^':ans=pow(b,a);
        break;
        default:ans=0;
    }
    top++;
    num[top]=ans;
}
