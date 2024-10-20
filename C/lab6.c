#include <stdio.h>
int main(){
    printf("NAME : - ANUSHKA NEGI/n");
    int n , max = 0 ; 
    printf("Enter the number of elements you want to insert : - \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array : - ");
    for(int i = 0 ; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("Maximum element of the array is  %d " , max);
    


}