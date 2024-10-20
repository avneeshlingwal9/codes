#include <iostream>
#include <vector>
using namespace std;
bool countBoquet(int curr , int flower ,  vector<int> a){
    int count = 0 ;
    int n = a.size();
    int i = 0 ;
    while( i < n ){
        if(a[i] > curr){
            i++;
            continue;
        }
        else{
            int j = i+1;
            int currcount = 1 ;
            while((j < n) && (currcount < flower) &&(a[j]<= curr)){
                j++;
                currcount++;
            }
            if(currcount == flower){
                count++;
                i = j ;
            }
            else{
                i++;
            }
            
        }
    }
    return count ;
}
int weightCheck(vector<int> w, int curr) {
        int sum = 0;
        int count = 0;
        int i = 0;
        int n = w.size();
        while (i < n) {
            if(w[i] > curr){
                return INT_MAX;
            }
            if ((sum == curr) ||(sum + w[i] > curr)) {
                sum = 0;
                count++;
            } 
            else {
                sum += w[i];
                i++;
            }
        }

        count++;

        return count ;
    }
int linearS(vector<int> a , int key){
    for(int i = 0 ; i < a.size(); i++){
        if(a[i] == key){
            return i;
        }

    }
    return -1;
}
int cows(int curr , vector<int> stal , int ma  ){
    int coun = 0;
    int n = stal.size();
    
    
    
    for(int i = 0 ; i < n ; i++){
        int t = stal[i]+curr;
        if(t > ma){
            continue;
        }
        else{
            if(linearS(stal,t) != -1){
                coun++;
                i = linearS(stal,t)-1;
            }
        }
        
    }
    return coun+1;
}
int numberOfPainters(vector<int> arr , int curr){
    int count=1, curBoard = 0 ;
    for(int i= 0 ; i < arr.size(); i++){
        if(curBoard+arr[i] <= curr){
            curBoard+=arr[i];
        }
        else{
            curBoard= arr[i];
            count++;
        }}
        return count;
    
}
int searc(vector<int> a){
        int low = 0 ;
        int high= a.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid]==0){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return a.size()-low;    
    }

int main(){
    vector<int> a = {0 ,0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1};
    cout << searc(a);
}