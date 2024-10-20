#include <iostream>

class Shape {
public:
    void print() const {
        std::cout << "This is a shape" << std::endl;
    }
};

class Polygon : public Shape {
public:
    void print() const {
        std::cout << "Polygon is a shape" << std::endl;
    }
};

class Rectangle : public Polygon {
public:
    void print() const {
        std::cout << "Rectangle is a polygon" << std::endl;
    }
};

class Triangle : public Polygon {
public:
    void print() const {
        std::cout << "Triangle is a polygon" << std::endl;
    }
};

class Square : public Rectangle {
public:
    // The print function is inherited from Rectangle, but can be overridden if needed.
};

int main() {
    Shape shapeObj;
    Polygon polygonObj;
    Rectangle rectangleObj;
    Triangle triangleObj;
    Square squareObj;

    std::cout << "Calling function using objects:\n";
    shapeObj.print();
    polygonObj.print();
    rectangleObj.print();
    triangleObj.print();
    squareObj.print();

    return 0;
}
