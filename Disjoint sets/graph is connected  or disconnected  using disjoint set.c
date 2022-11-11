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
    //for(int i=0;i<10000;i++){
        //  arr[i]=-1;
   // }
    int n;
    scanf("%d",&n);
    //int f[n][n];
    for(int i=0;i<n;i++){
        make_set(i+1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            scanf("%d",&num);
           // f[i][j]=num;
            if(num==1){
                    //make_set(i+1);
              union_set(i+1,j+1); 
                    //make_set(j+1);
               
                
            }
        }
    }
    //for(int i=0;i<n;i++){
        //for(int j=0;j<n;j++){
           // if(f[i][j]==1){
                   // union_set(i+1,j+1);
           // }
       // }
   // }
    int c=0;
    for(int i=1;i<=10;i++){
        if(arr[i]==i){
            //printf("%d",i);
            c++;
        }
    }
    // if graph have 1 connected component then graph is connected otherwise graph is disconnected.
    if(c==1){
    printf("Graph is connected ");
    }
    else{
        printf("graph is not connected");
    }
    return 0;
}
