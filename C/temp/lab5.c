#include <stdio.h>
int main(){
    int n ; 
    printf("NAME : - ANUSHKA NEGI\n");
    printf("Enter the number of elements you want to insert : - \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array : - ");
    for(int i = 0 ; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array is : - \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", arr[i] );}
    printf("\n");
    for(int j = 0 ; j < n/2 ; j++ ){
        int temp = arr[j];
        arr[j] = arr[n-j-1];
        arr[n-j-1] = temp ;
    }
    printf("Reversed array is : - \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }


}