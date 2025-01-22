#include <iostream>
using namespace std ;
class Student{
    public :
    string name ;
    int rollno; 
    Student(); // Default constructor
    Student(string parname , int parrollno ){
        name  = parname ;
        rollno = parrollno;
    }
    Student(Student &k){
        name = k.name ;
        rollno = k.rollno;
    }
    void display(){
        cout << "The name of the student is " << name << " and roll no. is " << rollno << endl ;
    }
    



   
};
int main(){
    Student s1("Anjali", 20);
    s1.display();
    Student s2(s1);
    s2.display();
    

    


    

}