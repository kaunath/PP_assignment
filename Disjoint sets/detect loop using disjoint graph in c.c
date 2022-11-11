#include <stdio.h>

int arr[10000]; // parent array;
int deg[10000];

void make_set(int v){
    arr[v]=v;
    deg[v]=1;
}
int find(int v){
    if(v==arr[v]){
        return v;
    }
    return arr[v]=find(arr[v]);
}
void union_set(int u,int v){
    u=find(u);
    v=find(v);
    if(u!=v){
        if(deg[u]>deg[v]){
            arr[v]=u;
            deg[u]=deg[u]+deg[v];
        }
        else{
            arr[u]=v;
            deg[v]=deg[u]+deg[v];
        }
    }
}
int main()
{   
    printf("number of nodes");
    int n;
    scanf("%d",&n);
    int f[n][n];
    for(int i=0;i<n;i++){  // create set of vertices.
        make_set(i+1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            scanf("%d",&num);
            if(num==1 && f[j][i]!=1){
               f[i][j]=num;
                
            }
            else {
                f[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f[i][j]==1){
              if(find(i+1)==find(j+1)){
                    printf("cycle");
                  return 0;
              }    
              union_set(i+1,j+1); // create set of edges.
            }
        }
    }
    //for(int i=0;i<n;i++){
        //for(int j=0;j<n;j++){
            //if(f[i][j]==1){
               // if(find(i+1)==find(j+1)){
                   // printf("Cycle is presenrt in graph");
                    //return 0;
               // }
           // }
      // }
   //}
   printf("Cycle is not present in graph");
   return 0;
   
}
