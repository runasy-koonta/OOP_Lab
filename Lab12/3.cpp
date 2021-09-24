#include <iostream>
using namespace std;

int main() {
	int n;
	do {
		cout << "Please enter a number: ";
		cin >> n;
		if (n < 2) {
			cout << "Wrong number!!!";
			break;
		}
		cout << "Size of random array: " << n / 2;
		
		int* arr = new int[n / 2];
		for (int i = 0; i < (n / 2); i++) {
			arr[i] = (rand() % n) + 1;
		}
		
		bool is_duplicated = false;
		for (int i = 0; i < (n / 2); i++) {
			for (int j = i; j < (n / 2); j++) {
				if (i == j) {
					continue;
				}
				if (arr[i] == arr[j]) {
					is_duplicated = true;
					break;
				}
			}
			if (is_duplicated) {
				break;
			}
		}
		
		cout << endl << "[ Array ]" << endl;
		for (int i = 0; i < (n / 2); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		if (is_duplicated) {
			cout << "Duplicates found." << endl << endl;
		} else {
			cout << "Duplicates not found." << endl << endl;
		}
	} while (true);
	return 0;
}
