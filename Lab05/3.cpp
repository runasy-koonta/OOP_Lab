#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int column = 1, row = 1;
	while (row <= 10) {
		while (column <= 10) {
			int num = 0;
			if (row == column){
				num = 1;
			}
			cout << setw(4) << num;
			column++;
		}
		cout << endl;
		row++;
		column = 1;
	}
	return 0;
}
