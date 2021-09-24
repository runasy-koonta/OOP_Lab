#include <iostream>
using namespace std;

int main() {
	int a[5][10];
	
	int (*p)[10] = a;
	p += 3;
	int *q = *p;
	q += 4;
	*q = 5;
	
	cout << a[3][4];
	return 0;
}