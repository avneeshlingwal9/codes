#include <bits/stdc++.h>
using namespace std;

// A structure to hold weather data.

struct weatherData
{
    string cityName;
    string time;
    int temperature;
};

/*
Function: insertionSort(vector<weather>& arr)


Description:

    Sorts an arrray arr containing weatherData according to city names.

Input Parameters:

    vector<int> arr: A vector of weatherData which is to be sorted.





*/

void insertionSort(vector<weatherData> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        weatherData key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].cityName > key.cityName)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*
Function: print(vector<weatherData> &arr)

Description:

    Prints the given values of array arr.

Input Parameters:

    vector<weatherData>& arr: The array to be printed.

Output:
    Prints the elements of the array.
*/

void print(vector<weatherData> &arr)
{
    for (auto i : arr)
    {
        cout << i.cityName << " " << i.time << " " << i.temperature << endl;
    }
}

int main()
{
    // Opening a file containing weather data.
    ifstream file("weather.txt");

    string line;
    // Array containing weather data.
    vector<weatherData> weatherInfo;

    while (getline(file, line))
    {
        // Converting data to stringstream and then using it to read corresponding inputs.
        stringstream ss(line);
        weatherData data;
        ss >> data.cityName;
        ss >> data.time;
        ss >> data.temperature;
        weatherInfo.push_back(data);
    }
    cout << "\n\nBefore sorting\n\n"
         << endl;
    print(weatherInfo);
    // Before sorting

    insertionSort(weatherInfo);

    cout << "\n"
         << "\n"
         << "After sorting " << "\n"
         << endl;
    // After sorting
    print(weatherInfo);
}