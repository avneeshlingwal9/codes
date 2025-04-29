

#include<stdio.h>
#include <stdbool.h>


#define MAX 6
int stck[MAX];
int top = -1 ;
bool isEmpty(){
    if(top == -1){
        return true ;
    }
    return false ;
}
bool isFull(){
    if(top == MAX-1){
        return true ;
    }
    return false ;
}
void push(int val){
    if(isFull()){
        printf("stack is overflow");
    }
    else{
        ++(top);
        stck[top]=val;
    }
}
int pop(){
    int temp;
    if(isEmpty()){
        printf("Stack is empty");
        temp=-1;
        return -1;
    }
    else{
        temp=stck[top];
        top--;
        return temp;
    }
}

int peek(){
    return stck[top];
}
int main(){


    int n;
    printf("NAME : - ANUSHKA NEGI\n");
    printf("Enter values:- ");
    for(int i=0;i<MAX;i++){
        scanf("%d",&n);
        push(n);
    }
    printf("Top value is : %d ", peek());
    printf("\nPopped values:- \n");
    for(int i=0;i<MAX;i++){
        printf("%d ",pop());
    }
}
