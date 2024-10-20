#include <stdio.h>
static int num = 0;
void toh(int n, char a , char b , char c){
    if(n>0){
        toh(n - 1, a, c, b);
        printf("Move Disk %d to Tower %c to Tower %c \n", n, a, c);
        num++;
        toh(n - 1, b, a, c);
    }
}
int main(){
    toh(64, 'A', 'B', 'C');
    printf("%d", num);
}