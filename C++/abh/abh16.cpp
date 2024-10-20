#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a vector of pairs to store student id and name pairs
    vector<pair<int, string>> students;

    // Add student id and name pairs to the vector
    students.push_back(make_pair(101, "Alice"));
    students.push_back(make_pair(103, "Bob"));
    students.push_back(make_pair(102, "Charlie"));
    students.push_back(make_pair(105, "David"));
    students.push_back(make_pair(104, "Eve"));

    // Sort the vector based on student id in ascending order
    sort(students.begin(), students.end());

    // Print student names in front of their corresponding IDs
    cout << "Sorted Student IDs and Names:\n";
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].second << " (ID: " << students[i].first << ")\n";
    }

    return 0;
}
