#include <iostream>
using namespace std;
class Student{
    public :
    string name ;
    int age ;
    Student(){
        cout << "Enter name of the student :- " << endl ;
        getline(cin,this->name);
        cout << "Enter age of the student :- " << endl ;
        cin >> this->age;
    }
    Student(string aname , int  aage){
        this->name = aname ;
        this->age = aage ;
    }
    Student(const Student& s){
        this->name = s.name ;
        this->age = s.age ;
    }
    void display(){
        cout << "The name of the student is " << name << " and age is "<< age << endl ;
    }
};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    Student s ;
    Student s1("Virat", 18);
    Student s2(s);
    cout << "Built using default constructor " << endl ; 
    s.display();
    cout << "Built using parameterized constructor " << endl ;
    s1.display();
    cout << "Built using copy constructor " << endl ; 
    s2.display();



}