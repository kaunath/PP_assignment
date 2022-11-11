/*
DFS implementation to detect a cycle in a connected componenets
*/

#include <stdio.h>
#define n 6
#include <stdbool.h>

int dfs(int node, int parent, int vis[n + 1], int A[][n + 1])
{
    printf("%d ", node);
    vis[node] = 1;
    for (int j = 1; j <= n; j++)
    {
        printf(" first inside\n");

        if (A[node][j] == 1 && vis[j] == 0)
        {
            if (dfs(j, node, vis, A) == 1)
            {
                printf("inside\n");

                return 1;
            }
        }
        else if (A[node][j] == 1 && j != parent)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int A[n + 1][n + 1]; // 1 based indexing
    int vis[n + 1] = {0};
    int flag = 0;
    int edge_1, edge_2, no_of_edges;
    scanf("%d", &no_of_edges);

    for (int i = 1; i <= no_of_edges; i++)
    {
        scanf("%d %d", &edge_1, &edge_2);
        A[edge_1][edge_2] = 1;
        A[edge_2][edge_1] = 1;
    }

    for (int i = 1; i <=n; i++)
    {
        if(vis[i] == 0) {
            if (dfs(3, -1, vis, A) == 1){
                printf("cycle\n");
                return 0;
            }
        } 
    }
    printf("not cycle\n");
    return 0;
}