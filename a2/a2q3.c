#include<stdio.h>
struct employee{
    int id,deptNo;
    char name[50];
    double salary;
}emp[5];
int main(){
    struct employee *e=emp;
    for(int i=0;i<5;i++){
        printf("\n\nEmployee %d:\nName:\t",i+1);
        scanf("%[^\n]s",(e+i)->name);
        printf("ID:\t");
        scanf("%d",&(e+i)->id);
        printf("Department Number:\t");
        scanf("%d",&(e+i)->deptNo);
        printf("Salary:\t");
        scanf("%lf",&(e+i)->salary);
        scanf("%*c");
    }
    for(int i=0;i<5;i++){
        printf("\n\nName:\t%s\nID:\t%d\nDepartment Number:\t%d\nSalary:\t%lf",(e+i)->name,(e+i)->id,(e+i)->deptNo,(e+i)->salary);
    }
    return 0;
}