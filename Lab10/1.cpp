#include<iostream>
#include<vector>
using namespace std;

void pow(int* n) {
	*n = *n * *n;
}

int main() {
	int input;
	cout << "input> ";
	cin >> input;
	
	pow(&input);
	
	cout << "제곱값> " << input;
	
	return 0;
}
