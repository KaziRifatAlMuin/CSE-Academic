#include<stdio.h>

int main()
{
    char a[]="abcd\nef\ng",b[]="abcd\befg\vabc\td", c[]="abcd\fefg\\\'\"\?";
    int n = printf("%s\nSize = %d\n", a, sizeof(a));
    printf("%d\n",n);
//    int m = scanf("%s %s",b, c);
//    printf("%s %s %d\n",b,c,m);
    printf("%s\nSize = %d\n", b, sizeof(b));
    printf("%s\nSize = %d\n", c, sizeof(c));
    //char d[]="a\"; //It is an error
    char s[]="abcd\befg";
    //scanf("%s",s);
    printf("%s\nSize = %d\tLength = %d\n", s, sizeof(s), strlen(s));
}

