#include <iostream>
using namespace std ; 
class person {
    public : 
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
class student : public person {
    public : 
    string classs ; 
    student(){
        get_data();
    }
    void get_class(){
        cout << "Enter the class : - "<< endl ;
        cin >> classs ; 
    }
    void get_data(){
        get_class();
    }
    void display_data(){
        cout <<"The name of the student is " << name << " and the age is " << age <<" and the class is " << classs <<"." << endl ; 
    }};
class teacher : public person {
    public : 
    string specialization ; 
    teacher(){
        get_specialization();
    }
    void get_specialization(){
        cout << "Enter the specialization : - "<< endl ;
        cin >> specialization; 
    }
    void get_data(){
        get_specialization();
    }
    void display_data(){
        cout <<"The name of the teacher is " << name << " and the age is " << age <<" and the specialization is " << specialization <<"." << endl ; 
    }};
int main(){
    person p1 ; 
    p1.display_data();
    student s1 ;
    s1.display_data();
    teacher t1 ;
    t1.display_data();
}