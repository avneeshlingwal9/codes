#include <iostream>
using namespace std ;
class Student{
    private :
    string name ;
    int rollno;
    string address ;
    string branch ;
    string university ;
    public :
    Student(){
        cout << "Enter the name :- "<< endl ; 
        getline(cin,name);
        cout << "Enter the roll no. " << endl ;
        cin >> rollno ;
        cout << "Enter the address : - "<< endl ; 
        getline(cin, address);
        cout << "Enter the branch : - "<< endl ;
        getline(cin,branch);
        cout << "Enter the university : - " << endl ;
        getline(cin , university);
    }
    void setname(){
        cout << "Enter the name :- "<< endl ; 
        getline(cin,name);

    }
    void setroll(){
        cout << "Enter the roll no : - "<< endl ;
        cin >> rollno;
        cin.ignore();
    }
    void setadress(){
        cout << "Enter the address :- "<< endl ;
        getline(cin , address);
    }
    void setbranch(){
        cout << "Enter the branch : - "<< endl ;
        getline(cin , branch);
    }
    void setuniversity(){
        cout << "Enter the university name : - " << endl ;
        getline(cin, university);
    }
    string getname(){
        return name ;
    }
    int getroll(){
        return rollno;
    }
    string getadress(){
        return address;
    }
    string getbranch(){
        return branch;
    }
    string getuniversity(){
        return university;
    }
    void displayname(){
        cout << "Your name is " << name << endl ;
    }
    void displayroll(){
        cout << "Your roll no. is " << rollno << endl ;
    }
    void displayadress(){
        cout << "Your address is " << address << endl ;

    }
    void displaybranch(){
        cout << "Your branch is " << branch << endl ;
    }
    void displayuniversity(){
        cout << "Your university is : - " << university << endl ;

    }

};
int main(){
    Student s1 ;
    s1.setname();
    s1.setadress();
    s1.setroll();

    s1.setbranch();
     s1.setuniversity();
    s1.displayname();
    s1.displayroll();
    s1.displaybranch();
    s1.displayadress();
    s1.displayuniversity();
    Student s2 ;

}
