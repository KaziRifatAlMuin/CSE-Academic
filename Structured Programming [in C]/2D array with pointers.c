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
    int *(ara)[4];
//    printf("Enter Number of Rows and Column : ");
//    scanf("%d %d", &n, &m);
    printf("Enter the numbers :\n");
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
            scanf("%d",(&ara[i]+j));
        }
    }
    printf("Display\n");

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
            printf("%d ",*(&ara[i]+j));
        }
        printf("\n");
    }

    //display_2D(mat, n, N=m);

    return 0;
}


