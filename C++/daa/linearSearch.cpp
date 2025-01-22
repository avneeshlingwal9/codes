#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void vectorToFile(const vector<int> &toConvert, string filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "File not opened" << endl;
        return;
    }
    for (auto i : toConvert)
    {
        file << i << " ";
    }
}
// Linear search function
int linearSearch(vector<int> &arr, int key)
{
    int count = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            break;
        }
        count++;
    }
    return count;
}
// Fills the vector with random numbers.
void fill(vector<int> &arr, int size)
{
    arr.push_back(34);
    for (int i = 1; i < size; i++)
    {
        int curr = rand() % (size + 1);
        arr.push_back(curr);
    }
}
// Initializes a matrix of vectors with different sizes, with a step of 10.
void initialize(vector<vector<int>> &mat)
{
    int size = 10;
    vector<int> numOfEl;
    for (int i = 0; i < mat.size(); i++)
    {
        numOfEl.push_back(size);
        fill(mat[i], size);
        size += 10;
    }
    vectorToFile(numOfEl, "numberOfElements.csv");
}
// Prints out a vector.
void print(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
// Function for best case .
void bestCase(vector<vector<int>> &mat, int key)
{

    vector<int> best;
    for (int i = 0; i < mat.size(); i++)
    {
        int currOpr = linearSearch(mat[i], key);
        best.push_back(currOpr);
    }
    cout << "The number of comparisons in the best case are: " << endl;
    print(best);
    vectorToFile(best, "bestcase.csv");
}
// Function for worst case
void worstCase(vector<vector<int>> &mat, int key)
{

    vector<int> worst;
    for (int i = 0; i < mat.size(); i++)
    {
        int currOpr = linearSearch(mat[i], key);
        worst.push_back(currOpr);
    }
    cout << "The number of comparisons in the worst case are: " << endl;
    print(worst);
    vectorToFile(worst, "worstCase.csv");
}
// Function for average Case
void averageCase(vector<vector<int>> &mat, int key)
{

    vector<int> average;
    for (int i = 0; i < mat.size(); i++)
    {
        int currOpr = linearSearch(mat[i], key);
        average.push_back(currOpr);
    }
    cout << "The number of comparisons in the average case are: " << endl;
    print(average);
    vectorToFile(average, "averageCase.csv");
}

int main()
{

    srand(time(0));
    vector<vector<int>> arr(10);
    initialize(arr);
    bestCase(arr, 34);
    worstCase(arr, 1002);
    averageCase(arr, 86);
    /*     vector<vector<int>> mat{
            {1, 2, 3},
            {4, 5, 6},
            {4, 5, 8}};
        vector<int> ans(mat.size());

        for (int i = 0; i < mat.size(); i++)
        {
            int currOpr = linearSearch(mat[i], 4);

            ans[i] = currOpr;
        }
        cout << "The number of comparisons in the best case are: " << endl;
        cout << ans.size();
        vectorToFile(ans, "bestcase.txt"); */
}