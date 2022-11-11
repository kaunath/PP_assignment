#include<stdio.h>
#define MAX 100

int main()
{
	FILE *fh;
	int arr[MAX];
	int i=0,j;
	fh = fopen("DLL.txt", "r");
	
	if(fh != NULL)
	{
		char c;
		
		while((c = fgetc(fh))!= EOF)
		{
			if(c != ' ')
			{
			arr[i]= c ;
			i++ ;
		}
		}
		
		fclose(fh);
	}
	else
	{
		printf("ERROR IN OPENING FILE\n");
	}
	
	for(j=0;j<i;j++)
	{
		printf("%c ",arr[j]);
	}
	
	return 0;
}
