/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) 
and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or 
diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
*/

#include<stdio.h>
#define n 5
#define m 4

void dfs(int graph[][m], int vis[][m], int row, int col)
{
    printf("calling dfs\n");
    vis[row][col] = 1;
    for (int  delrow = -1; delrow <=1 ; delrow++)
    {
    // printf("inside for outer\n");
        for (int delcol = -1; delcol <= 1; delcol++)
        {
    // printf("inside for inner\n");

            int nrow = row + delrow;
            int ncol = col + delcol;
            // printf("nrow and ncol are %d %d\n", nrow, ncol);
           if (nrow >=0 && nrow<n && ncol >=0 && ncol < m 
           && graph[nrow][ncol] == 1 && vis[nrow][ncol] == 0  ) 
           {
            // printf("inside recursion\n");
            dfs(graph, vis, nrow, ncol);
           }
           
            
        }
        
        /* code */
    }
    
    
}

int main() 
{
    int graph[n][m];
    int count = 0;
    // int vis[n][m] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int vis[n][m] = {0};


     for (int i = 0; i <n ; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    
    }


    for (int i = 0; i <n ; i++)
    { 
        //  printf("inside for outer\n");
        for (int j = 0; j < m; j++)
        {
            //  printf("inside for inner\n");
            if (graph[i][j] == 1 && vis[i][j] == 0)
            {
                // printf("inside\n");
                count++;
                dfs(graph, vis,i,j);
            }
            
        }
    
    }
    printf("no of islands are %d\n", count);
}