#include <iostream>

using namespace std;
class Student{
    private:
    string name ;
    int age ;
    string address ;
    public : 
    Student(){
        name ="unknown";
        age = 0 ;
        address = "not available";
    }
    void setInfo(string aname , int aage){
        name = aname ;
        age = aage ;
        
    }
    void setInfo(string aname , int aage , string aaddress){
        name = aname ;
        age = aage ;
        address = aaddress ;
    }
    void displaydata(){
        cout << "The name of the student is " << name << " age is " << age <<" and address is " << address << endl ;
    }
    ~Student(){
        cout << "Destructor executed" << endl ;
    }
};
int main(){
    Student arr[10] ; 
    for(int i = 0 ; i < 10 ; i++){
        arr[i].setInfo("Hehe",19,"New York");
        arr[i].displaydata();

    }

}