#include <stdio.h>
#include <stdlib.h>
int main(){
    int n ; 
    printf("Enter the number of elements you want for array : - ");
    scanf("%d",&n);
    int arr[n], sum  = 0 ; 
    printf("Enter the elements in the array : - ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);

    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i]%2==0){
            sum+=arr[i];
        }
    }
    printf("Name : - ANUSHKA NEGI\n");
    printf("Sum of the even elements are : - %d", sum);
}