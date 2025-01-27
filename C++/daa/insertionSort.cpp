#include <bits/stdc++.h>

using namespace std;

void vector_to_file(const vector<int> &toConvert, string filename)
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

void generate_permutations(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    unordered_set<int> done;

    for (int i = index; i < arr.size(); i++)
    {

        swap(arr[i], arr[index]);
        generate_permutations(arr, ans, index + 1);
        swap(arr[i], arr[index]);
    }
}

int insertionSort(vector<int> &arr)
{
    int comp = 0;
    int traversal = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        traversal++;
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) // Moving in j till j > key. Or j will stop at the index, where on the right, all the elements will be greater than key and on the left, all are smaller.
        {
            comp++;
            arr[j + 1] = arr[j]; // Shifting the elements to the right.
            j--;
        }
        arr[j + 1] = key; // j + 1 because j will stop at the index, in which the keys before j are all small that current key.
    }
    return comp + traversal;
}
void generate_graph(vector<int> &size, vector<vector<vector<int>>> collection)
{
    vector<int> bestCase;
    vector<int> WorstCase;
    vector<int> averageCase;
    for (auto collect : collection)
    {
        int min_comparison = INT_MAX;
        int max_comparison = INT_MIN;
        int average_comparison = 0;
        int number_of_arrays = collect.size();

        for (auto arr : collect)
        {
            int curr_comparison = insertionSort(arr);
            min_comparison = min(min_comparison, curr_comparison);
            max_comparison = max(max_comparison, curr_comparison);
            average_comparison += curr_comparison;
        }
        average_comparison /= number_of_arrays;

        bestCase.push_back(min_comparison);
        WorstCase.push_back(max_comparison);
        averageCase.push_back(average_comparison);
    }

    cout << "The best case comparisons are: " << endl;
    print(bestCase);
    cout << "The worst case comparisons are: " << endl;
    print(WorstCase);
    cout << "The average case comparisons are: " << endl;
    print(averageCase);
    vector_to_file(bestCase, "bestCaseInsertionSort.txt");
    vector_to_file(WorstCase, "worstCaseInsertionSort.txt");
    vector_to_file(averageCase, "averageCaseInsertionSort.txt");
    vector_to_file(size, "size.txt");
}
void generate_comparisons(vector<int> &arr)
{
    vector<vector<int>> permutations;
    generate_permutations(arr, permutations, 0);

    int maximum_comparisons = INT_MIN;
    int minimum_comparisons = INT_MAX;
    int average_comparisons = 0;
    int number_of_permutations = 0;
    for (auto it : permutations)
    {
        int current_comparisons = insertionSort(it);
        number_of_permutations++;
        average_comparisons += current_comparisons;
        maximum_comparisons = max(maximum_comparisons, current_comparisons);
        minimum_comparisons = min(minimum_comparisons, current_comparisons);
    }
    average_comparisons /= number_of_permutations;
    cout << "Best case comparisons are: " << minimum_comparisons << endl;
    cout << "Worst case comparisons are: " << maximum_comparisons << endl;
    cout << "Average case comparisons are: " << average_comparisons << endl;
}
int main()
{
    srand(time(0));

    vector<vector<vector<int>>> collection;
    vector<int> size;
    for (int i = 10; i <= 1000; i += 10)
    {
        size.push_back(i);
        vector<vector<int>> variety;
        for (int j = 0; j < 10; j++)
        {
            vector<int> arr(i);
            fill(arr, i);
            variety.push_back(arr);
        }
        collection.push_back(variety);
    }

    generate_graph(size, collection);
    vector<int> arr(4);
    fill(arr, 4);
    generate_comparisons(arr);
}