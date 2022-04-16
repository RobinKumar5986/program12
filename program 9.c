/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
//----------------//
typedef struct poly{
    int coef;
    int Xexpo;
    int Yexpo;
    int Zexpo;
}poly;
//-------represent---------//
void represent()
{
    int n,c,x,y,z;
    poly a[50];
    printf("\nenter the number of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\ncoef:");
        scanf("%d",&a[i].coef);
        printf("\nx expo:");
        scanf("%d",&a[i].Xexpo);
        printf("\ny expo:");
        scanf("%d",&a[i].Yexpo);
        printf("\nz expo:");
        scanf("%d",&a[i].Zexpo);
    }
    //------display---------//
    printf("\nExpression is:");
    int j=0;
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i].coef);
        if(a[i].Xexpo>0)
        printf("X^%d",a[i].Xexpo);
        if(a[i].Yexpo>0)
        printf("X^%d",a[i].Yexpo);
        if(a[i].Zexpo>0)
        printf("X^%d",a[i].Zexpo);
        if((j<n-1)&&(a[i+1].coef>0)){
            printf("+");
            j++;
        }
        else
        {
            j++;
        }
    }
}
//------add-------//
void add(){
    poly a[50],b[50],ans[100];
    int n1,n2;
    printf("\nenter the number of term in poly_1:");
    scanf("%d",&n1);
    printf("\nenter the number of term in poly_2:");
    scanf("%d",&n2);
    printf("\n\t\t\tEnter poly_1 data:");
    for(int i=0;i<n1;i++)
    {
        printf("\ncoef:");
        scanf("%d",&a[i].coef);
        printf("\nx expo:");
        scanf("%d",&a[i].Xexpo);
        printf("\ny expo:");
        scanf("%d",&a[i].Yexpo);
        printf("\nz expo:");
        scanf("%d",&a[i].Zexpo);   
    }
    printf("\n\t\t\tEnter poly_2 data:");
    for(int i=0;i<n2;i++)
    {
         printf("\ncoef:");
        scanf("%d",&b[i].coef);
        printf("\nx expo:");
        scanf("%d",&b[i].Xexpo);
        printf("\ny expo:");
        scanf("%d",&b[i].Yexpo);
        printf("\nz expo:");
        scanf("%d",&b[i].Zexpo);
    }
    //------add-------//
    int i=0,k=0;
    while(i<n1&&i<n2){
        for(k;k<n2;k++)
        {
        if(a[k].Xexpo==b[k].Xexpo&&a[k].Yexpo==b[k].Yexpo&&a[k].Zexpo==b[k].Zexpo)
        {
            ans[k].coef=a[k].coef+b[i].coef;
            ans[k].Xexpo=a[k].Xexpo;
            ans[k].Yexpo=b[k].Yexpo;
            ans[k].Zexpo=b[k].Zexpo;
        }
        }
        else if ((a[i].Xexpo+a[i].Yexpo+a[i].Zexpo)>(b[i].Xexpo+b[i].Yexpo+b[i].Zexpo))
        {
            ans[i].coef=a[i].coef;
            ans[i].Xexpo=a[i].Xexpo;
            ans[i].Yexpo=a[i].Yexpo;
            ans[i].Zexpo=a[i].Zexpo;
            //--------------//
            ans[i+1].coef=b[i].coef;
            ans[i+1].Xexpo=b[i].Xexpo;
            ans[i+1].Yexpo=b[i].Yexpo;
            ans[i+1].Zexpo=b[i].Zexpo;
            i++;
        }
        else if ((a[i].Xexpo+a[i].Yexpo+a[i].Zexpo)<(b[i].Xexpo+b[i].Yexpo+b[i].Zexpo))
        {
            ans[i].coef=b[i].coef;
            ans[i].Xexpo=b[i].Xexpo;
            ans[i].Yexpo=b[i].Yexpo;
            ans[i].Zexpo=b[i].Zexpo;
            //--------------//
            ans[i+1].coef=a[i].coef;
            ans[i+1].Xexpo=a[i].Xexpo;
            ans[i+1].Yexpo=a[i].Yexpo;
            ans[i+1].Zexpo=a[i].Zexpo;
            i++;
        }
        i++;
    }
    //--------------//
    //int i=0;
    if(n1>n2)
    {
        for(i;i<n1;i++)
        {
            ans[i].coef=a[i].coef;
            ans[i].Xexpo=a[i].Xexpo;
            ans[i].Yexpo=a[i].Yexpo;
            ans[i].Zexpo=a[i].Zexpo;
        }
    }
    //i=0;
    if(n2>n1)
    {
        for(i;i<n2;i++)
        {
            ans[i].coef=b[i].coef;
            ans[i].Xexpo=b[i].Xexpo;
            ans[i].Yexpo=b[i].Yexpo;
            ans[i].Zexpo=b[i].Zexpo;
        }
    }
    //------display---------//
   int j=0;
   for(j;j<=i;j++)
   {
       printf("%dX^%dY^%dZ^%d+",ans[j].coef,ans[j].Xexpo,ans[j].Yexpo,ans[j].Zexpo);
   }
   printf("\n%d",ans[0].coef);
   printf("\n%d",ans[1].coef);
   printf("\n%d",ans[2].coef);
}


int main()
{
    int ch;
    while(ch!=3){
        printf("\n1.Represent in p(x,y,z) form\n2.Add two polynomial\n3.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:represent();
            break;
            case 2:add();
            break;
        }
    }
    return 0;
}
