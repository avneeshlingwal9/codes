#include <bits/stdc++.h>

using namespace std;
/*

Description: fill( arr , size)

    Fills the array of size with random values.

Input Parameters:

    vector<int> arr: A vector of integers in which key to be found.

    int size: Size of the array.




*/
void fill(vector<int> &arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        int curr = rand() % (size + 1);
        arr.push_back(curr);
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int insertionSort(vector<int> &arr)
{
    int comp = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) // Moving in j till j > key. Or j will stop at the index, where on the right, all the elements will be greater than key and on the left, all are smaller.
        {
            arr[j + 1] = arr[j]; // Shifting the elements to the right.
            j--;
        }
        arr[j + 1] = key; // j + 1 because j will stop at the index, in which the keys before j are all small that current key.
    }
    return comp;
}
int main()
{
    vector<int> arr;
    fill(arr, 1000000000);
    sort(arr.begin(), arr.end());
    print(arr);
}