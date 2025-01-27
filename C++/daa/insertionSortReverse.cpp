#include <iostream>
#include <vector>

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
        comp++;
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) // Inserting elements if everything after the current index j is smaller.
        {
            arr[j + 1] = arr[j];
            comp++;
            j--;
        }
        arr[j + 1] = key;
    }
    return comp;
}
int main()
{
    vector<int> arr{1, 2, 12, 2, 1};
    cout << insertionSort(arr) << endl;
    print(arr);
}