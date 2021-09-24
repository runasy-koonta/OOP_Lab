#include <iostream>
using namespace std;

class Complex {
	double re, im;
public:
	Complex(double r, double i) {
		re = r; im = i;
	}

	Complex() { re = 0; im = 0; }

	Complex operator+(Complex &other) {
		return Complex(re + other.re, im + other.im);
	}
	Complex operator-(Complex &other) {
		return Complex(re - other.re, im - other.im);
	}
	Complex operator+(double re) {
		return Complex(this->re + re, im);
	}
	Complex operator-(double re) {
		return Complex(this->re - re, im);
	}

	void print() {
		cout << re << " + i" << im <<endl;
	}
};

 

int main() {
   Complex a(.3, 8.4), b(4.5, 5.2), c(2.0, 7.7);
   Complex sum, dif;
   sum = a + b + 3.0; // 중요 : "3.0"과 정확히 동일하게 기입하여야 함
   cout << "a + b + 3.0 = ";
   sum.print();

   dif = a - b - 2.0; // 중요 : "2.0"과 정확히 동일하게 기입하여야 함
   cout << "a - b - 2.0 = ";
   dif.print();

   sum = a + b + 5 - c - 8; // 중요 : "5 - 8"과 정확히 동일하게 기입하여야 함
   cout << "a + b + 5 - c - 8 = ";
   sum.print();

   return 0;
}