/*
Refer question 1 in practice-08
solving using dfs
*/
#include<stdio.h>
#define n 7

void conn_to_A(int node,int graph[][n+1], int vis[n+1], char ch[n+1] )
{
    vis[node] = 1;
    for (int  i = 1; i <=n; i++)
    {
        if (graph[node][i] == 1)
        {
            vis[i] = 1;
            printf("%c ",ch[i]);

        }
        
    }
    
}

void find_pred(int graph[][n+1], char ch[n+1])
{
    for (int i = 1; i <=n; i++)
    {
        
    }
    
}
int main()
{   
    int graph[n+1][n+1];
    int vis[n+1] = {0};
    char node[] = {'0','A','b','c','d','e','f','g'};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            scanf("%d",&graph[i][j]);
        }
        
    }
    conn_to_A(1, graph, vis, node);
    find_pred(graph, node);
    
}