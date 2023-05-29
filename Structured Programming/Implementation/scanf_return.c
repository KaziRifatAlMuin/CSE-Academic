#include<stdio.h>

int main()
{
    int a, b, c, d;
    printf("%d\n",scanf("%d %d %d",&a,&b,&c));
    char c1, c2, c3;
//    printf("%d\n",scanf("%c%c %d %d %c %d",&c1,&c3,&a,&b,&c2,&c));
//    printf("\n%d %d %d %d %d %d\n", c1, c3, a, b, c2, c);
    printf("Enter 2 int : ");
    scanf("%d%d ",&a, &b); //it will take whitespace until next input
    printf("%d %d\n",a,b);
    //getchar();
    printf("Enter 2 char : ");
    scanf("%c %c",&c1, &c2);
    printf("%c %c\n",c1,c2);
}
