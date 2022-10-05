#include<stdio.h>

//#define ROW 3
//#define COL 3

int main()
{	int ROW;
	int COL;
	int COL2;
	scanf("%d%d%d", &ROW, &COL, &COL2);
	int arr_1[ROW][COL];
	int arr_2[COL][COL2];
	int res[ROW][COL2];
	int i;
	int j;
	int k;
	for (i = 0; i < ROW; i++ ) {
		for(j = 0; j < COL; j++){
			scanf("%d", &arr_1[i][j]);
		}
	}
	
	for (i = 0; i < COL; i++ ) {
		for(j = 0; j < COL2; j++){
			scanf("%d", &arr_2[i][j]);
		}
	}

	for (i = 0; i < ROW; i++ ) {
		for (j = 0; j < COL2; j++) {
			res[i][j] = 0;
			for (k = 0; k < COL; k++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}

	printf("1st matrix\n");

	for (i = 0; i < ROW; i++ ) {
		for(j = 0; j < COL; j++) {
			printf("%d ", arr_1[i][j]);
		}

		printf("\n");
	}

	printf("2nd matrix\n");

	for (i = 0; i < COL; i++ ) {
		for(j = 0; j < COL2; j++) {
			printf("%d ", arr_2[i][j]);
		}

		printf("\n");
	}
	
	printf("3rd matrix\n");

	for (i = 0; i < ROW; i++ ) {
		for(j = 0; j < COL2; j++) {
			printf("%d ", res[i][j]);
		}

		printf("\n");
	}

}

