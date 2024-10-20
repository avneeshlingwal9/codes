#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int size;
    int Top;
    int *A;
};
void push(struct Stack *s , int k){
    if(s->Top == s->size-1){
        printf("Stack overflow");
    }
    else{
        s->A[++s->Top] = k;
    }
}
int pop(struct Stack *s){
    int x = -1;
    if(s->Top == -1){
        printf("Stack underflow");
    }
    else{
        x = s->A[s->Top--];
    }
    return x; 
}
int peek(struct Stack s ,int pos){
    int x = -1;
    if(s.Top -pos+1 < 0){
        printf("INvalid position");
    }
    else{
        x = s.A[s.Top - pos + 1];
    }
    return x; 
}
int topGun(struct Stack st){
    if(st.Top == -1 ){
        printf("Stack underflow");
        return -1;
    }
    else{
        return st.A[st.Top];
    }

}
int isFull(struct Stack st){
    if(st.Top == st.size-1){
        return 1;
    }
    return 0; 
}
int isEmpty(struct Stack st){
    if(st.Top == -1){
        return 1; 
    }
    return 0; 
}

int main(){
    struct Stack st ;
    st.size = 5;
    st.A = (int *)malloc(sizeof(int)*st.size);
    st.Top = -1;
    push(&st, 35);
    push(&st, 35);
    push(&st, 35);
    push(&st, 35);
    push(&st, 35);
    printf("%d", peek(st, 4));
}