#include <iostream>
using namespace std ; 
class Person{
    private :
    string name ;
    int age ; 
    public : 
    Person(string aname , int aage){
        name = aname ; 
        age = aage ;
    }
    friend  void comp(Person p1 , Person p2){
        if(p1.age > p2.age){
            cout << p1.name << " is greater than " << p2.name << endl ; 
        }
        else {
            cout << p2.name << " is greater than " << p1.name << endl ; 
        }
    }
};
int main(){
    Person p1("a",5);
    Person p2("b",6);
    comp(p1,p2);
}
