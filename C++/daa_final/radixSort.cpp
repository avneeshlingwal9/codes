#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;
int getMax(int arr[], int n)
{

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
    }

    return maxi;
}

void countSort(int arr[], int size, int place)
{

    int count[10] = {0};
    int output[size];

    for (int i = 0; i < size; i++)
    {

        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {

        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {

        int index = --count[(arr[i] / place) % 10];
        output[index] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    // code here
    int maxEl = getMax(arr, n);

    for (int place = 1; maxEl / place > 0; place *= 10)
    {

        countSort(arr, n, place);
    }
}
int main()
{
    vector<int> arr = readInput();
    print(arr);
}