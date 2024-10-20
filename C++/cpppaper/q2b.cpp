#include <iostream>
using namespace std ;
class Anything{
    public :
    int num ;
    Anything(){
        num = 0 ; 
    }
    Anything(int n){
        num = n ;
    }
    friend Anything operator > (const Anything& a , const Anything& b); // Operator overloading using friend function
    void display(){
        cout << "Answer of using function is: " << num << endl; 
    }

};
Anything operator > (const Anything& a , const Anything& b){
    Anything c ;
    if(a.num > b.num){
        c.num = a.num ;
    } 
    else {
        c.num = b.num ;
    }
    return c ;
}
int main(){
    Anything a(4);
    Anything b(5);
    Anything c = a > b;
    c.display();


}