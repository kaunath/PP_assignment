/*
Number of enclaves
*/

#include<stdio.h>
#define n 4
int main()
{
    int graph[n+1][n+1];
    int vis[n+1][n+1] = {0};
    int edge_1, edge_2, no_of_edges,nrow, ncol;
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    
    for (int  i = 1; i <= no_of_edges; i++)
    {
        scanf("%d %d", &edge_1, &edge_2);
        graph[edge_1][edge_2] = 1;
        graph[edge_2][edge_1] = 1;

    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 0 || i == n-1 || j ==0 || j== n-1)
            {
                if (graph[i][j] == 1)
                {
                vis[i][j] = 1;
                nrow = 
                }
            }
            
        }
        
    }
    
    
}