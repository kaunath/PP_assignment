#include<stdio.h>
#include<string.h>

int main()
{
	printf("Enter the number of Employees: ");
	int n;
	scanf("%d",&n);
	int i,j,t,flag;
	char s[n][100];
	char temp[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
    for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		t= strcmp(s[i],s[j]);
    		if(t>0)
    		{
    			    strcpy(temp,s[i][]); 
         			strcpy(s[i],s[j]);
         			strcpy(s[j],temp);
			}
		}
	}
	printf("Arranged in lexicographical order:\n");
	
	for(i=0;i<n;i++)
	{
		printf("%s\t", s[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			t= strcmp(s[i],s[j]);
			if(t==0)
			{
				flag=0;
				break;
			}
			flag = 1;
		}
		if(flag==1)
		{
			printf("%s\t",s[i]);
		}
	}
	return 0;
}
