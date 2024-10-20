#include <bits/stdc++.h>
using namespace std;
void display(vector<int> arr){
    for (int i = 0; i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void frequencyCount(vector<int>& arr, int N, int P) {
        // do modify in the given array
        
         for(int i =0 ; i < arr.size(); i++ ){
             if(arr[i]<=N){
                 cout << "arr i " << arr[i] % (N + 1) << " ";
                 arr[(arr[i]%(N+1)) -1]+=N+1;
                 display(arr);
             }
         }
         

         for(int i = 0 ; i < arr.size(); i++){
             arr[i] = arr[i]/(N+1);
             
         }
    }
int main(){
    vector<int> a = {2, 3, 2, 3, 5};
    frequencyCount(a, 5,5);
}