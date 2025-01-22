#include <iostream>
using namespace std ;
class Student{
    public :
    string *name ;
    int * age ;
    Student(const Student& s){
        name = new string ;
        age = new int ;
        *(name) = *(s.name);
        *(age) = *(s.age);
    }
    Student(string  s ,int i){
        name = new string ;
        age = new int ; 
        *name = s;
        *age = i;
    }
    void display(){
        cout << "Name of the student is " << *name << " and age is " << *age << endl ;
            }
};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    int a ;
    string s ;
    cout << "Enter the name of the student:- " << endl ;
    getline(cin,s);
    cout << "Enter the age of the student:- " << endl ;
    cin >> a ;
    Student s1(s,a);
    s1.display();
    
    Student s2(s1);
    cout << "Deep copy of the object " << endl ;
    s2.display();

}