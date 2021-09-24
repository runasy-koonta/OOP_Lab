#include <iostream>
#include <vector>
using namespace std;

void vector_reverse(vector<int>& vec) {
	for (int i = vec.size() - 1; i >= 0; i--) {
		vec.push_back(vec.at(i));
		vec.erase(vec.begin() + i);
	}
}

int main() {
	vector<int> vec;
	for (int i = 1; i <= 10; i++) {
		vec.push_back(i);
	}
	
	cout << "기본 Vector 값:" << endl;
	for (int &i: vec) {
		cout << " " << i;
	}
	
	vector_reverse(vec);
	cout << endl << "함수 실행 후 Vector 값:" << endl;
	for (int &i: vec) {
		cout << " " << i;
	}
	return 0;
}