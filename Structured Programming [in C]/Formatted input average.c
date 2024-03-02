#include<stdio.h>

struct data{
    int roll;
    char name[30];
    double mark;
};

struct data s[100];

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    int i=0, j=0;
    double sum=0;
    while(!feof(fp)){
        fscanf(fp,"%d, %[^,], %lf",&s[i].roll, s[i].name, &s[i].mark);
        fgetc(fp);
        sum += s[i].mark;
        //printf("%d %s %lf %lf\n", i, s[i].name, s[i].mark, sum);
        i++;
    }
    int num = --i;
    for(j=0; j<i; j++){
        printf("Roll : %d\nName : %s\nMarks : %lf\n\n",s[j].roll,s[j].name,s[j].mark);
    }

    printf("\nAverage is %lf\n",sum/num);
    fclose(fp);
    exit(0);
}
