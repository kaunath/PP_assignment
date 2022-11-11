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
	int n;
	scanf("%d",&n);

	int matrix[n][n];
	int i,j;

	for(i = 1; i<= n; i++){  
		for(j = 1; j <= n; j++){
			scanf("%d", &matrix[i][j]);
			}
		}

	for(i = 1; i <= n; i++){
		makeset(i);
		}

	int u ,v;

	for(i = 1; i <= n; i++){
		for(j = 1; j<= n; j++){
			if(matrix[i][j] == 1){
				Union(i,j);
				}
			}
		}
	int count = 0;
	for(i = 1; i <= n; i++){
		if(find(i) == i){
			count++ ;
		}
	}
	if(count==1){
		printf("Connected\n");
	}
	else{
		printf("Disconnected\n");
	}

}
	
	return 0;
}
	
