#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,t,dsum=0;
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	 for(i=0;i<n;i++)
	 {
	 	dsum = dsum +a[i][i];
	 }
	 t = ((dsum)/(n*n - n));
	 
	 printf("%d",t+1);
	 
	 
	
	return 0;
}
