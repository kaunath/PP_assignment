/*
 *4. Read a square matrix of size n. Do the following tasks:
a. Print all unique values along each row.
b. Print all unique values along each column.
c. Print all unique values in the matrix.
Input:
4
5 1 2 1
4 10 3 5
2 1 4 4
1 2 0 7
Output:
Along rows:
1 2 5
3 4 5 10
1 2 4
0 1 2 7
Along columns:
1 2 4 5
1 2 10
0 2 3 4
14 5 7
Matrix:
0 1 2 3 4 5 7 10
 *
 * */

#include<stdio.h>

int main()
{
	int row, col;
	
	scanf("%d %d", &row, &col);
	
	int arr[row][col];

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			scanf("%d", &arr[row][col]);
		}
	}

}
