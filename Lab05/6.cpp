#include <iostream>
using namespace std;

int main() {
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;
	switch (key) {
		case 'p':
		case 'P':
			cout << "Pause";
			break;
		case 'q':
		case 'Q':
			cout << "Quit";
			break;
		default:
			cout << "Default";
	}
	cout << endl;
	return 0;
}
