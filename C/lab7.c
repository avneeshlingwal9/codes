#include <stdlib.h>
#include <stdio.h>
int main(){
    printf("NAME : -ANUSHKA NEGI\n");
    int n ; 
    printf("Enter the number of  elements you want to insert in array : -\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements in the array : - ");
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&arr[i]);


    }
    printf("Elements of the array are : - ");
    for(int i = 0 ; i < n ; i ++){
        printf("%d ",arr[i]);


    }
    printf("\n");

    //Resizing the array 
    int r ; 
    printf("Enter the number of elements you want to add more in the array : - ");
    scanf("%d", &r);
    int *res = (int*)malloc((n+r)*sizeof(int));
    printf("Enter new elements in the array : -");
    for(int i = 0 ; i < n+r ; i++){
        if(i > n-1){
        scanf("%d", &res[i]);}
        else{
            res[i] = arr[i];
        }
    }
    printf("Elements of the array are : - ");
    for(int i = 0 ; i < n+r ; i ++){
        printf("%d ",res[i]);


    }
    free(arr);
    free(res);

    
}