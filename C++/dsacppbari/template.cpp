#include <iostream>
using namespace std;
template <class T>
class Num {
    public :
        T a;
        T b;
        Num();
        T add();
        T sub();
};
template <class T> 
Num<T>::Num(){
    cout << "Enter two numbers : " << endl;
    cin >> a >> b;
}
template <class T> 
T Num<T>::add(){
    T c;
    c = a + b;
    return c; 
} 
template <class T>
T Num<T>::sub(){
    T c;
    c = a - b;
    return c; 
}
template <class T> 
T multiply( T a , T b ){
    T c;
    c = a * b;
    return c; 
}
int main(){
    Num<int> n ;

    cout << "Sum " << n.add() << endl;
    cout << "Sub " << n.sub() << endl;
    cout << "Multiply " << multiply<int>(n.a,n.b) << endl; 
    Num<float> f;
    cout << "Float sum " << f.add() << endl;
    cout << "Float sub " << f.sub() << endl;
    cout << "Multiply " << multiply<float>(f.a, f.b) << endl; 
}