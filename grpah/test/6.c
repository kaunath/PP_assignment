/*
DFS implemetation in C My Implementation
 1 based indexing-- here we should take vis array and ajacency matrix's size one more
 than actual size, i.e for 7 node graph, matrix is 8*8 and vis array is size
 8

 0 based indexing--- here size of ajacency matrix and vis array is same as no of nodes 
 in the graph
*/
#include<stdio.h>
#define n 8

void dfs(int node, int vis[n], int A[][n])
{
   printf("%d ", node);
   vis[node] = 1;
    for (int  j = 1; j <= n; j++)
    {
        if (A[node][j] == 1 && vis[j] == 0)
        {
            dfs(j,vis, A);

        }
        
        
    }
    
}

int main()
{
     int A[n][n]; // 1 based indexing
     int vis[n] = {0,0,0,0,0,0,0,0};
     int edge_1, edge_2, no_of_edges;
     scanf("%d", &no_of_edges);

     for (int i = 1; i <= no_of_edges; i++)
     {
        scanf("%d %d", &edge_1,&edge_2);
        A[edge_1][edge_2] = 1;
        A[edge_2][edge_1] = 1;   
     }
     
   
    dfs(7, vis, A);
    
}