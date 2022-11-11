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

			int u ,v,cycle;

			for(i = 1; i <n; i++){
					cycle =0;
					for(j = i+1; j<=n; j++){
							if(matrix[i][j] == 1){
										if(find(i)==find(j)){
											    cycle = 1;
													break;
										}else{
												Union(i,j);
										}
							}
					}
					if(cycle == 1){
					printf("Cycle is present\n");
					break;
					}
			}
				if(cycle != 1){
				printf("Cycle is not present\n");
			}
	}
	
	return 0;
}
	
