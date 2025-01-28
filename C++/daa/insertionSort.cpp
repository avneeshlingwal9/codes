#include <bits/stdc++.h>

using namespace std;

/*
Function: vector_to_file(const vector<int>& toConvert , string fileName)

Description:

    Converts the vector into a file.

Input Parameters:

    vector<int> arr: A vector of integers, which is to be converted.

    string fileName: Name of the file, in which content of vector to be stored.



*/
void vector_to_file(const vector<int> &to_convert, string filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "File not opened" << endl;
        return;
    }
    for (auto i : to_convert)
    {
        file << i << " ";
    }
}
/*
Function: fill( arr , size)

Description:

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
/*
Function: print(vector<int> &arr)

Description:

    Prints the given array arr.

Input Parameters:

    vector<int>& arr: The array to be printed.

Output:
    Prints the elements of the array.
*/
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*
Function : generate_permutations( vector<int> arr , vector<vector<int>> &ans , int index = 0 )

Description:

    Fills the 2-D array ans with all permutations of the arr.

Input Parameters:

    vector<int> arr: A vector of integers for which permutations to be generated.

    vector<vector<int>>& ans: A 2-D matrix in which all permutations to be stored.

    int index: index from where permutations to be generated. Default value is zero.



*/
void generate_permutations(vector<int> &arr, vector<vector<int>> &ans, int index = 0)
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
/*
Function: insertionSort(vector<int>& arr)


Description:

    Sorts an array arr and returns the sum of total number of comparisons done.

Input Parameters:

    vector<int> arr: A vector of integers which is to be sorted.

Return Value:
    int comp : Returns total number of comparisons done.



*/
int insertionSort(vector<int> &arr)
{
    int comp = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comp++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comp;
}
/*
Function: generate_graph( vector<vector<vector<int>>> collection)


Description:

    Given a 3-D vector Collection. For each 2-D array, Matrix in Collection, counts the number of average , maximum and minimum number of comparisons done for that Matrix when insertion sort is applied to each Row of the Matrix.

    Stores the result for each 2-D Matrix in arrays, according to different cases and then converts them into files, which will be then used for graph plotting.

Input Parameters:
    vector<vector<vector<int>>> collection:

     A 3-D vector, containing 2-D Matrices, with each 2-D Matrices containing randomly generated Rows of a 'fixed size'. The 'fixed size' varies for each 2-D Matrix varies from 10 to 1000 in the step size of 10.


Output Parameters:

    Prints the number of comparisons done in each case.


*/
void generate_graph(vector<vector<vector<int>>> collection)
{
    vector<int> bestCase;

    vector<int> WorstCase;

    vector<int> averageCase;

    vector<int> size;

    for (auto matrix : matrixion)
    {
        int min_comparison = INT_MAX;

        int max_comparison = INT_MIN;

        int average_comparison = 0;

        int number_of_arrays = matrix.size();

        int size_of_current = 0;

        for (auto row : matrix)
        {
            int curr_comparison = insertionSort(row);

            min_comparison = min(min_comparison, curr_comparison);

            max_comparison = max(max_comparison, curr_comparison);

            average_comparison += curr_comparison;

            size_of_current = row.size();
        }

        average_comparison /= number_of_arrays;

        bestCase.push_back(min_comparison);

        WorstCase.push_back(max_comparison);

        averageCase.push_back(average_comparison);

        size.push_back(size_of_current);
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

/*
Function: generate_comparisons( vector<int>& arr)


Description:

  Given an array, it generates all the permutations of the array, then returns the maximum, minimum and average comparisons done when insertion sort is applied to all permutations.

Input Parameters:
    vector<int> arr:
    An array containing randomly generated integers.


Output Parameters:

    Prints the number of comparisons done in each case.


*/
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

    for (int i = 10; i <= 1000; i += 10)
    {
        vector<vector<int>> matrix;

        for (int j = 0; j < 10; j++)
        {
            vector<int> row(i);
            fill(row, i);
            matrix.push_back(row);
        }
        collection.push_back(matrix);
    }

    generate_graph(collection);
    vector<int> arr(4);
    fill(arr, 4);
    generate_comparisons(arr);
}