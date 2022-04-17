//-----polnomial additon------//
#include <stdlib.h>
#include <stdio.h>
//------structure------//
typedef struct poly
{
    int coeff,x_expo,y_expo,z_expo;
    struct poly *link;
}polynode;
//-------create function-------//
polynode*create(int coeff,int x_expo,int y_expo,int z_expo)
{
    polynode *node;
    node=(polynode*)malloc(sizeof(polynode));
    node->coeff=coeff;
    node->x_expo=x_expo;
    node->y_expo=y_expo;
    node->z_expo=z_expo;
    node->link=NULL;
    return node;
}
//-------attach function-------//
polynode*attachnode(polynode*node,polynode*poly)
{
    polynode *cur;
    cur=poly->link;
    while(cur->link!=poly)
    {
        cur=cur->link;
    }
    cur->link=node;
    node->link=poly;
    return poly;
}
//-------read function-------//
polynode *readpoly()
{
    polynode*poly=(polynode*)malloc(sizeof(polynode));
    poly->link=poly;
    int coef,x_exp,y_exp,z_exp;
    int n,i;
    polynode*temp;
    printf("\n\tEnter the number of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the tern %d:",i+1);
        printf("\nEnter coeff x,y and z:\n");
        scanf("%d%d%d%d",&coef,&x_exp,&y_exp,&z_exp);
        temp=create(coef,x_exp,y_exp,z_exp);
        attachnode(temp,poly);
    }
    return poly;
}
//-------display-------//
void display(polynode*poly)
{
    polynode*cur;
    cur=poly->link;
    while(cur!=poly)
    {
        if(cur->coeff>=0)
            printf("+%dx^%dy^%dz^%d",cur->coeff,cur->x_expo,cur->y_expo,cur->z_expo);
        else
            printf("%dx^%dy^%dz^%d",cur->coeff,cur->x_expo,cur->y_expo,cur->z_expo);
        cur=cur->link;
    }
}
//-------power function-------//
int power(int x,int n)
{
    if(n==0)
        return 1;
    return x*power(x,n-1);
}
//-------evaluate function-------//
void evaluate(polynode*poly1)
{
    polynode*poly;
    int x,y,z, xval,yval,zval,sum=0;
    poly=poly1->link;
    printf("\nEnter the value of x,y and z:\n");
    scanf("%d%d%d",&x,&y,&z);
    while(poly!=poly1)
    {
        xval=power(x,poly->x_expo);
        yval=power(y,poly->y_expo);
        zval=power(z,poly->z_expo);
        sum=sum+(poly->coeff*xval*yval*zval);
        poly=poly->link;
    }
    printf("\nResult:%d",sum);
}
//-------add function-------//
polynode*addpoly(polynode*poly1,polynode*poly2,polynode*poly)
{
    int comp;
    polynode *a,*b,*temp;
    a=poly1->link;
    b=poly2->link;
    while(a!=poly1&&b!=poly2)
    {
        if(a->x_expo==b->x_expo&&a->y_expo==b->y_expo&&a->z_expo==b->z_expo)
            comp=0;
        else if(a->x_expo>b->x_expo)
            comp=1;
        else if(a->x_expo==b->x_expo&&a->y_expo>b->y_expo)
            comp=1;
        else if(a->x_expo==b->x_expo&&a->y_expo==b->y_expo&&a->z_expo>b->z_expo)
            comp=1;
        else
            comp=-1;
        switch(comp)
        {
            case 0:temp=create(a->coeff+b->coeff,a->x_expo,a->y_expo,a->z_expo);
                    poly=attachnode(temp,poly);
                    a=a->link;
                    b=b->link;
                    break;
            case 1:temp=create(a->coeff,a->x_expo,a->y_expo,a->z_expo);
                    poly=attachnode(temp,poly);
                    a=a->link;
                    break;
            case -1:temp=create(b->coeff,b->x_expo,b->y_expo,b->z_expo);
                    poly=attachnode(temp,poly);
                    b=b->link;
                    break;
        }
    }
    while(a!=poly1)
    {
        temp=create(a->coeff,a->x_expo,a->y_expo,a->z_expo);
        poly=attachnode(temp,poly);
        a=a->link;
    }
    while(b!=poly2)
    {
        temp=create(b->coeff,b->x_expo,b->y_expo,b->z_expo);
        poly=attachnode(temp,poly);
        b=b->link;
    }
    return poly;
}
int main()
{
    int ch;
    polynode*poly1,*poly2,*poly3;
    poly3=(polynode*)malloc(sizeof(polynode));
    poly3->link=poly3;
    while(1)
    {
        printf("\n\t---------MENUE----------\n");
        printf("\n\t1.Represent and evaluate\n\t2.Add two polynomial\n\t3.exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the polynomial:\n");
                    poly1=readpoly();
                    display(poly1);
                    evaluate(poly1);
                    break;
            case 2:printf("\nEnter poly1:\n");
                    poly1=readpoly();
                    display(poly1);
                    printf("\nEnter poly2:\n");
                    poly2=readpoly();
                    display(poly2);
                    printf("\nResultent polynomial:\n");
                    poly3=addpoly(poly1,poly2,poly3);
                    display(poly3);
                    break;
            case 3:
                    exit(0);
            default:printf("\nInvalid choice...!\n");
        }
        
    }

    return 0;
}
