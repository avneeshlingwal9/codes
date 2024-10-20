#include <iostream>
using namespace std ; 
class Person{
    public :
    int age ;
    string name ;
    Person(){
        cout << "Enter the name : - " << endl ; 
        cin >> name ;
        cout << "Enter the age : -" << endl ;
        cin >> age;
    }
    Person(string aname , int aage){
        name = aname ;
        age = aage ;
    }
    Person(Person &p){
        name = p.name ;
        age = p.age;

    }
}
;
int main(){
    Person p ;
    Person p2("a", 56);
    Person p3(p2);
}