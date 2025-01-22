//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long  int s = n*(n+1)/2 , sum = 0 ; 
        for(int i = 0 ; i < n ; i++){
            sum+=arr[i];
            
        }
        int doubl = 0 ; 
        int diff = s-sum;
        for(int i = 0 ; i < n ; i++){
            arr[arr[i]%n-1]+=n ;
            if(arr[i]/n > 1){
                doubl = i+1;
                
            }
        }
        int msing = doubl+diff;
        vector<int> v{doubl,msing};
        return v;
    }
};
int main(){

}