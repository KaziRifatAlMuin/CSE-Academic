#include<stdio.h>

void print_space(int n)
{
    while(n--)
        printf(" ");
}

void print_star(int n)
{
    while(n--)
        printf("*");
    printf("\n");
}

int main()
{
    int n, i;
    scanf("%d",&n);
    int space = n - 1;
    for(i=1; i<=n; i++){
        print_space(space--);
        print_star(2*i-1);
    }
    for(i=n-1; i>0; i--){
        print_space(++space+1);
        print_star(2*i-1);
    }
}
