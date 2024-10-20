#include <stdlib.h>
#include <stdio.h>
struct Node{
    int i;
    int j;
    int data;
    struct Node *next;
} *head;
void insert(struct Node* p, int i , int j ,int el){
    struct Node *last , *temp; 
    
    printf("Enter elements: ");
    for (int i = 0; i < el; i++){
        if(i == 0)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d%d%d", &head->i,&head->j,&head->data);
            last = head;
        }
        else{
            temp = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d%d%d", &temp->i, &temp->j, &temp->data);
            temp->next = NULL;
            last->next = temp;
            last = temp; 
        }

    }
}
void display(struct Node* p , int k , int l){
    for (int i = 0; i < k; i++){
        for (int j = 0; j < l; j++)
        {
            if( p && i == p->i && j == p->j){
                printf("%d ", p->data);
                p = p->next;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main(){
    insert(head, 4,5,4);
    display(head, 4, 5);
}