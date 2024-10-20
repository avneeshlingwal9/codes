#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:

    // Note that the size of the array is n-1
    
    int missingNumber(int n, vector<int>& arr) {
        long int sum = n*(n+1)/2 ; 
        long int  s = 0 ;
        

        for(int i = 0 ; i < n ; i++){
            s+=arr[i];
            
            
        }
        return sum-s;
    }
};
int main(){
    Solution s ;
    int n = 198;
    vector<int> arr;
    int l; 
    cout << "Enter elements : " << endl; 
    for (int i = 0; i < n-1; i++){
        cin >> l;
        arr.push_back(l);
        }

        s.missingNumber(n, arr);
}