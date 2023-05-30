#include<stdio.h>
#include<string.h>

struct stud{
    char name[30];
    int roll;
    char dept[40];
    int batch;
    double cgpa;
};

struct stud kuet[1000];

void input(int n)
{
    int i = 0;
    for(i = 0; i < n; i++){
        printf("Enter Name : ");
        scanf("%s", &kuet[i].name);
        printf("Enter Roll : ");
        scanf("%d", &kuet[i].roll);
        printf("Enter dept : ");
        scanf("%s", &kuet[i].dept);
        printf("Enter batch : ");
        scanf("%d", &kuet[i].batch);
        printf("Enter cgpa : ");
        scanf("%lf",&kuet[i].cgpa);
    }
}

void display(struct stud *s)
{
    printf("Name : %s\n", s->name);
    printf("Roll : %d\n", s->roll);
    printf("Department : %s\n", s->dept);
    printf("Batch : %d\n", s->batch);
    printf("CGPA : %lf\n\n", s->cgpa);
}

void short_display(struct stud *s)
{
    printf("Name : %s\n", s->name);
    printf("Roll : %d\n", s->roll);
    printf("CGPA : %lf\n\n", s->cgpa);
}

int main()
{
    int n, i;
    printf("Enter number of students : ");
    scanf("%d", &n);
    input(n);
    char name[30], dept[40];
    int batch, roll;
    printf("Enter department name : ");
    scanf("%s", dept);
    printf("Enter Batch : ");
    scanf("%d", &batch);
    for(i=0; i<n; i++){
        if(strcmp(dept,kuet[i].dept) == 0 && kuet[i].batch == batch){
            short_display(&kuet[i]);
        }
    }
    printf("Enter a Roll : ");
    scanf("%d", &roll);
    for(i=0; i<n; i++){
        if(roll == kuet[i].roll){
            display(&kuet[i]);
        }
    }
}
