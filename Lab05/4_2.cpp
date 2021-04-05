#include<iostream>
using namespace std;

int main() {
	int num;
	do {
		cout << "Enter the number (0, 10]: ";
		cin >> num;
	} while (num > 10 || num <= 0);
	cout << "Success!" << endl;
	return 0;
}
