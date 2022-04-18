//----BFS DFS operation-----//

#include <stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visited[20],reach[10],n,i,j,f=0,r=-1,count=0;
//----bfs----//
void bfs(int v)
{
    for(i=1;i<=n;i++){
        if(a[v][i]&&!visited[i])
        q[++r]=i;
        if(f<=r){
            visited[q[f]]=1;
            bfs(q[f++]);
        }
    }
}

int main()
{
    int v,choice;
    printf("\nEnter the number of CITIES:");
    scanf("%d",&n);
    //----bfs initilaztion----//
    for(i=1;i<=n;i++){
        q[i]=0;
        visited[i]=0;
    }
    //------data input-------//
    printf("\nEnter the data:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    printf("1.BFS\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter the ROOT vertex:");
            scanf("%d",&v);
            bfs(v);
            if((v<1)||(v>n)){
                printf("BFS is not possible...!!!");
            }
            else{
                printf("the node which are rechable form %d:",v);
                for(i=1;i<=n;i++){
                    if(visited[i])
                    printf("%d ",i);
                }
            }
            break;
        default:printf("invalid choice...!!!");
                exit(0);
    }
    return 0;
}
