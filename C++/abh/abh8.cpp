#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void sound() const {
        cout << "Generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() const override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        cout << "Cat meows" << endl;
    }
};

class Bird : public Animal {
public:
    void sound() const override {
        cout << "Bird chirps" << endl;
    }
};

int main() {
    cout << "Name:- Anushka Negi "<< endl ;
    cout << "Section:- G1 " << endl ;
    cout << "Roll No.:- 11" << endl ;
    cout << "Demonstration of virtual functions " << endl ;

    

    Dog d ;
    Cat cat;
    Bird bird;
    d.sound();
    cat.sound();
    bird.sound();




    return 0;
}
