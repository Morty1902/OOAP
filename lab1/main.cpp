#include <iostream>
#include <windows.h>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "Об'єкт створено" << endl;
    }
    virtual ~Shape() {}

    virtual double area() const = 0;

    void printArea() const {
        cout << "Площа = " << area() << endl;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {
        cout << "Площа квадрата = " << area() << endl; 
    }
    double area() const override { return side * side; }
};

class Rect : public Shape {
    double width, height;
public:
    Rect(double w, double h) : width(w), height(h) {
        cout << "Площа прямокутника = " << area() << endl;
    }
    double area() const override { return width * height; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        cout << "Площа круга = " << area() << endl;
    }
    double area() const override { return 3.14159 * radius * radius; }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Shape* shapes[] = { new Square(4), new Rect(3, 5), new Circle(2.5) };
    for (Shape* s : shapes) {
        s->printArea();
        delete s;
    }
    return 0;
}