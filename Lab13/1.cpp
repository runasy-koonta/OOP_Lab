#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	int x;
	int y;

public: // class 안/밖에서 사용가능

	// Point() {}
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}

	void print() {
		cout << x << ", " << y << endl;
	}
};

int main() {
	Point pt1(1, 2), pt2(3, 4);
	pt1.setXY(10, 20);
	pt1.print();
	pt2.print();

	cout << pt1.getX() << endl;
	cout << pt2.getY() << endl;
	return 0;
}
