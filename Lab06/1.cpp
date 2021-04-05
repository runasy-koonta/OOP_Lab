#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 5; i++) {
		int num;
		cout << i << "번째 정수 : ";
		cin >> num;
		
		cout << num << "은(는) " << (num  % 2 == 0 ? "짝수" : "홀수") << "입니다." << endl;
	}
	return 0;
}
