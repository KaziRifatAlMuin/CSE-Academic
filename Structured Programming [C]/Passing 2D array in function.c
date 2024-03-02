#include<stdio.h>

void display1(int *q, int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%3d ",*(q+i*col+j));
        }
        printf("\n");
    }
}

void display2(int (*q)[4], int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%3d ",*(*(q+i)+j));
        }
        printf("\n");
    }
}

int main()
{
    int mat[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    printf("Type 1 :\n\n");
    display1(mat,3,4);
    printf("\nType 2 :\n\n");
    display2(mat,3,4);
    return 0;
}



