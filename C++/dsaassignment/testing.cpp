//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long int findN(int mid , int n , int m){
	    long long int ans = m;
	    for(int i= 0 ; i < n ; i++){
	        ans*=mid;
	        if(ans > m){
	            break;
	        }
	        
	        
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    long low = 1;
	    long high = m;
	    while(low<=high){
	        int mid = low + (high-low)/2;
	        long long int val = findN(mid,n,m);
	        if(val <= m){
	            low= mid+1;
	        }
	        else{
	            high = mid-1;
	        }
	    }
	    return high;
	    // Code here.
	}  
};

//{ Driver Code Starts.
int main(){
    Solution ob;
    cout << ob.findN(2,3,25);
    return 0;
}
// } Driver Code Ends