//-----hashing function------//

#include <stdio.h>
#include<stdlib.h>
#define max 50
//-----------//
int create(int);
void l_prob(int[],int,int);
void display(int[]);
//-----------//
int main()
{
    int a[max],num,key,i;
    printf("COLLISION HANDLING WITH LINEAR PROBING");
    /*Initial value in hase table */
    for(int i=0;i<max;i++)
    {
        a[i]=-1;
    }
    int ans;
    while(ans){
        printf("\nentern the data");
        scanf("%4d",&num);
        key=create(num);
        l_prob(a,key,num);
        printf("\nDo you wish to continue?(1/0)");
        scanf("%d",&ans);
    }
    display(a);
    return 0;
}

//-----------create----------//
int create(int num){
    int key;
    key=num%10;
    return key;
}
//-----------linear probing----------//
void l_prob(int a[max],int key,int num){
    int i,count=0;
    if(a[key]==-1)
        a[key]=num;
    else{
        printf("\nCOLLISION DETECTED");
        i=0;
        while(i<max){
            if(a[i]!=-1)
            count++;
            i++;
        }
        if(count==max){
            printf("\ntable is full");
            display(a);
            exit(0);
        }
        printf("\ncollision avoided successfully by linear probing...");

        for(i=key+1;i<max;i++){
            if(a[i]==-1){
                a[i]=num;
                break;
            }
        }
        i=0;
        for(i;i<key;i++){
            if(a[i]==-1){
                a[i]=num;
                break;
            }
        }
        
    }
}

//-----------display---------//
void display(int a[max]){
    int i,n;
    printf("\n1.Display all\n2.Filterd display");
    scanf("%d",&n);
    if(n==1){
        for(i=0;i<max;i++){
            printf("\n %d\t%d",i,a[i]);
        }
    }
    else if(n==2){
        for(i=0;i<max;i++){
            if(a[i]!=-1)
            printf("\n%d\t%d",i,a[i]);
        }
    }
    else
    printf("invalid input....");
}
