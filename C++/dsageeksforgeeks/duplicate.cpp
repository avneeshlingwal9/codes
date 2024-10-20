class Solution {
  public:
    vector<int> duplicates(vector<long long> arr) {
        // code here
        
        
        vector<int> ar2(arr.size(),-1);
        for(int i= 0 ; i < ar2.size();i++){
            ar2[arr[i]]++;
        }
        vector <int>ar1 = ar2 ; 
        ar2.clear();
       
        int j = 0 ; 
        ar2.push_back(-1);  
        for(int i = 0 ; i < ar1.size(); i++){
            if(ar1.at(i)>0){
                ar2[j++] = i ; 
                
            }
        }
        
        
    return ar2;
    }
};