/*
 *In a matrix, calculate the sum of all neighboring elements of each diagonal element (up, down,
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
index: 2
 * */

#include<stdio.h>

int main() 
{
	int val;
	int i, j, sum =0, index, count;
	scanf("%d", &val);
	
	int arr[val][val];
	
	for(i = 0; i < val; i++) {
		for(j = 0; j < val; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for(i = 0; i < val; i++) {
		for(j = 0; j < val; j++) {
			if(i == j) {
				if(i == 0 && j == 0) {
					sum += arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
					printf("%d: %d\n", arr[i][i] ,sum);
					index = i;
					count = sum;
					sum = 0;
				}

				if(i == val-1 && j == val-1) {
					 sum += arr[val-2][val-1] + arr[val-1][val-2] + arr[val-2][val-2];
					 printf("%d: %d\n", arr[i][i] ,sum);
					 
					 if (sum > count) {
						count = sum;
					 	index = i;
					 }
					 sum = 0;
				} else if (i !=0) {
					sum += arr[i-1][j] + arr[i+1][j] + arr[i][j-1] + arr[i][j+1] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i+1][j-1] + arr[i+1][j+1];
					printf("%d: %d\n", arr[i][i] ,sum);

					if(sum > count) {
						count = sum;
						index = i;
					}
					sum = 0;

				}
			}
		}
	}
	printf("index: %d", index);
}
