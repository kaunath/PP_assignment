/*
Question on disjoint set test
*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int graph[n+1][n+1];
    int vis[n+1];
    int alive[n+1];
    int k;
    scanf("%d", &k);
    int count = (n/2) +k;
    int j = 1;
    for (int i = 1; i <=n; i++)
    {
        alive[i] = 0;
    }

    

    for (int i = 1; i <= count; i = i + 1)
    {
        if(n % 2 == 0)
        {
        alive[j%n] = 1;
        for (int i = 1; i <n; i++)
        {
            /* code */
        }
        
        alive[(j+1)%n] = 0;
        graph[j][(j+1)] = 1;
        graph[j+1][j] = 1;
        }
        else {
        alive[j] = 1;
        alive[j+1] = 0;
        graph[j%n][(j+1)%n] = 1;
        graph[(j+1)%n][j%n] = 1;
        }
    }
}


