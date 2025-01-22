#include <iostream>
using namespace std ;
class Employee{
    private :
    int pan ;
    string name ;
    double tax ;
    double taxincome ;
    public :
    Employee(){
        inputInfo();

    }
    void inputInfo(){
        cout << "Enter the name of the person : -" << endl ;
        getline(cin,name);
        cout << "Enter the pan number : -"<< endl ;
        cin>> pan ;
        cin.ignore();
        cout << "Enter the taxable income " << endl ;
        cin >> taxincome;
    }
    void taxCalc(){
        double a  = 0.0 ;
        if(taxincome <= 250000){
            a = 0.0 ;
        }
        else if((taxincome> 250000) && (taxincome <= 300000)){
            a = (taxincome-250000)*0.1;
        }
        else if((taxincome> 300000) && (taxincome <=400000)){
            a = (taxincome- 300000)*0.2 + 5000;
        }
        else{
            a = (taxincome - 400000)*0.3 + 25000;
        }
        tax = a ;

    }
    void displayInfo(){
        cout << "The name of the employee is " << name << " and PAN number is " << pan << " and taxable income is " << taxincome << " and tax is " << tax << endl ;

    }
};
int main(){
    Employee e ;
    e.taxCalc();
    e.displayInfo();
}