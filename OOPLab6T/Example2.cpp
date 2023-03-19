#include <iostream>
using namespace std;
namespace SpaceExample2 {
    using namespace std;
#include <iostream>
#include <math.h>
    const float M_PI = 3.14159265358979323846;

    using namespace std;

    class Shape {
    public:
        virtual double perimeter() = 0;
    };

    class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double perimeter() override {
            return 2 * (width + height);
        }
    };

    class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        double perimeter() override {
            return 2 * M_PI * radius;
        }
    };

    class RightTriangle : public Shape {
    private:
        double a;
        double b;
        double c;
    public:
        RightTriangle(double side1, double side2) : a(side1), b(side2) {
            c = sqrt(a * a + b * b);
        }
        double perimeter() override {
            return a + b + c;
        }
    };

    class Trapezium : public Shape {
    private:
        double a;
        double b;
        double c;
        double d;
    public:
        Trapezium(double side1, double side2, double side3, double side4) : a(side1), b(side2), c(side3), d(side4) {}
        double perimeter() override {
            return a + b + c + d;
        }
    };

    int main() {
        Rectangle r(3.0, 4.0);
        Circle c(2.5);
        RightTriangle t(3.0, 4.0);
        Trapezium z(1.0, 2.0, 3.0, 4.0);

        cout << "Perimeter of Rectangle: " << r.perimeter() << endl;
        cout << "Perimeter of Circle: " << c.perimeter() << endl;
        cout << "Perimeter of Right Triangle: " << t.perimeter() << endl;
        cout << "Perimeter of Trapezium: " << z.perimeter() << endl;

        return 0;
    }
}
