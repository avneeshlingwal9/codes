#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool contains(int arr[] , int n , int s){
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==s){
            return true ;
        }
    }
    return false ;
}
int main(){
    int n  , m ;
    printf("NAME : - ANUSHKA NEGI \n"); 
    printf("Enter the number of elements you want for first array : - ");
    scanf("%d",&n);
     printf("Enter the number of elements you want for second array : - ");
    scanf("%d",&m);
    int *arr1 = (int*)malloc(n* sizeof(int));
    int *arr2 = (int*)malloc(m*sizeof(int)); 
    printf("Enter the elements in the array : - ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr1[i]);

    }
    printf("Enter the elements in the array : - ");

    for(int j = 0 ; j < m ; j++){
        scanf("%d",&arr2[j]);

    }
    if(n>m){
    int *insection = (int*)malloc(m*sizeof(int));
    
    

    int k = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(contains(arr2, m , arr1[i])){
            if( ! contains(insection , k , arr1[i])){
                insection[k] = arr1[i];
                k++;
            }
        }

        }
     
    
    for(int i =0 ; i < k; i++){
        printf("%d " , insection[i]);
        
    
    }}
    else{
        
    int* insection = (int*)malloc(n*sizeof(int));

    int k = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(contains(arr2, m , arr1[i])){
            if( ! contains(insection , k , arr1[i])){
                insection[k] = arr1[i];
                k++;
            }
        }

        }
     
    
    for(int i =0 ; i < k; i++){
        printf("%d " , insection[i]);
        
    
    }
    }
    
}

    
