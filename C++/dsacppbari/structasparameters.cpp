#include <iostream>
using namespace std; 
struct Rectangle{
    int length;
    int breadth; 
};
struct test {
    int A[5]; 
};
int area(struct Rectangle r){
    return r.breadth * r.length;
}
int areaa(struct Rectangle &r){
    r.length++;
    r.breadth++;
    return r.length * r.breadth;
}
void changelength(struct Rectangle* r , int l ){
    r->length = l;
}
void initial(struct test t){
    t.A[0] = 1;
    t.A[1]= 2 ;
    t.A[2] = 3;
    t.A[3] = 4;
    t.A[4] = 5;
}
void pr(struct test* t){
    for(int i : t->A){
        cout << i << endl; 
    }
}
int main(){
    Rectangle r = {10, 5};
    test t; 
    cout << "Area using call by value " << area(r) << endl;
    
    cout << "Area using call by reference " << areaa(r) << endl;
    changelength(&r, 20);
    cout << "Updation using call by address" << r.length << endl;
    initial(t);
    pr(&t);
        }