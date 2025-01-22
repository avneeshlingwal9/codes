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
class A : private first{

};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    A a ;
    a.publicdisp();
}