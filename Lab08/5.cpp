#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
	ifstream fin("5_input");
	ofstream fout("5_output.txt");
	
	char c;
	int i = 0, n;
	
	cout << "length = ";
	cin >> n;
	
	while (fin.get(c)) {
		i++;
		if (c == '\n') {
			fout << " ";
			continue;
		}
		fout << c;
		if (i >= n) {
			i = 0;
			fout << endl;
		}
	}
	
	return 0;
}