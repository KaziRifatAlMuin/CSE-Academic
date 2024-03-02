#include<stdio.h>

struct data{
    int roll;
    char name[30];
    double mark;
    char str[100];
};

struct data s[100];

int main()
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    int i=0, j=0;
    double sum=0;
    while(scanf("%[^\n]",s[i].str)!=EOF){
        //gets(s.str[i]);
        getchar();
        sscanf(s[i].str,"%d, %[^,], %lf",&s[i].roll, s[i].name, &s[i].mark);
        sum += s[i].mark;
        //printf("%d %s %lf %lf\n", i, s[i].name, s[i].mark, sum);
        i++;
    }
    for(j=0; j<i; j++){
        fprintf(fp,"Roll : %d\nName : %s\nMarks : %lf\n\n",s[j].roll,s[j].name,s[j].mark);
    }

    fprintf(fp,"\nAverage is %lf\n",sum/i);
    fclose(fp);
    return 0;
}
