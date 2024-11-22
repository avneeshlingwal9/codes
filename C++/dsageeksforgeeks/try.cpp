#include <bits/stdc++.h>
using namespace std;
void Sort(vector<int> &arr , int n , int i=0 ){
if(n == 0){
    return;
}
if(i == n-1){
Sort(arr,n-1,0);
return;
}
if(arr[i] > arr[i+1]){
swap(arr[i],arr[i+1]);

}
Sort(arr,n,i+1);

}
int main(){
    vector<int> v = {5, 6, 3, 2, 1};
    Sort(v, 5, 0);
    for(auto it: v){
        cout << it << endl;
    }
}
