#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	cout << "number : ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0 && i % 3 != 0) {
			sum += i;
		}
	}
	cout << "sum : " << sum << endl;
	return 0;
}
