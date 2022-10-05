#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d", &n);
	char s[n][20];
	int i,j,k,len;
	
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++)
	{
		len = strlen(s[i]);
		k=1;
		for(j=0;j<len/2;j++)
		{
			if(s[i][j]!=s[i][len-1-j])
			{
				k=0;
				break;
			}
		}
		if(k==1)
		{
			printf("%s\n", s[i]);
		}
	}
	return 0;
}
