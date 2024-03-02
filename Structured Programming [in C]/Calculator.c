#include<stdio.h>

main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char ch = *argv[2];
    if(ch=='+') printf("%sum : d\n",a+b);
    else if(ch=='-') printf("%d\n",a-b);
    else if(ch=='*') printf("Multiple : %d\n",a*b);
    else if(ch=='/') printf("%d\n",a/b);
}


