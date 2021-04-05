#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main() {
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	
	cout << "gcd(" << x << "," << y << ")" << " = " << gcd(x, y);
	return 0;
}
