#include<stdio.h>

int main()
{
    char *p = "Hello";
    char q[20], r[20];
    strcpy(r,p);
    strcpy(q,p);
    p = "Bye";
    strcat(r,p);
    strcpy(q,p);
    printf("%s %s %s",p,q,r);
}


