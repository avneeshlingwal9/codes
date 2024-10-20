#include <iostream>
using namespace std ; 

class Point{
    int x , y ;
    public : 
    Point( int a , int b){
        x = a ; 
        y = b;
    }
    void addPoint(Point p, Point q){
        x = p.x + q.x;
        y = p.y + q.y;
    }
    void showPoint(){
        cout << x << " " << y << endl ; 
    }
};
int main(){
    int m ,n ,p , q ; 
    cout << "Enter the coordinates : - "<< endl ; 
    cin >> m  >> n ; 


    Point a(m,n);
    cout << "Enter the coordinates : - " << endl ; 
    cin >> p >> q ; 
    Point b(p,q);
    a.showPoint();
    a.addPoint(a,b);
    a.showPoint();
    Point c(a);
    cout << "Coordinates for a + b is :  " ;
    c.showPoint(); 



}