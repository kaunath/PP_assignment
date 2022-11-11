#include <stdio.h>

int parent[100000];
int rank[100000];

void makeset(int n){
		parent[n] = n;
		rank[n] = 0;
}

int find(int x){
	if(x != parent[x]){
		return parent[x] = find(parent[x]);
	}
	else{
		return parent[x];
	}
}
void Union(int u, int v){
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
int main(){
	int num,k,i;
	scanf("%d", &num);
	scanf("%d", &k);
	for(i=1;i<=num;i++){
		makeset(i);
	}
	
	int u,v;
	while(k--)
	{
		scanf("%d%d", &u, &v);
		Union(u,v);
	}

	int count = 0;

	for(i=1;i<=num;i++)
	{
		if(find(i) == i)
		{
			count++ ;
		}
	}

	printf("%d",count);
	
	return 0;
}

