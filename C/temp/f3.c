#include <stdio.h>
#include <stdlib.h>
#define MAX 6
struct node {
    int info;
    struct node* next;
};
typedef struct node node;

node *insert(int v,node *head) {
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = v;
    
    if(head==NULL){
       temp->next = NULL; 
    }
    else{
       temp->next=head;  
    }
    head = temp;
    return head;
}

void display(node *head) {
    node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}

int delete1(node **head) {
    if ((*head) == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return -1;
    }
    node* ptr = (*head);
    (*head) = (*head)->next;
    int temp=ptr->info;
    free(ptr);
    return temp;
}

int main() {
    printf("IMPLEMENTATION OF LINKED LIST \n");
	node* head = NULL; 
    int n;
    printf("NAME: ANUSHKA NEGI\n");
    printf("Enter values in linked list : ");
    for(int i=0;i<MAX;i++){
        scanf("%d",&n);
        head = insert(n,head);
    }
    printf("Initial list is: \n");
    display(head);
    printf("\nEnter no.of elements to delete : ");
    scanf("%d",&n);
    printf("Deleted elements are: ");
    for(int i=0;i<n;i++){
        int t= delete1(&head);
        printf("%d ",t);
    }
    printf("\nAfter deleting list is : ");
    display(head);
  return 0;
  }
