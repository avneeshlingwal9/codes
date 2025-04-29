

#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX 20
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
        printf("Stack overflow");
      
    }
    else{
        ++(top);
        stck[top]=val;
    }
}
int pop(){
    int temp;
    if(isEmpty()){
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

int evaluation(char pos[]) {
    int len = strlen(pos);
    for (int i = 0; i < len; i++) {
        if (isdigit(pos[i])) {
            push(pos[i] - '0'); 
        } else {
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (pos[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Division by zero\n");
                        return 0; 
                    }
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    printf("Name :- ANUSHKA NEGI\n");
    char pos[MAX];
    printf("Enter a pos expression: ");
    scanf("%s", pos);

    int result = evaluation(pos);
    
    printf("Result: %d\n", result);
    

    return 0;
}