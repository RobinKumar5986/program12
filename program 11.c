//-----BFS DFS operaton-----//
#include <stdio.h>
#include <stdlib.h>
//-----------------//
int a[20][20],q[20],visited[20],reach[10],n,i,j,f=0,r=-1,count=0;

//-------BFS------//
void bfs(int v)
{
    for(i=1;i<=n;i++)
        if(a[v][i]&&!visited[i])
    q[++r]=i;
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}
//-------DFS-------//
void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]&&!reach[i])
        {
            printf("\n%d->%d",v,i);
            count++;
            dfs(i);
        }
    }
}
//------main-------//
void main()
{
    int v,ch;
    printf("\n\tEnter the number of vertex:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    for(i=1;i<=n;i++)
        reach[i]=0;
    printf("\n\tEnter the graph data in metrix form:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("\n\t-----MENUE------\n");
    printf("\n\t1.BFS\n\t2.DFS\n\t3.EXIT\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter the starting vertex:");
                scanf("%d",&v);
                bfs(v);
                if((v<1)||(v>n))
                    printf("\nBFS not possible...!!!");
                else
                {
                    printf("\n\tThe nodes which are reachable from %d is:\n",v);
                    for(i=1;i<=n;i++)
                        if(visited[i])
                            printf("%d\t",i);
                }
                break;
        case 2:dfs(1);
                if(count==n-1)
                    printf("\nGraph is connected");
                else
                    printf("\nGraph is not connected");
                break;
        case 3:
                exit(0);
                
    }
}
