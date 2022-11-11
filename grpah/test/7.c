/*
 * counting the no of provinces
 */
#include<stdio.h>
#define n 8

void dfs(int node, int (*graph)[n+1], int *vis)
{
    vis[node] = 1;
    // printf("%d ", node);
    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && vis[i] == 0)
        {
            dfs(i, graph, vis);
            /* code */
        }
        
        
        /* code */
    }
    
}
int main()
{   
    int graph[n+1][n+1];
    int vis[n+1] = {0};
    int edge_1, edge_2, node,no_of_edges, count;
    node = 3;
    count = 0;
    scanf("%d", &no_of_edges);
    for (int i = 1; i <=no_of_edges ; i++)
    {
        scanf("%d %d" ,&edge_1, &edge_2);
        graph[edge_1][edge_2] =  1;
          graph[edge_2][edge_1] =  1; //uncomment this line for undirected graph

    }
    
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 )
        {   count++;
            dfs(i, graph, vis);
            printf("inside \n");
            /* code */
        }
        /* code */
    }
        printf("no of disjoint sets are %d\n", count);

    
    

}