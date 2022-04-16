//----infix to postfix----//

#include <stdio.h>
#define max 50
//---------------//
char s[max];
int top=-1;
//----PUSH function----//
void push(char elem)
{
    s[++top]=elem;
}
//----pop function----//
char pop()
{
    return (s[top--]);
}
//----precedence-----//
int pr(char elem)
{
    switch(elem)
    {
        case '#':
                    return 0;
        case '(':
                    return 1;
        case '+':
        case '-':
                    return 2;
        case '*':
        case '/':
        case '%':
                    return 3;
        case '^':
                    return 4;
    }
}
//-----main function----//

int main()
{
    char infix[max],pofix[max],ch,elem;
    int i=0,k=0;
    printf("\n\tEnter the INFIX expression:\n");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
            push(ch);
        else if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
            pofix[k++]=ch;
        else if(ch==')')
        {
            while(s[top]!='(')
                pofix[k++]=pop();
            elem=pop();     //---remove ( -----//
        }
        else
        {
            while(pr(s[top])>=pr(ch))
                pofix[k++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#')
        pofix[k++]=pop();
    pofix[k]='\0';
    printf("\n\tPOSTFIX expression:\n%s",pofix);
    return 0;
}
