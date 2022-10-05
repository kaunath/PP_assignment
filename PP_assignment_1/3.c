/*
 *Take a matrix of size m*n. Find out its transpose using a function transpose(arr, &m, &n).
Input:
2 3
1 1 1
2 2 2
Output:
1 2
1 2
1 2
 * */
#include<stdio.h>

int row, col;
void transpose(int arr[][col], int *, int * );

int main ()
{
	int i, j;
	scanf("%d %d", &row, &col);
	int arr[row][col];
	
	for (i = 0; i < row; i++ ) {
		for(j = 0 ; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	transpose(arr, &row, &col);
}

void transpose(int arr[][col], int *row, int *col)
{
	int transpose[*col][*row];

	for(int i = 0; i < *col; i++) {
		for(int j = 0; j < *row; j++) {
			transpose[i][j] = arr[j][i];
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}
}
