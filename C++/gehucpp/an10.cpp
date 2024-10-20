#include <iostream>
using namespace std ;
class Person{
    private :
    int age ;
    string name ;
    public : 
    Person(){
        cout << "Enter the name of the person:- " << endl ;
        getline(cin,name);
        cout<< "Enter the age of the person:- " << endl ;
        cin >> age ;
    }
    friend void display(Person p );
};
void display(Person p){
    cout << "Private member access " << endl ;
    cout << "The name of person is " << p.name << " and age is " << p.age << endl ;
}
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    Person p1 ;
    display(p1);

}