
/*
In a matrix, calculate the sum of all neighboring elements of each diagonal element (up, down,
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
index: 3
*/

#include<stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    int arr[size][size];
    int sum;
    sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);    
        }
    }
     
    sum += arr[0][1] + arr[1][1] + arr[1][0];
    printf("%d : %d\n", arr[0][0], sum);


    sum = 0;

    sum += arr[size-1][size-2] + arr[size-2][size-1] + arr[size-2][size-2];
    printf("%d : %d\n", arr[size-1][size-1], sum);


}