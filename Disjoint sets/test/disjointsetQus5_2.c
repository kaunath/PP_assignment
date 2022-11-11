#include<stdio.h>

int parent[1000];
int rank[1000];

void makeset(int n)
{
	parent[n] = n;
	rank[n] = 0;
}

int find(int x)
{
	if(x != parent[x]){
		return parent[x] = find(parent[x]);
	}
	else{
		return parent[x];
	}
}

void Union(int u, int v)
{
	u = find(u);
	v = find(v);

	if(rank[u] < rank[v]){
		parent[u] = v;
	}
	else if(rank[u] > rank[v]){
		parent[v] = u;
	}
	else{
		parent[v] = u;
		rank[u]++ ;
	}
}

int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
	int n, i,j;
	int u ,v;
	scanf("%d",&n);
	int count = 0,z=0;
	int arr[n];
	int matrix[n][n];

	for(i = 1; i<= n; i++){  
		for(j = 1; j <= n; j++){
			scanf("%d", &matrix[i][j]);
			}
		}

	for(i = 1; i <= n; i++){
		makeset(i);
	}

	for(i = 1; i <= n; i++){
		for(j = 1; j<= n; j++){
			if(matrix[i][j] == 1){
				Union(i,j);
				}
			}
		}
		
	for(i = 1; i <= n; i++){
		if(find(i) == i){
			count++ ;
			arr[z] = i;
			z++ ;
		}
	}
	printf("%d\n", count);
	for(i=0;i<z;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
	
	return 0;
}
	
