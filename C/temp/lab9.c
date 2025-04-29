#include<stdio.h>
#include<stdlib.h>
#define size 5
int enque(int q[],int *f,int *r){
    int item;
    if(*r==size-1){
        printf("queue is full");
        exit(1);      }
    scanf("%d",&item);
    q[++(*r)]=item;
    return item;
    }
    int deque(int q[],int *f,int *r){
    if(*f==*r){
    printf("Queue is empty");
    exit(1);      }
    return q[(*f)++];
    }
    void display(int q[],int *f,int *r){
    int i;
    printf("\nContent of queue is :\n");
    for(i=(*f);i<=(*r);i++){
    printf("%d ",q[i]);
    }
    printf("\n");    }
    int main(){
    printf("Name :- ANUSHKA NEGI\n");
    int q[size];
    int f=-1;
    int r=-1;
    int deleted_item;
    
    printf("Enter the items to be added : ");
	for(int i=0;i<size;i++){
        enque(q,&f,&r);
    }
	f=0;
	display(q,&f,&r);
	printf("Deleted items are: ");
    deleted_item=deque(q,&f,&r);
    printf("%d ",deleted_item);
    deleted_item=deque(q,&f,&r);
    printf("%d ",deleted_item);
    deleted_item=deque(q,&f,&r);
    printf("%d ",deleted_item);
    display(q,&f,&r);
    }
