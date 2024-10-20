#include <stdio.h>
#include <iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
int main(){
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(Rectangle));
    p->breadth = 5;
    p->length = 10;

    printf("%d \n", 5);
    printf("%d \n", p->breadth);
}