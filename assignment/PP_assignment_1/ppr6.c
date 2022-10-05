/*Enter a square matrix and print the the i
th row and j
th column whose sums are equal.
Input:
4
1 1 1 5
1 1 1 0
2 2 2 1
3 3 3 2
Output:
Row: 1
Column: 4
*/
#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int temp1[n],temp2[n];
	
	int i,j,k,sum1,sum2;
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		sum1=0, sum2=0;
		for(j=0;j<n;j++)
		{
			sum1 = sum1 + arr[i][j];
			
		}
		temp1[i]= sum1;
		for(k=0;k<n;k++)
		{
			sum2 = sum2 + arr[k][i];		
		}
		temp2[i]= sum2;
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(temp1[i]==temp2[j])
			{
				printf("Column:%d and Row:%d ",j, i);
			}
		}
	}	
	return 0;	
}
