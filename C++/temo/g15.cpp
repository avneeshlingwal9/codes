#include <iostream>
using namespace std ; 
class person {
    private : 
    string name ; 
    int age ; 
    public : 
    person(){
        get_data();
    }
    void get_data(){
        cout << "Enter the name of the person : - " << endl ;
        cin >> name ; 
        cout << "Enter the age of the person : - " << endl ;
        cin >> age ; 
    }
    person ( const person& ){
        name = name ;
        age = age;
    }
    person(string aname , int aage){
        name = aname ; 
        age = aage ; 
    }
    ~person(){
        cout << "Object destroyed :) " << endl ;

    }
    void display_data(){
        cout << "The name of the person is " << name << " and the age is " << age << "." << endl ;    
    }
};
int main(){
    person p1 ; 
    person p2("Newton",40);
    person p3(p1);
    p1.display_data();

}