/*
storing a graph given the edges
*/

#include<stdio.h>

int main() 
{   int n, edge;
    scanf("%d",&n);
    scanf("%d",&edge);

    //using matrix
    int graph[n][n];
    for (int  i = 1; i <= edge; i++)
    {   
        int edge_1, edge_2;
        scanf("%d %d", &edge_1, &edge_2);
        graph[edge_1][edge_2] = 1;
        graph[edge_2][edge_1] = 1;

    }

    
    for (int  i = 1; i <= n; i++)
    {   
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] ==1)
            {
                printf("%d -> %d\n", i,j);
            }
            
        }
        
        
    }
    

}