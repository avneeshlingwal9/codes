#include <bits/stdc++.h>
using namespace std; 
int numpalind(int num){
    int n = 0 ; 
    int l = 0 ;
    int rem = num;
    do{
          l = rem%10;
          n = n*10 + l ; 
          rem = rem/10 ;
          
      }while(rem);
      if(num == n){
          return 1;
      }
      return 0 ; 
  }
    bool PalinArray(vector<int> &arr) {
        // code here
        for(int i = 0 ; i < arr.size(); i++){
            if(!numpalind(arr[i])){
                return 0 ; 
            }
            
        }
        return 1;
        
    }
int main(){
    int l = 101;
    cout << numpalind(l);
}