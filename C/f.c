

#include<stdio.h>

#define MAX 6
void push(int st[],int val,int *top){
    if(*top>=MAX-1){
        printf("stack is overflow");
    }
    else{
        ++(*top);
        st[*top]=val;
    }
}
int pop(int st[],int *top){
    int temp;
    if(*top==-1){
        printf("Stack is empty");
        temp=-1;
        return -1;
    }
    else{
        temp=st[*top];
        (*top)--;
        return temp;
    }
}
int main(){
    printf("Question 1 : - Implementation of Stack.\n");
    int top=-1;
    int n;
    int st[MAX];
    printf("NAME : - ANUSHKA NEGI\n");
    printf("Enter values:- ");
    for(int i=0;i<MAX;i++){
        scanf("%d",&n);
        push(st,n,&top);
    }
    printf("Popped values:- \n");
    for(int i=0;i<MAX;i++){
        printf("%d ",pop(st,&top));
    }
}
