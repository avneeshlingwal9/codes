#include <stdlib.h>
#include <stdio.h>
struct diagonalM{
    int A[10];
    int n;
};
void set(struct diagonalM *m , int i , int j , int ele){
    if(i==j){
        m->A[i] = ele;
    }

}
int get(struct diagonalM m , int i , int j){
    if(i==j){
        return m.A[i];
    }
    return 0; 
}
void display(struct diagonalM m){
    for (int i = 0; i < m.n; i++){
        for (int j = 0; j < m.n; j++){
            if(i==j){
                printf("%d ", m.A[i]);
            }
            else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main(){
    struct diagonalM m;
    m.n = 5;

    set(&m, 0, 0, 4);
    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 10);
    display(m);
}