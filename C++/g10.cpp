#include <iostream>
#include <cmath>
using namespace std ;
double Area( double side ){
    double area = side*side ;
    return area ; 
}
double Area ( double breadth , double length){
    double  area = breadth*length ; 
    return area ; 
}
double Area( double side1 , double side2 , double side3){
    double s = (side1 + side2 + side3 )/2;
    double area = pow((s*(s-side1)*(s-side2)*(s-side3)),0.5) ; 
    return area ; 
}
int main(){
    string shape ;
    cout << "Enter the name of the shape : - "  << endl ; 
    cin >> shape ; 
    if ( shape == "Square"){
        double side ; 
        cout << "Enter the length of the side : - "<< endl ;
        cin >> side ; 
        cout << "The area of the square is : - " << Area(side) << endl ;
    }
    else if ( shape == "Rectangle"){
        double length , breadth ;
        cout << "Enter the length and breadth of the rectangle : - " << endl ;
        cin >> length >> breadth ; 
        cout << "The area of the rectangle is : - " << Area( length , breadth) << endl ;

    }
    else if ( shape == "Triangle"){
        double side1,side2,side3 ; 
        cout << "Enter the side of the triangle : - " << endl ; 
        cin >> side1 >> side2 >> side3 ;
        cout << "The area of the triangle is : - " << Area( side1 ,side2 , side3) << endl ; 
    }
    return 0 ;
}