#include <stdio.h>
int N;

void display_2D(int a[][N], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%5d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int i, j, n = 4, m = 3;
    display_2D(a, 4, N=3);

    printf("Enter Number of Rows and Column : ");
    scanf("%d %d", &n, &m);
    printf("Enter the numbers :\n");
    int mat[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    display_2D(mat, n, N=m);

    return 0;
}

