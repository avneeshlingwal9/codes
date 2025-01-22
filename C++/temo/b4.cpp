#include <iostream>
using namespace std ;
class Student{
    private :
    string name ;
    int age ;
    char section ;
    public :
    Student(string n , int a , char s){
        name = n ; 
        age = a ;
        section = s ;
    }
    Student operator -( const Student &s){
        Student s3("", age - s.age , section );
        return s3 ;
    }





}
;
int main(){
    Student s1("An",19,'a');
    Student s2("dv",14,'e');
    Student s3  = s1-s2 ;

}