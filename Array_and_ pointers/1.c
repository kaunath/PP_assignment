#include<stdio.h>
#include<math.h>

int main()
{

/*
 *1. For an n*n matrix diagonal elements are given. All non-diagonal elements are equal, say x. Find
out the minimum value of x such that the sum of diagonal elements is less than the sum of nondiagonal elements.
Input:
4
5 10 4 7
Output:
5 3 3 3
3 10 3 3
3 3 4 3
3 3 3 7
(Hint: Sum of diagonal element: 26, sum of other elements: 36)

*/
	int val;
	int i, j;
	int res, remainder;
	int sum = 0;

	scanf("%d", &val);
	
	int arr[val][val];

	for (i = 0; i < val; i++) {
		for (j = 0; j < val; j++ ) {
			if (i == j) {
				scanf("%d", &arr[i][i]);
				sum += arr[i][i];
			}
		}
	}
	
	res = sum / ((val* val) - val);
	res++;

	for (i = 0; i < val; i++) {
		for (j = 0; j < val ; j++) {
			if (i != j) {
				arr[i][j] = res;
			}
		}
	}

	
	for (i = 0; i < val; i++) {
		for (j = 0; j < val; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


}
