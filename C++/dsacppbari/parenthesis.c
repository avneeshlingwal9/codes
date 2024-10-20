#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct  Stack{
    int Top;
    int size;
    char *s;
};
int isEmpty(struct Stack st){
    return st.Top == -1; 
}
int isFull(struct Stack st){
    return st.Top == st.size;
}
void push(struct Stack *st , char a){
    if(isFull(*st)){
        printf("Stack overflow\n");
        return; 
    }
    st->Top++;

    st->s[st->Top] = a; 
}
char pop(struct Stack *st ){
    if(isEmpty(*st)){
        printf("Stack underflow");
        return '-1';
    }
    return st->s[st->Top--];
}
int parenthesischecker(char *exp){
    struct Stack st;
    
    st.size = strlen(exp);
    st.Top = -1;
    st.s = (char *)malloc(sizeof(st.size));
    for (int i = 0; exp[i] != '\0'; i++){
        if(exp[i] =='('){
            push(&st, exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty(st)){
                return 0; 
            }
            pop(&st);
        }}
        return isEmpty(st) ? 1 : 0 ;
    
}
int parenthesischeckermodified(char* exp){
    struct Stack st;
    st.Top = -1;
    st.size = strlen(exp);
    st.s = (char *)malloc(sizeof(st.size));
    for (int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(&st, exp[i]);
        }
        else if(exp[i] ==')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(st)){
                return 0;
            }
            char x = pop(&st);
            if( (x =='(' && exp[i] != ')') || (x =='['  && exp[i] != ']')  || (x =='{' && exp[i]!= '}')){
                return 0;
            }
        }}
        return isEmpty(st) ? 1 : 0; 
    
}
int main(){
    char ex[] = "{4+ (2 + [6] }";
    printf("%d ",parenthesischeckermodified(ex));
}