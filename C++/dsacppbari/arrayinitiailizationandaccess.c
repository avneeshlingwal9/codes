#include <stdio.h>
int main(){
    int A[5] = {2, 4, 6, 8, 10};
    int B[] = {2, 4, 8, 6};
    int C[5] = {2, 4};
    int D[5] = {0};
    for (int i = 0; i < 5; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", i[C]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", *(D + i));
    }

        return 0; 
}