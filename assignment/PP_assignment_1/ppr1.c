/* In a matrix, calculate the sum of all neighboring elements of each diagonal element (up, down,
left, right, and 4 diagonal elements -- a total of 8 elements). Print these values corresponding to 
each diagonal element. Also print the index of that diagonal element whose corresponding sum is 
highest.
Input:
5
3 2 0 4 5
1 10 4 -2 6
0 3 7 0 8
6 5 1 4 4
9 7 0 -1 3

Output:
3: 13
10: 20
7: 25
4: 22
3: 7
index: 3  */

#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j,k=0,dsum=0,max,p;
	int arr[n][n];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	max = arr[0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
			
				if(i==n-1 && j==n-1)
				{
					dsum = arr[i][j-1] + arr[i-1][j-1] + arr[i-1][j];
					printf("%d : %d \n", arr[i][j], dsum);
					if(dsum>max)
					{
						max= dsum;
						p = n*i + j;
					}
				}
				else if(i==0 && j==0)
				{
					dsum = arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j];
					printf("%d : %d \n", arr[i][j], dsum);
						if(dsum>max)
					{
						max= dsum;
						p = n*i +j;
					}
				}
				else
				{
					dsum = arr[i][j-1] + arr[i][j+1] + arr[i-1][j] + arr[i+1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i+1][j-1] + arr[i+1][j+1];
					printf("%d : %d \n", arr[i][j], dsum);
						if(dsum>max)
					{
						max= dsum;
						p = n*i +j;
					}
				}
			}
      	}
    }
    
	printf("index of diagonal with highest sum is %d", p);
	
	return 0;
	
}
