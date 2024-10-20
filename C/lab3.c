#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool notcontains(int arr[] , int n , int s){
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==s){
            return false ;
        }
    }
    return true ;
}
int main(){
    int n  , m ; 
    printf("Name : - ANUSHKA NEGI\n");
    printf("Enter the number of elements you want for first array : - ");
    scanf("%d",&n);
     printf("Enter the number of elements you want for second array : - ");
    scanf("%d",&m);
    int arr1[n], arr2[m] ,sum  = 0 ; 
    printf("Enter the elements in the array : - ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr1[i]);

    }
    printf("Enter the elements in the array : - ");

    for(int j = 0 ; j < m ; j++){
        scanf("%d",&arr2[j]);
    }
    int unio[m+n];
    int ind = 0 ; 
    for(int i = 0 ; i < n ; i++){
            if(notcontains(unio,ind,arr1[i])){
            unio[ind] = arr1[i];
            ind++;}

    }
    for(int j = 0 ; j < m ; j++){
        if(notcontains(unio,ind,arr2[j])){
            unio[ind]= arr2[j];
            ind++;
        }
    }
    for(int i =0 ; i < ind; i++){
        printf("%d " , unio[i]);
        
    

    }

    
}