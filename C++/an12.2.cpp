#include <iostream>
using namespace std ;
class first{
    private:
    int a = 10 ;
    void privdisplay(){
        cout << "This is private function and variable  a " << a << endl ;
    }
    public :
    int b = 20 ;
    void publicdisp(){
        cout << "This is public function and variable b " << b << endl ;
    }
    protected :
    int c = 30 ;
    void protdisp(){
        cout << "This is protected function and variable c " << c << endl ;
    }
};
class A : protected first{
    public :
    void protectedaccess(){
        cout << "Protected variable is " << b << endl ; 
    }

};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    A a ;
    cout << "Protected mode of inheritance " << endl ;
    a.protectedaccess();
}