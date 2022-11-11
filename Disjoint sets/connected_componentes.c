#include<stdio.h>

int parent[1000];
int rank[1000];


void makeset(int n) {

    parent[n] = n;
    rank[n] = 0;
}

int findset(int elem) {

    if(elem != parent[elem]) {
        return parent[elem] = findset(parent[elem]);
    }

    else {
        return parent[elem];
    }
}

void Union(int u, int v) 
{
    u = findset(u);
    v = findset(v);

    if(rank[u] < rank[v]) {
        parent[u] =v;
    } else if (rank[u] > rank[v])
    {
        parent[v] = u;
    } else {
        parent[v] =u;
        rank[u++];
    }
    


}

int main() 
{
    int n;
    scanf("%d", &n);
    int graph[n][n], rep[n];
    int count = 0,z=0;

    for ( int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }

        
    }
    
    for(int i = 1; i<=n; i++) {
        makeset(i);
    }


    for ( int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == 1)
            {
                Union(i,j);
            }
            
        }

        
    }

    for ( int i = 1; i <= n; i++)
    {
        if (findset(i) == i)
        {
            count++;
            rep[z] = i;
            z++;
        }
    
    }
    printf("%d\n", count);
    for (int i = 0; i < z; i++)
    {
        printf("%d ", rep[z]);
    }
    
    
}