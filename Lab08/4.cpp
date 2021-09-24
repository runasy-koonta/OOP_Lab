#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	ofstream fout("4_output.txt");
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fout << rand() % 100 << " ";
		}
		fout << endl;
	}
	
	return 0;
}