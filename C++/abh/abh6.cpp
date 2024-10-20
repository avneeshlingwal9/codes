#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Marks {
private:
    static int rollNumberCounter;

protected:
    int rollNumber;
    string name;
    int marks;

public:
    Marks() : rollNumber(++rollNumberCounter), name(""), marks(0) {}

    void setName(const string& studentName) {
        name = studentName;
    }

    void setMarks(int studentMarks) {
        marks = studentMarks;
    }

    int getMarks() const {
        return marks;
    }
};

int Marks::rollNumberCounter = 0;

class Physics : public Marks {
public:
    using Marks::Marks;
};

class Chemistry : public Marks {
public:
    using Marks::Marks;
};

class Mathematics : public Marks {
public:
    using Marks::Marks;
};

int main() {
    int numStudents;

    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    vector<Physics> physicsStudents(numStudents);
    vector<Chemistry> chemistryStudents(numStudents);
    vector<Mathematics> mathStudents(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        string studentName;
        int physicsMarks, chemistryMarks, mathMarks;

        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> studentName;

        cout << "Enter marks in Physics for student " << i + 1 << ": ";
        cin >> physicsMarks;
        physicsStudents[i].setName(studentName);
        physicsStudents[i].setMarks(physicsMarks);

        cout << "Enter marks in Chemistry for student " << i + 1 << ": ";
        cin >> chemistryMarks;
        chemistryStudents[i].setName(studentName);
        chemistryStudents[i].setMarks(chemistryMarks);

        cout << "Enter marks in Mathematics for student " << i + 1 << ": ";
        cin >> mathMarks;
        mathStudents[i].setName(studentName);
        mathStudents[i].setMarks(mathMarks);
    }

    double totalPhysics = 0, totalChemistry = 0, totalMath = 0;

    for (int i = 0; i < numStudents; ++i) {
        totalPhysics += physicsStudents[i].getMarks();
        totalChemistry += chemistryStudents[i].getMarks();
        totalMath += mathStudents[i].getMarks();
    }

    double averagePhysics = totalPhysics / numStudents;
    double averageChemistry = totalChemistry / numStudents;
    double averageMath = totalMath / numStudents;

    cout << "\nClass Summary:\n";
    cout << "Average marks in Physics: " << averagePhysics << "\n";
    cout << "Average marks in Chemistry: " << averageChemistry << "\n";
    cout << "Average marks in Mathematics: " << averageMath << "\n";

    return 0;
}
