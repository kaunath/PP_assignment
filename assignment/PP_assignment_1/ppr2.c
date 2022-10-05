/*
3. Take a matrix of size m*n. Find out its transpose using a function transpose(arr, &m, &n).
Input:
2 3
1 1 1
2 2 2
Output:
1 2
1 2
1 2*/
#include<stdio.h>
int m, n;
void transpose(int arr[][n], int *a,int *b)
{
	int c,d;
	c= *a; d=*b;
	int p[d][c];
	int i,j;
	for(i=0;i<d;i++)
	{
		for(j=0;j<c;j++)
		{
			p[i][j]= arr[j][i];
				printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
int main()
{

	scanf("%d %d", &m, &n);
	int i,j;
	int arr[m][n];
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	 transpose(arr, &m, &n);
	 
	 return 0;
}




