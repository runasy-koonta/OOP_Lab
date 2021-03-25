#include <iostream>
#include <cmath>

using namespace std;

void swap_call_by_value(int x, int y);
void swap_call_by_reference(int &x, int &y);
void get_data(int &x, int &y);

int main() {
	int x, y;
	
	get_data(x, y);
	
	// swap_call_by_value
	cout << "swap_call_by_value 함수 사용 전" << endl;
	cout << "x = " << x << ", y = " << y << endl;
	
	cout << endl;
	swap_call_by_value(x, y);
	
	cout << "swap_call_by_value 함수 사용 후" << endl;
	cout << "x = " << x << ", y = " << y << endl;
	
	
	cout << endl << endl;
	
	// swap_call_by_reference
	cout << "swap_call_by_reference 함수 사용 전" << endl;
	cout << "x = " << x << ", y = " << y << endl;
	
	cout << endl;
	swap_call_by_reference(x, y);
	
	cout << "swap_call_by_reference 함수 사용 후" << endl;
	cout << "x = " << x << ", y = " << y << endl;
}

void swap_call_by_value(int x, int y) {
	int temp;
	temp = y;
	y = x;
	x = temp;
}
void swap_call_by_reference(int &x, int &y) {
	int temp;
	temp = y;
	y = x;
	x = temp;
}
void get_data(int &x, int &y) {
	cout << "x 입력 : ";
	cin >> x;
	cout << "y 입력 : ";
	cin >> y;
}