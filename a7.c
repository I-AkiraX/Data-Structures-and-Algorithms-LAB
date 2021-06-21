#include<stdio.h>
#include<stdlib.h>
struct student{
    int roll;
    double cgpa;
    struct student *next;
};
typedef struct student* node;
node createNode(){
    node temp;
    temp=(node)malloc(sizeof(struct student));
    temp->next=NULL;
    return temp;
}
node push(node top,int roll,double cgpa){
    node temp,p;
    temp=createNode();
    temp->roll=roll;
    temp->cgpa=cgpa;
    if(top==NULL){
        top=temp;
    }
    else{
        p=top;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    return top;
}
node pop(node top){
    if(top==NULL){
        printf("No student information is present!");
    }
    else{
        node temp=top;
        top=top->next;
        printf("Roll: %d\nCGPA: %lf\nThis student info was popped!",temp->roll,temp->cgpa);
        free(temp);
    }
    return top;
}
void show(node top){
    node p;
    p=top;
    int i=0;
    if(p==NULL){
        printf("No student information is present!");
    }
    else{
        while(p!=NULL){
            printf("\n\nStudent %d:\nRoll: %d\nCGPA: %lf",++i,p->roll,p->cgpa);
            p=p->next;
        }
    }
}
node sort(node top){
    node current=top,index=NULL;
    if(top==NULL){
        return top;
        printf("No student information is present!");
    }
    else{
        while(current!=NULL){
            index=current->next;
            while(index!=NULL){
                if(current->roll>index->roll){
                    int roll=current->roll;
                    current->roll=index->roll;
                    index->roll=roll;
                    double cgpa=current->cgpa;
                    current->cgpa=index->cgpa;
                    index->cgpa=cgpa;
                }
                index=index->next;
            }
            current=current->next;
        }
        printf("Student stack has been sorted!");
    }
    return top;
}
int main(){
    node top=NULL;
    int x=0;
    while(x!=5){
        printf("\n\nPress--\n\n1: Push\n2: Pop\n3: Sort\n4: Display\n5: Exit\n\nYour choice:  ");
        scanf("%d",&x);
        if(x==1){
            int roll;
            double cgpa;
            printf("\n\nRoll Number:\t");
            scanf("%d",&roll);
            printf("CGPA:\t");
            scanf("%lf",&cgpa);
            top=push(top,roll,cgpa);
            printf("Student information pushed!");
        }
        else if(x==2){
            top=pop(top);
        }
        else if(x==3){
            sort(top);
        }
        else if(x==4){
            show(top);
        }
        else if(x==5){

        }
        else{
            printf("Wrong entry! Enter again!");
        }
    }
}