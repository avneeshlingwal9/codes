#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;

void insertionSort(vector<int> &arr)
{
    // code here
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {

        int prev = i - 1;
        int currel = arr[i];
        while (prev >= 0 && arr[prev] > currel)
        {

            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = currel;
    }
}

int main(){

}