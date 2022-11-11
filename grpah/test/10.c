/*
FLOOD FILL algorithm
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel
value newColor, "flood fill" the image.

input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
*/

#include<stdio.h>
#define n 3
#define m 3

void dfs(int image[][m], int vis[][m],int sr, int sc, int new_color, int ini_color )
{
    printf("calling dfs\n");
    image[sr][sc] = new_color;
    vis[sr][sc] = 1;
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1 };
    for (int i = 0; i < 4; i++)
    {
        printf("inside for\n");
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];

        if  (nrow >= 0 && nrow <n && ncol >=0 && ncol <n && 
            image [nrow][ncol] == ini_color  && vis [nrow][ncol] == 0)
        {
            printf("inside recursion");
            dfs(image, vis, nrow, ncol, new_color, ini_color);
        }
        


    }
    

}

int main()
{
    int image[n][m];
    int vis[n][m] = {0};
    int sr = 1, sc = 1,new_color = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &image[i][j]);
        }
        
        /* code */
    }
    dfs(image, vis, sr, sc, new_color, image[sr][sc]);
    
      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", image[i][j]);
        }
        
     
     printf("\n");   /* code */
    }

    // doing the same work again
    // int vis_1[n][m] = {0};
    // dfs(image, vis, 2, 0, 3, image[2][0]);
    //       for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf("%d ", image[i][j]);
    //     }
        
     
    //  printf("\n");   /* code */
    // }


}