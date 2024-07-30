#include <stdio.h>
#include <stdlib.h>
void Dijkstras(int cost[10][10],int n,int source)
{
    int i,u,v,count=1,distance[10],visited[10],min;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        distance[i]=cost[source][i];
    }
    visited[source]=1;
    distance[source]=0;
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0&&distance[i]<min)
            {
                min=distance[i];
                u=i;
            }
        }
        visited[u]=1;
        count++;
        for(i=1;i<=n;i++)
        {
            if(distance[i]>distance[u]+cost[u][i])
                distance[i]=distance[u]+cost[u][i];
        }
    }
    printf("Shortest path from %d",source);
    for(i=1;i<=n;i++)
        printf("\n %d to %d is %d",source,i,distance[i]);
}
int main()
{
     int n,cost[10][10],i,j,source;
    printf("\nRead no:of nodes: ");
    scanf("%d",&n);
    printf("\nRead source: ");
     scanf("%d",&source);
    printf("\nRead cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    Dijkstras(cost,n,source);
    return 0;
}
