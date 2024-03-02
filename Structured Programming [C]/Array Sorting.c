#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int ara[n];
    for(i=0; i<n; i++){
        scanf("%d",&ara[i]);
    }
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(ara[j]<ara[i])
                swap(&ara[j],&ara[i]);
        }
    }
    for(i=0; i<n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");
    return 0;
}
