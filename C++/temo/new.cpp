#include <iostream> 
#include<conio.h>  
class complex  
{  
 float x;  
 float y;  
public:  
 void input(float real, float img)  
 {  
 x=real;  
 y=img;  
 }  
 friend complex sum(complex, complex);  
 void show(complex){
    cout << c.x << "+j " << c.y << "\n";
 } 
};  
complex sum(complex c1, complex c2)  
{  
 complex c3;  
 c3.x = c1.x + c2.x;  
 c3.y = c1.y + c2.y;  
 return (c3);  
}  

int main()  
{  
 complex A,B,C;  
 A.input(3.1, 5.65);  
 B.input(2.75, 1.2);  
 C=sum(A,B);  
 cout<<"A=";  
 A.show(A);  
 cout<<"B=";  
 B.show(B);  
 cout<<"C=";  
 C.show(C);  
  
 return 0;}