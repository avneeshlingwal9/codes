#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;
void quickSort(vector<int> &arr, int low, int high)
{
    // code here
    if (low >= high)
    {
        return;
    }
    int divide = partition(arr, low, high);
    quickSort(arr, low, divide - 1);
    quickSort(arr, divide + 1, high);
}


    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[high];
        
        int i = low - 1; 
          
        for(int j = low ; j < high ; j++){
            if(arr[j] < pivot){
                swap(arr[++i], arr[j]);
            }
            
        }
        swap(arr[++i], arr[high]);
        return i;
        
    }

    int main()
    {
        vector<int> arr = readInput();
        print(arr);
    }