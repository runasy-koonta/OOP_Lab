#include <iostream>
using namespace std;

int main() {
	int n;
	
	while (true) {
		cout << "단 수를 입력하세요: ";
		cin >> n;
		
		if (n == -1) {
			break;
		} else if (n < 0 || n > 9) {
			cout << "1부터 9까지의 정수를 입력해주세요." << endl;
			continue;
		}
		
		for (int i = 1; i <= 9; i++) {
			cout << n << "*" << i << " = " << n * i << endl;
		}
	}
	cout << "종료합니다.";
	return 0;
}
