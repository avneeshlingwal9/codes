#include <bits/stdc++.h>
using namespace std;
struct weatherData
{
    string cityName;
    string time;
    int temperature;
};

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

void print(vector<weatherData> &arr)
{
    for (auto i : arr)
    {
        cout << i.cityName << " " << i.time << " " << i.temperature << endl;
    }
}

int main()
{
    ifstream file("weather.txt");

    string line;
    vector<weatherData> weatherInfo;
    while (getline(file, line))
    {
        stringstream ss(line);
        weatherData data;
        ss >> data.cityName;
        ss >> data.time;
        ss >> data.temperature;
        weatherInfo.push_back(data);
    }
    print(weatherInfo);
    insertionSortTime(weatherInfo);
    print(weatherInfo);
}