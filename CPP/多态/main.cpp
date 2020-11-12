#include <bits/stdc++.h>
using namespace std;

// 静态多态
namespace STATIC_POLYMORPHISM {
    class A {
    public:
        A() {
            cout << "A 被创建了" << endl;
        }
        ~A() {
            cout << "A 被销毁了~" << endl;
        }
        int add(int a) {
            return a;
        }
        int add(int a, int b) {
            return a + b;
        }
        int add() {
            return 0;
        }
        template <class T, class... Ts> 
        int add(const T& a, const Ts& ...rest) {
            return a + add(rest...);
        }
    };
    void main() {
        A* a = new A();
        cout << a->add(1) << endl;
        cout << a->add(1, 2) << endl;
        cout << a->add(1, 2, 3) << endl;
        cout << a->add(1, 2, 3, 4) << endl;
        delete a;
        a = nullptr;
    }
}

namespace DYNAMIC_POLYMORPHISM {
    // 形状类
    class Shape {
    public:
        virtual double calcArea() = 0;
        virtual ~Shape() {
            cout << "Shape 被销毁了~" << endl;
        }
    };

    // 圆形类
    class Circle : public Shape {
        constexpr static double PI = acos(-1.0);
        double r;
    public:
        Circle(double r) {
            this->r = r;
        }
        virtual double calcArea() {
            return PI * r * r;
        };
        virtual ~Circle() {
            cout << "Circle 被销毁了~" << endl;
        }
    };

    // 矩形类
    class Rect : public Shape {
        double w, h;
    public:
        Rect(double w, double h) {
            this->w = w;
            this->h = h;
        }
        virtual double calcArea() {
            return w * h;
        };
        virtual ~Rect() {
            cout << "Rect 被销毁了~" << endl;
        }
    };

    void outCalc(Shape* shape) {
        cout << shape->calcArea() << endl;
        delete shape;
        shape = nullptr;
    }

    void main() {
        Shape* shape1 = new Circle(4.0);
        Shape* shape2 = new Rect(5.0, 6.0);
        outCalc(shape1);
        outCalc(shape2);
    }
}

int main() {
    STATIC_POLYMORPHISM::main();
    DYNAMIC_POLYMORPHISM::main();
}