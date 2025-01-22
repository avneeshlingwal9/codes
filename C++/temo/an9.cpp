#include <iostream>
using namespace std;
class Person{
    public :
    int age ;
    Person(int aage = 0 ){
        this->age = aage ;
    }
    Person operator+(const Person& n){
        Person sm ;
        sm.age = age + n.age;
        return sm ;
    }
    void display(){
        cout << "The age of person is " << age << endl ;
    }
};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    int a , b ;
    cout << "Enter the age of first person :- " << endl ;
    cin >> a ;
    cout << "Enter the age of the second person :- "<< endl ;
    cin >> b; 
    Person p1(a) , p2(b);
    Person p3 = p1+p2 ;
    p3.display();


}