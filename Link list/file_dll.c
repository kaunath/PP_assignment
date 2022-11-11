#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fptr;
int i = 0;
	size_t len = 0;
char *contents = NULL;
	fptr = fopen("link.txt", "r");
	if (fptr == NULL)
		printf("file not opened");
    else
        printf("file opened\n");

    while (getline(&contents, &len, fptr) != EOF) {
        while ((char)contents[i] != '\n')
        {
        printf( "%c",contents[i]);
        i++;            /* code */
        }
        

    }
    free(contents);
    fclose(fptr);
    return 0;
}
