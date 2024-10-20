#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Stack{
    int *A;
    int Top;
    int size;
};
int isEmpty(struct Stack st){
    return st.Top == -1; 
}
int isFull(struct Stack st){
    return st.Top == st.size - 1;
}
void push(struct Stack *st, int a){
 if(st->Top == st->size-1){
        printf("Stack overflow ");
     return;
 }
 st->Top++;
 st->A[st->Top] = a; 
}
int pop(struct Stack *st){
    if(st->Top == -1){
        return -1;
    }
    return st->A[st->Top--];
}
char atTop(struct Stack st){
    if(st.Top == -1){
        return '0';
    }
    return st.A[st.Top];
}
int isOperand(char x){
    if(x =='+' || x =='-' || x =='*' || x =='/' || x =='(' || x == ')' || x == '^'){
        return 0;
    }
    return 1;
}
int pre(char c){
    if(c =='+' || c =='-'){
        return 1;
    }
    if(c =='*' || c == '/'){
        return 2;
    }
    return 0; 
}
int preinside(char c){
    if(c =='+' || c =='-'){
        return 2;
    }
    else if(c == '*' || c == '/'){
        return 4;
    }
    else if(c == '^'){
        return 5;
    }
    else if(c =='('){
    return 0;
    }
    else if(c ==')'){
        return 0;
    }
    return 0;
}
int preoutside(char c){
    if(c == '+' || c =='-'){
        return 1;
    }
    else if(c =='*' || c =='/'){
        return 3;
    }
    else if(c == '^'){
        return 6;
    }
    else if(c =='('){
        return 7;
    }
    else if(c == ')'){
        return 0;
    }
    return 0;
}

/* char* infixToPostfix(char *infix){
    struct Stack st;
    st.Top = -1;
    st.size = strlen(infix);
    st.A = (int *)malloc(sizeof(char) * st.size);
    char *postfix = (char *)malloc(sizeof(char) * st.size + 1);
    int i = 0, j = 0; 
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            
            if(pre(infix[i]) > pre(atTop(st))){
                push(&st, infix[i++]);
            }
            else{
                postfix[j++] = pop(&st);
            }
        }
        
    }
    while(!isEmpty(st)){
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}
char* infixToPostfixRTL(char *infix){
    struct Stack st;
    st.Top = -1;
    st.size = strlen(infix);
    st.A = (char *)malloc(sizeof(char) * st.size);
    char *postfix = (char *)malloc(sizeof(char) * st.size + 1);
    int i = 0, j = 0; 
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(preoutside(infix[i]) > preinside(atTop(st))){
                push(&st, infix[i++]);
            }
            else if(preoutside(infix[i]) == preinside(atTop(st))){
                pop(&st);
                i++;
            }
            else {
                
                postfix[j++] = pop(&st);
            }
        }
        
    }
    while(!isEmpty(st)){
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
} */
int eval(char* a){
    struct Stack st;
    st.size = strlen(a);
    st.Top = -1;
    st.A = (int *)malloc(sizeof(char) * st.size + 1);
    int i, r, x1, x2;
    for (int i = 0; a[i] != '\0'; i++){
        if(isOperand(a[i])){
            push(&st, a[i]-'0');
        }
        else{
            x2 = pop(&st);
            x1 = pop(&st);
            switch (a[i]){
                case '+' :
                    r = x1 + x2;
                    push(&st, r);
                    break;
                case '-' :
                    r = x1 - x2;
                    push(&st, r);
                    break;
                case '*' :
                    r = x1*x2;
                    push(&st, r);
                    break;
                case '/' :
                    r = x1 / x2;
                    push(&st, r);
                    break;
            }

        }

    }
    return pop(&st);
}

int main(){
    char *c = "512+4*+3-";
    int d = eval(c);
    printf("%d", d);
}