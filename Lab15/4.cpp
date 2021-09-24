#include <iostream>
#include <cmath>
using namespace std;

class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point; mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter: empty" << endl;; }
	virtual void calcArea() { cout << "Area: empty" << endl; }
protected:
	int mPoint; // 꼭지점의 갯수
	double mLength; // 한 변의 길이
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override {
		double perimeter = mLength * 4;
		cout << "Perimeter: " << perimeter << endl;
	}
	void calcArea() override {
		double area = mLength * mLength;
		cout << "Area: " << area << endl;
	}
};

class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(int point, float length) : Polygon(point, length) {}
	~Triangle() {}
	void calcPerimeter() override {
		double perimeter = mLength * 3;
		cout << "Perimeter: " << perimeter << endl;
	}
	void calcArea() override {
		double area = mLength * mLength * (sqrt(3)/2) / 2;
		cout << "Area: " << area << endl;
	}
};

class Circle : public Polygon {
public:
	Circle() {}
	Circle(int point, float length) : Polygon(point, length) {}
	~Circle() {}
	void calcPerimeter() override {
		double perimeter = 2 * 3.14 * mLength;
		cout << "Perimeter: " << perimeter << endl;
	}
	void calcArea() override {
		double area = 3.14 * mLength * mLength;
		cout << "Area: " << area << endl;
	}
};

int main() {
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}
