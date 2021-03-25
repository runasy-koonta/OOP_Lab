#include <iostream>

using namespace std;

int square(int n);

int main() {
	int x;
	x = 5;
	cout << square(x) << endl;
}

int square(int n) {
	return n * n;
}