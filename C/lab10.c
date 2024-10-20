#include<stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX 20
char stck[MAX];
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
char peek(){
    return stck[top];
}

void push(char val){
    if(isFull()){
        printf("Stack overflow");
    }
    else{
        ++(top);
        stck[top]=val;
    }
}
char pop(){
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

int operandCheck(char ch){
    return (ch >= 'a' && ch <= 'z' ) || (ch >='A' && ch <='Z');
}
int precedence(char c){
    if(c == '-' || c == '+'){
        return 1 ;
    }
    else if(c == '*' || c=='/'){
        return 2 ;
    }
    else if (c == '^'){
        return 3 ;

    }
    else {
        return -1 ;
    }
}
int highprecedence(char a , char b){
    return precedence(a) > precedence(b);
}
int covertInfixToPostfix(char* expression)   
{   
    int i, j;  
  
    for (i = 0, j = -1; expression[i]; ++i)   
    {   
       if (operandCheck(expression[i]))   
            expression[++j] = expression[i];   
  
        else if (expression[i] == '(')   
            push(expression[i]);   
  
        else if (expression[i] == ')')   
        {   
            while (!isEmpty() && peek() != '(')   
                expression[++j] = pop();   
            if (!isEmpty() && peek() != '(')   
                return -1;             
            else  
                pop();   
        }  
        else   
        {   
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))   
                expression[++j] = pop();   
            push(expression[i]);   
        }   
  
    }   
  
    while (!isEmpty())   
        expression[++j] = pop();   
  
    expression[++j] = '\0';   
    printf( "%s", expression);   
}   
  
int main()  
{  
    printf("Name : - ANUSHKA NEGI\n");

char expression[20];
printf("Enter expression:- ");
scanf("%s",expression); 

    covertInfixToPostfix(expression);   
    return 0;   
}  