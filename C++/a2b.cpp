#include <iostream>
using namespace std ;
class Person{
    private : 
    string name ; 
    double units;
    double cost  ;
    public :
    Person(string aname , double aunits){
        name = aname ;
        units = aunits;
    }
    Person(){
        cout << "Enter the name:- "<< endl ;
        getline(cin,name);
        cout << "Enter the units : - "<< endl ; 
        cin >> units ;
    }
    void calculate(){
        if(units <=100){
            cost = (units*0.6);
        }
        else if((100< units)&&(units<= 300)){
            cost = ((100*0.6) + (units-100)*0.8 );

        }
        else {
            cost = ((100*0.6) + (200*0.8) + (units-300)*0.9);

        }
        if(cost < 50){
            cost = 50.0 ;
        }
        else if(cost > 300){
            cost = cost + (cost*15)/100;
        }
        }

        

    

    void display(){
        cout << "The total charge of " << name << " is " << cost << endl ;



    }
};
int main(){
Person p("loki", 250);
Person k("sylvie",325);
Person j("thor",25);
p.calculate();
p.display();
k.display();
j.display(); 
}