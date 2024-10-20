#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Drawing a generic shape" << endl;
    }

    virtual void erase() const {
        cout << "Erasing a generic shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a circle" << endl;
    }

    void erase() const override {
        cout << "Erasing a circle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a triangle" << endl;
    }

    void erase() const override {
        cout << "Erasing a triangle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a square" << endl;
    }

    void erase() const override {
        cout << "Erasing a square" << endl;
    }
};

int main() {
    Circle circle;
    Triangle triangle;
    Square square;

    Shape* shapes[] = {&circle, &triangle, &square};

    for (const auto& shape : shapes) {
        shape->draw();
        shape->erase();
        cout << endl;
    }

    return 0;
}
