#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum Color { RED, BLUE, YELLOW };
class Point {
	int x;
	int y;
public:
	Point(const int& x_ = 0, const int& y_ = 0) {
		this->x = x_;
		this->y = y_;
	}
	int getx() { return x; }
	int gety() { return y; }
};

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class ClosedShape : public Shape {

public:
	virtual float getArea() const = 0;

};

class ClosedShapeList {
    vector <ClosedShape*> shapes;
    ClosedShape* shapeclone;
public:
    void addShape(ClosedShape* const shape) {
        shapeclone = static_cast<ClosedShape*>(shape->clone()) ;
        shapes.push_back(shapeclone);
    }
    float getTotalArea() const {
        auto totalArea = 0.0F;
        for (const auto shape : shapes)
            totalArea += shape->getArea();
        return totalArea;
    }
    virtual void print() const {
        for (const auto shape : shapes) {
            shape->print();
        }
    }
};


class Polygon : public ClosedShape {
public:

};

class Triangle : public Polygon {
    Point* tri;
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3) : tri(new Point[3]) {
        tri[0] = p1;
        tri[1] = p2;
        tri[2] = p3;
    }
    virtual void print() const {
        cout << "Triangle : ";
        for (int i = 0; i < 2; i++) {
            cout << "(" << tri[i].getx() << ", " << tri[i].gety() << ")";
        };
        cout << endl;
    }
    virtual float getArea() const {
        return (tri[1].gety() - tri[0].gety()) * (tri[2].getx() - tri[0].getx()) / 2;
    }
    virtual float getLength() const {
        float temp = 0.0F;
        float totallen = 0.0F;
        for (int i = 0; i < 3; i++) {
            if (i == 2) {
                temp = (tri[i].getx() - tri[i - 2].getx()) ^ 2 + (tri[i].gety() - tri[i - 2].gety()) ^ 2;
            }
            else {
                temp = (tri[i].getx() - tri[i + 1].getx()) ^ 2 + (tri[i].gety() - tri[i + 1].gety()) ^ 2;
            }
            totallen += sqrt(temp);
        }
        return totallen;
    }
    virtual Triangle* clone() const {
        return new Triangle(*this);
    }
};

class Rectangle : public Polygon {
    Point* rec;
public:
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : rec(new Point[4]) {
        rec[0] = p1;
        rec[1] = p2;
        rec[2] = p3;
        rec[3] = p4;
    }
    virtual void print() const {
        cout << "Rectangle: ";
        for (int i = 0; i < 4; i++) {
            cout << "(" << rec[i].getx() << ", " << rec[i].gety() << ")";
        }
        cout << endl;
    }
    virtual float getArea() const {
        return (rec[1].gety() - rec[0].gety()) * (rec[2].getx() - rec[0].getx());
    }
    virtual float getLength() const {
        float temp = 0.0F;
        float totallen = 0.0F;
        for (int i = 0; i < 3; i++) {
            if (i == 3) {
                temp = (rec[i].getx() - rec[i - 3].getx()) ^ 2 + (rec[i].gety() - rec[i - 3].gety()) ^ 2;
            }
            else {
                temp = (rec[i].getx() - rec[i + 1].getx()) ^ 2 + (rec[i].gety() - rec[i + 1].gety()) ^ 2;
            }
            totallen += sqrt(temp);
        }
        return totallen;
    }
    virtual Rectangle* clone() const {
        return new Rectangle(*this);
    }
};
int main() {
    Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30) ;

    ClosedShape* const r = new Rectangle(p1, p2, p3, p4) ;
    ClosedShape* const t = new Triangle(p1, p2, p3) ;

    ClosedShapeList list{} ;
    list.addShape(r) ;
    list.addShape(t) ;
    delete r;
    delete t;

    list.print() ;
    cout << list.getTotalArea() << endl ;
}